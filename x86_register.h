/*
 *
 * Written by Dennis Yurichev <dennis(a)yurichev.com>, 2013
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/.
 *
 */

#pragma once

//#include <windows.h>
#include "lisp.h"

#ifdef  __cplusplus
extern "C" {
#endif

enum X86_register
{
    R_ABSENT=0, // should always be zero!
    
    R_AH,
    R_AL,
    R_AX,
    R_BH,
    R_BL,
    R_BP,
    R_BX,
    R_CH,
    R_CL,
    R_CS,
    R_CX,
    R_DH,
    R_DI,
    R_DL,
    R_DS,
    R_DX,
    R_EAX,
    R_EBX,
    R_ECX,
    R_EDX,
    R_ESI,
    R_EDI,
    R_EBP,
    R_ESP,
    R_EIP,
    R_ES,
    R_FS,
    R_GS,
    R_SI,
    R_SP,
    R_SS,
    R_ST0,
    R_ST1,
    R_ST2,
    R_ST3,
    R_ST4,
    R_ST5,
    R_ST6,
    R_ST7,
    R_XMM0,
    R_XMM1,
    R_XMM2,
    R_XMM3,
    R_XMM4,
    R_XMM5,
    R_XMM6,
    R_XMM7,
    R_XMM8,
    R_XMM9,
    R_XMM10,
    R_XMM11,
    R_XMM12,
    R_XMM13,
    R_XMM14,
    R_XMM15,
    R_MM0,
    R_MM1,
    R_MM2,
    R_MM3,
    R_MM4,
    R_MM5,
    R_MM6,
    R_MM7,
    R_RAX,
    R_RBX,
    R_RCX,
    R_RDX,
    R_RSI,
    R_RDI,
    R_RSP,
    R_RBP,
    R_RIP,
    R_R8,
    R_R9,
    R_R10,
    R_R11,
    R_R12,
    R_R13,
    R_R14,
    R_R15,

    R_R8D,
    R_R9D,
    R_R10D,
    R_R11D,
    R_R12D,
    R_R13D,
    R_R14D,
    R_R15D,

    R_R8W,
    R_R9W,
    R_R10W,
    R_R11W,
    R_R12W,
    R_R13W,
    R_R14W,
    R_R15W,

    R_R8L,
    R_R9L,
    R_R10L,
    R_R11L,
    R_R12L,
    R_R13L,
    R_R14L,
    R_R15L,

    R_SPL,
    R_BPL,
    R_SIL,
    R_DIL,

    R_PF,
    R_SF,
    R_AF,
    R_ZF,
    R_OF,
    R_CF,
    R_DF,
    R_TF,

    R_MAX // should be present!
};

enum X86_register X86_register_from_string (const char* s);
//bool X86_register_from_string (const char* s, X86_register *out);
bool X86_register_is_flag (enum X86_register r);
bool X86_register_is_STx (enum X86_register r);
const char* X86_register_ToString (enum X86_register r);
enum obj_type X86_register_get_type (enum X86_register r);

bool X86_register_is_ExX_ExI(enum X86_register r);
bool X86_register_is_xX_xI(enum X86_register r);
bool X86_register_is_xH(enum X86_register r);
bool X86_register_is_xL(enum X86_register r);
bool X86_register_is_segment(enum X86_register r);
bool X86_register_is_XMMx(enum X86_register r);
enum X86_register X86_register_get_32bit_part_of(enum X86_register r);
enum X86_register _32_bit_X86_register_is_part_of_64_bit_reg (enum X86_register r);

#ifdef  __cplusplus
}
#endif

/* vim: set expandtab ts=4 sw=4 : */
