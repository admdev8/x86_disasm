/*
 *
 * Written by Dennis Yurichev <dennis(a)yurichev.com>, 2013
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/.
 *
 */

#pragma once

#include "datatypes.h"

#include "X86_register.h"
#include "x86_disas.h"

//#pragma pack(push)
//#pragma pack(1)
struct Da_stage1
{
    bool use_callbacks:1;
    // case 1
    uint8_t* cur_ptr;
    // case 2
    callback_read_byte read_byte_fn;
    callback_read_word read_word_fn;
    callback_read_dword read_dword_fn;
    callback_read_oword read_oword_fn;
    void *callback_param;

    // case 1 and 2:
    uint8_t cur_idx;
    disas_address cur_adr;

    unsigned PREFIXES;
    unsigned ESCAPE_0F:1, ESCAPE_F2:1, ESCAPE_F3:1;
    unsigned PREFIX_66_is_present:1, PREFIX_67:1;
    enum Ins_codes ins_code;
    unsigned len;
    unsigned tbl_p;
    uint64_t new_flags; // including promoted F_IMM64, etc

    uint8_t REG_FROM_LOWEST_PART_OF_1ST_BYTE; // lowest 3 bits
    unsigned REG_FROM_LOWEST_PART_OF_1ST_BYTE_loaded:1;

    unsigned x64:1;
    unsigned REX_prefix_seen:1;
    unsigned REX_W:1, REX_R:1, REX_X:1, REX_B:1;

    // MODRM = MOD(2) | REG(3) | RM(3)
    union
    {
        struct
        {
            unsigned RM:3;
            unsigned REG:3;
            unsigned MOD:2;
        } s;
        uint8_t as_byte;
    } MODRM;
    bool MODRM_loaded;

    // SIB
    union
    {
        struct
        {
            unsigned base:3;
            unsigned index:3;
            unsigned scale:2;
        } s;
        uint8_t as_byte;
    } SIB;
    bool SIB_loaded;

    // DISP8/16/32
    int8_t DISP8; unsigned DISP8_loaded:1;
    int16_t DISP16; unsigned DISP16_loaded:1;
    int32_t DISP32; unsigned DISP32_loaded:1; disas_address DISP32_pos;

    // IMM8/16/32
    // 8 и 16 могут быть одновременно загружены, вот как при ENTER
    uint8_t IMM8;  unsigned IMM8_loaded:1;
    uint16_t IMM16; unsigned IMM16_loaded:1;
    uint32_t IMM32; unsigned IMM32_loaded:1; disas_address IMM32_pos;
    uint64_t IMM64; unsigned IMM64_loaded:1; disas_address IMM64_pos;

    uint64_t PTR; unsigned PTR_loaded; disas_address PTR_pos;
};
//#pragma pack(pop)

// "methods"
bool Da_stage1_get_next_byte(struct Da_stage1* p, uint8_t *out);
void Da_stage1_unget_byte(struct Da_stage1 *p);
bool Da_stage1_get_next_word(struct Da_stage1 *p, uint16_t *out);
bool Da_stage1_get_next_dword(struct Da_stage1 *p, uint32_t *out);
bool Da_stage1_get_next_qword (struct Da_stage1 *p, uint64_t *out);
bool Da_stage1_load_prefixes_escapes_opcode (struct Da_stage1 *p, disas_address adr_of_ins, uint8_t *out);
void Da_stage1_dump (struct Da_stage1 *p, disas_address adr, int len);
bool Da_stage1_Da_stage1 (struct Da_stage1 *p, TrueFalseUndefined x64_code, disas_address adr_of_ins);

// flags:

#define F_MODRM OCTA_1<<0
#define F_IMM8  OCTA_1<<1
#define F_IMM16 OCTA_1<<2
#define F_IMM32 OCTA_1<<3

#define F_PREFIX66_ALLOWED OCTA_1<<4
#define F_PREFIX66_IS_PART_OF_OPCODE OCTA_1<<5
#define F_PREFIX66_APPLIED_TO_OP1_ONLY OCTA_1<<6

#define F_REG32_IS_LOWEST_PART_OF_1ST_BYTE OCTA_1<<7

#define F_REG64_IS_LOWEST_PART_OF_1ST_BYTE OCTA_1<<9

// including promoting F_IMM32 to F_IMM64 ... (кажется)
#define F_REXW_PROMOTE_ALL_32_OPS_TO_64 OCTA_1<<11

#define F_X32_ONLY OCTA_1<<12
#define F_X64_ONLY OCTA_1<<13

#define F_IMM64 OCTA_1<<14

#define F_REXW_ABSENT OCTA_1<<16
#define F_REXW_PRESENT OCTA_1<<17

#define F_X64_PROMOTE_OP1_32_TO_64 OCTA_1<<18
#define F_REXW_SIGN_EXTEND_OP2_32_TO_64 OCTA_1<<19
#define F_REXW_PROMOTE_OP1_32_TO_64 OCTA_1<<20

#define F_WHEN_MOD3_TREAT_RM_AS_STx OCTA_1<<21

// 0F is part of opcode?
#define F_0F OCTA_1<<22

#define F_MODRM_REG_0 OCTA_1<<23
#define F_MODRM_REG_1 OCTA_1<<24
#define F_MODRM_REG_2 OCTA_1<<25
#define F_MODRM_REG_3 OCTA_1<<26
#define F_MODRM_REG_4 OCTA_1<<27
#define F_MODRM_REG_5 OCTA_1<<28
#define F_MODRM_REG_6 OCTA_1<<29
#define F_MODRM_REG_7 OCTA_1<<30

#define F_MODRM_RM_2  OCTA_1<<31
#define F_MODRM_RM_3  OCTA_1<<32
#define F_MODRM_RM_0  OCTA_1<<33

// F3 is part of opcode? (it was REP instruction also)
#define F_F3          OCTA_1<<34

// F2 is part of opcode? (it was REPNE instruction also)
#define F_F2          OCTA_1<<35

#define F_MODRM_MOD_IS_3     OCTA_1<<36
#define F_MODRM_MOD_IS_NOT_3 OCTA_1<<37
#define F_MODRM_RM_1         OCTA_1<<38
#define F_MODRM_RM_5         OCTA_1<<39
#define F_MODRM_RM_4       OCTA_1<<40
#define F_MODRM_RM_6       OCTA_1<<41
#define F_MODRM_RM_7       OCTA_1<<42

#define F_PTR              OCTA_1<<43
#define F_OPC2             OCTA_1<<44

// the flag is to be set in table in DEBUG build if disasm used the entry at least once
// this information will be used in print_unused_tbl_entries() while testing
#define F_HIT_DURING_EXECUTION  OCTA_1<<45

typedef bool (*c_OP_fn) (struct Da_stage1 *stage1, disas_address ins_adr, unsigned ins_len, struct Da_op *out);

struct Ins_definition
{
    uint8_t opc;
    uint8_t opc2;
    uint64_t flags;
    c_OP_fn op1; // source of first operand
    c_OP_fn op2; // second
    c_OP_fn op3; // third

    const char *name;

    enum Ins_codes ins_code;
};

//Ins_definition ins_tbl[];
//extern Ins_definition ins_tbl[];

/* vim: set expandtab ts=4 sw=4 : */
