/*
 *
 * Written by Dennis Yurichev <dennis(a)yurichev.com>, 2013
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivs 3.0 Unported License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/3.0/.
 *
 */

#include "x86_register.h"
#include <stdint.h>
#include <stdio.h>

#include "oassert.h"
#include "ostrings.h"

bool X86_register_is_flag (enum X86_register r)
{
    switch (r)
    {
    case R_PF:
    case R_SF:
    case R_AF:
    case R_ZF:
    case R_OF:
    case R_CF:
    case R_DF:
    case R_TF:
        return true;
    default:
        return false;
    };
};

bool X86_register_is_STx (enum X86_register r)
{
    switch (r)
    {
    case R_ST0:
    case R_ST1:
    case R_ST2:
    case R_ST3:
    case R_ST4:
    case R_ST5:
    case R_ST6:
    case R_ST7:
        return true;
    default:
        return false;
    };
};

/*
bool X86_register_from_string (const char* s, X86_register *out)
{
    *out=X86_register_from_string (s);
    if (*out==R_ABSENT)
        return false;
    return true;
};
*/

enum X86_register X86_register_from_string (const char* s)
{
#if 0
    L ("%s:%d s=%s, this=0x%x\n", __FUNCTION__, __LINE__, s, this);
#endif

    enum X86_register r=R_ABSENT;

    if (strcasecmp (s, "eax")==0) r=R_EAX;
    if (strcasecmp (s, "ebx")==0) r=R_EBX;
    if (strcasecmp (s, "ecx")==0) r=R_ECX;
    if (strcasecmp (s, "edx")==0) r=R_EDX;
    if (strcasecmp (s, "esi")==0) r=R_ESI;
    if (strcasecmp (s, "edi")==0) r=R_EDI;
    if (strcasecmp (s, "ebp")==0) r=R_EBP;
    if (strcasecmp (s, "esp")==0) r=R_ESP;
    if (strcasecmp (s, "eip")==0) r=R_EIP;

    if (strcasecmp (s, "rax")==0) r=R_RAX;
    if (strcasecmp (s, "rbx")==0) r=R_RBX;
    if (strcasecmp (s, "rcx")==0) r=R_RCX;
    if (strcasecmp (s, "rdx")==0) r=R_RDX;
    if (strcasecmp (s, "rsi")==0) r=R_RSI;
    if (strcasecmp (s, "rdi")==0) r=R_RDI;
    if (strcasecmp (s, "rbp")==0) r=R_RBP;
    if (strcasecmp (s, "rsp")==0) r=R_RSP;
    if (strcasecmp (s, "rip")==0) r=R_RIP;

    if (strcasecmp (s, "r8")==0)  r=R_R8;
    if (strcasecmp (s, "r9")==0)  r=R_R9;
    if (strcasecmp (s, "r10")==0) r=R_R10;
    if (strcasecmp (s, "r11")==0) r=R_R11;
    if (strcasecmp (s, "r12")==0) r=R_R12;
    if (strcasecmp (s, "r13")==0) r=R_R13;
    if (strcasecmp (s, "r14")==0) r=R_R14;
    if (strcasecmp (s, "r15")==0) r=R_R15;

    if (strcasecmp (s, "r8w")==0)  r=R_R8W;
    if (strcasecmp (s, "r9w")==0)  r=R_R9W;
    if (strcasecmp (s, "r10w")==0) r=R_R10W;
    if (strcasecmp (s, "r11w")==0) r=R_R11W;
    if (strcasecmp (s, "r12w")==0) r=R_R12W;
    if (strcasecmp (s, "r13w")==0) r=R_R13W;
    if (strcasecmp (s, "r14w")==0) r=R_R14W;
    if (strcasecmp (s, "r15w")==0) r=R_R15W;

    if (strcasecmp (s, "r8d")==0)  r=R_R8D;
    if (strcasecmp (s, "r9d")==0)  r=R_R9D;
    if (strcasecmp (s, "r10d")==0) r=R_R10D;
    if (strcasecmp (s, "r11d")==0) r=R_R11D;
    if (strcasecmp (s, "r12d")==0) r=R_R12D;
    if (strcasecmp (s, "r13d")==0) r=R_R13D;
    if (strcasecmp (s, "r14d")==0) r=R_R14D;
    if (strcasecmp (s, "r15d")==0) r=R_R15D;

    if (strcasecmp (s, "r8l")==0)  r=R_R8L;
    if (strcasecmp (s, "r9l")==0)  r=R_R9L;
    if (strcasecmp (s, "r10l")==0) r=R_R10L;
    if (strcasecmp (s, "r11l")==0) r=R_R11L;
    if (strcasecmp (s, "r12l")==0) r=R_R12L;
    if (strcasecmp (s, "r13l")==0) r=R_R13L;
    if (strcasecmp (s, "r14l")==0) r=R_R14L;
    if (strcasecmp (s, "r15l")==0) r=R_R15L;
   
    // IDA style
    if (strcasecmp (s, "r8b")==0)  r=R_R8L;
    if (strcasecmp (s, "r9b")==0)  r=R_R9L;
    if (strcasecmp (s, "r10b")==0) r=R_R10L;
    if (strcasecmp (s, "r11b")==0) r=R_R11L;
    if (strcasecmp (s, "r12b")==0) r=R_R12L;
    if (strcasecmp (s, "r13b")==0) r=R_R13L;
    if (strcasecmp (s, "r14b")==0) r=R_R14L;
    if (strcasecmp (s, "r15b")==0) r=R_R15L;
    
    if (strcasecmp (s, "spl")==0) r=R_SPL;
    if (strcasecmp (s, "bpl")==0) r=R_BPL;
    if (strcasecmp (s, "sil")==0) r=R_SIL;
    if (strcasecmp (s, "dil")==0) r=R_DIL;

    if (strcasecmp (s, "st0")==0) r=R_ST0;
    if (strcasecmp (s, "st1")==0) r=R_ST1;
    if (strcasecmp (s, "st2")==0) r=R_ST2;
    if (strcasecmp (s, "st3")==0) r=R_ST3;
    if (strcasecmp (s, "st4")==0) r=R_ST4;
    if (strcasecmp (s, "st5")==0) r=R_ST5;
    if (strcasecmp (s, "st6")==0) r=R_ST6;
    if (strcasecmp (s, "st7")==0) r=R_ST7;

    if (strcasecmp (s, "pf")==0) r=R_PF;
    if (strcasecmp (s, "sf")==0) r=R_SF;
    if (strcasecmp (s, "af")==0) r=R_AF;
    if (strcasecmp (s, "zf")==0) r=R_ZF;
    if (strcasecmp (s, "of")==0) r=R_OF;
    if (strcasecmp (s, "cf")==0) r=R_CF;
    if (strcasecmp (s, "df")==0) r=R_DF;
    if (strcasecmp (s, "tf")==0) r=R_TF;

    if (r==R_ABSENT)
    {
        printf ("fatal error: register name %s isn't recognised\n", s);
        fatal_error();
    };

    return r;
};

const char* X86_register_ToString (enum X86_register r)
{
#if 0
    L ("%s:%d this=0x%x\n", __FUNCTION__, __LINE__, this);
#endif

    switch (r)
    {
    // FIXME: make array of strings
    case R_AL: return "AL";
    case R_BL: return "BL";
    case R_CL: return "CL";
    case R_DL: return "DL";

    case R_AH: return "AH";
    case R_BH: return "BH";
    case R_CH: return "CH";
    case R_DH: return "DH";

    case R_AX: return "AX";
    case R_BX: return "BX";
    case R_CX: return "CX";
    case R_DX: return "DX";

    case R_BP: return "BP";
    case R_DI: return "DI";
    case R_SI: return "SI";
    case R_SP: return "SP";

    case R_FS: return "FS";
    case R_GS: return "GS";
    case R_SS: return "SS";
    case R_ES: return "ES";
    case R_DS: return "DS";
    case R_CS: return "CS";

    case R_EAX: return "EAX";
    case R_EBX: return "EBX";
    case R_ECX: return "ECX";
    case R_EDI: return "EDI";
    case R_EDX: return "EDX";
    case R_ESI: return "ESI";
    case R_ESP: return "ESP";
    case R_EBP: return "EBP";
    case R_EIP: return "EIP";

    case R_RAX: return "RAX";
    case R_RBX: return "RBX";
    case R_RCX: return "RCX";
    case R_RDI: return "RDI";
    case R_RDX: return "RDX";
    case R_RSI: return "RSI";
    case R_RSP: return "RSP";
    case R_RBP: return "RBP";
    case R_RIP: return "RIP";

    case R_R8:  return "R8";
    case R_R9:  return "R9";
    case R_R10: return "R10";
    case R_R11: return "R11";
    case R_R12: return "R12";
    case R_R13: return "R13";
    case R_R14: return "R14";
    case R_R15: return "R15";

    case R_R8D:  return "R8D";
    case R_R9D:  return "R9D";
    case R_R10D: return "R10D";
    case R_R11D: return "R11D";
    case R_R12D: return "R12D";
    case R_R13D: return "R13D";
    case R_R14D: return "R14D";
    case R_R15D: return "R15D";

    case R_R8W:  return "R8W";
    case R_R9W:  return "R9W";
    case R_R10W: return "R10W";
    case R_R11W: return "R11W";
    case R_R12W: return "R12W";
    case R_R13W: return "R13W";
    case R_R14W: return "R14W";
    case R_R15W: return "R15W";

#ifdef DISASM_IDA_STYLE
    case R_R8L:  return "R8B";
    case R_R9L:  return "R9B";
    case R_R10L: return "R10B";
    case R_R11L: return "R11B";
    case R_R12L: return "R12B";
    case R_R13L: return "R13B";
    case R_R14L: return "R14B";
    case R_R15L: return "R15B";
#else
    case R_R8L:  return "R8L";
    case R_R9L:  return "R9L";
    case R_R10L: return "R10L";
    case R_R11L: return "R11L";
    case R_R12L: return "R12L";
    case R_R13L: return "R13L";
    case R_R14L: return "R14L";
    case R_R15L: return "R15L";
#endif

    case R_SPL: return "SPL";
    case R_BPL: return "BPL";
    case R_SIL: return "SIL";
    case R_DIL: return "DIL";

    case R_ST0: return "ST0";
    case R_ST1: return "ST1";
    case R_ST2: return "ST2";
    case R_ST3: return "ST3";
    case R_ST4: return "ST4";
    case R_ST5: return "ST5";
    case R_ST6: return "ST6";
    case R_ST7: return "ST7";

    case R_XMM0: return "XMM0";
    case R_XMM1: return "XMM1";
    case R_XMM2: return "XMM2";
    case R_XMM3: return "XMM3";
    case R_XMM4: return "XMM4";
    case R_XMM5: return "XMM5";
    case R_XMM6: return "XMM6";
    case R_XMM7: return "XMM7";
    case R_XMM8: return "XMM8";
    case R_XMM9: return "XMM9";
    case R_XMM10: return "XMM10";
    case R_XMM11: return "XMM11";
    case R_XMM12: return "XMM12";
    case R_XMM13: return "XMM13";
    case R_XMM14: return "XMM14";
    case R_XMM15: return "XMM15";

    case R_MM0: return "MM0";
    case R_MM1: return "MM1";
    case R_MM2: return "MM2";
    case R_MM3: return "MM3";
    case R_MM4: return "MM4";
    case R_MM5: return "MM5";
    case R_MM6: return "MM6";
    case R_MM7: return "MM7";

    case R_PF: return "PF";
    case R_SF: return "SF";
    case R_AF: return "AF";
    case R_ZF: return "ZF";
    case R_OF: return "OF";
    case R_CF: return "CF";
    case R_DF: return "DF";
    case R_TF: return "TF";

    case R_ABSENT: return "ABSENT";
    default: 
        oassert(!"unknown register");
        fatal_error();
    };
};

enum obj_type X86_register_get_type (enum X86_register r)
{
    switch (r)
    {
    case R_AL: case R_BL: case R_CL: case R_DL:
    case R_AH: case R_BH: case R_CH: case R_DH:
    case R_R8L:  case R_R9L:  case R_R10L: case R_R11L: case R_R12L: 
    case R_R13L: case R_R14L: case R_R15L: 
    case R_SPL:  case R_BPL:  case R_SIL:  case R_DIL: 
        return OBJ_BYTE;

    case R_AX: case R_BX: case R_CX: case R_DX: 
    case R_BP: case R_DI: case R_SI: case R_SP: 
    case R_FS: case R_GS: case R_SS: case R_ES: case R_DS: case R_CS: 
    case R_R8W:  case R_R9W:  case R_R10W: case R_R11W: case R_R12W: 
    case R_R13W: case R_R14W: case R_R15W: 
        return OBJ_WYDE;

    case R_EAX: case R_EBX: case R_ECX: case R_EDI: case R_EDX: case R_ESI: 
    case R_ESP: case R_EBP: case R_EIP:
    case R_R8D:  case R_R9D:  case R_R10D: case R_R11D: case R_R12D: 
    case R_R13D: case R_R14D: case R_R15D: 
        return OBJ_TETRA;

    case R_RAX: case R_RBX: case R_RCX: case R_RDI: case R_RDX: case R_RSI:
    case R_RSP: case R_RBP: case R_RIP:
    case R_R8:  case R_R9:  case R_R10: case R_R11: case R_R12:
    case R_R13: case R_R14: case R_R15:
        return OBJ_OCTA;

    case R_ST0: case R_ST1: case R_ST2: case R_ST3: 
    case R_ST4: case R_ST5: case R_ST6: case R_ST7: 
        return OBJ_DOUBLE; // not very precious, but OK.

    case R_XMM0: case R_XMM1: case R_XMM2: case R_XMM3: case R_XMM4: 
    case R_XMM5: case R_XMM6: case R_XMM7: case R_XMM8: case R_XMM9: 
    case R_XMM10: case R_XMM11: case R_XMM12: case R_XMM13: case R_XMM14: case R_XMM15:
        return OBJ_XMM;

    case R_MM0: case R_MM1: case R_MM2: case R_MM3:
    case R_MM4: case R_MM5: case R_MM6: case R_MM7:
        oassert (!"MMX registers are not handled here");
        fatal_error();

    case R_PF: case R_SF: case R_AF: case R_ZF: 
    case R_OF: case R_CF: case R_DF: case R_TF: 
        oassert (!"flag registers are not handled here");
        fatal_error();

    case R_ABSENT:
        oassert (!"R_ABSENT isn't handled here");
        fatal_error();

    default: 
        oassert(!"unknown register");
        fatal_error();
    };
};


bool X86_register_is_ExX_ExI(enum X86_register r)
{
    return (r==R_EAX || r==R_EBX || r==R_ECX || r==R_EDX || r==R_ESI || r==R_EDI || r==R_EBP || r==R_ESP);
};
bool X86_register_is_xX_xI(enum X86_register r)
{
    return (r==R_AX || r==R_BX || r==R_CX || r==R_DX || r==R_SI || r==R_DI || r==R_BP || r==R_SP);
};
bool X86_register_is_xH(enum X86_register r)
{
    return (r==R_AH || r==R_BH || r==R_CH || r==R_DH);
};
bool X86_register_is_xL(enum X86_register r)
{
    return (r==R_AL || r==R_BL || r==R_CL || r==R_DL);
};

bool X86_register_is_segment(enum X86_register r)
{
    return (r==R_CS || r==R_DS || r==R_SS || r==R_ES || r==R_FS || r==R_GS);
};

enum X86_register X86_register_get_32bit_part_of(enum X86_register r)
{
    switch (r)
    {
        case R_EAX: case R_AX: case R_AL: case R_AH: 
            return R_EAX;
        case R_EBX: case R_BX: case R_BL: case R_BH: 
            return R_EBX;
        case R_ECX: case R_CX: case R_CL: case R_CH: 
            return R_ECX;
        case R_EDX: case R_DX: case R_DL: case R_DH: 
            return R_EDX;
        case R_ESI: case R_SI: 
            return R_ESI;
        case R_EDI: case R_DI: 
            return R_EDI;
        case R_EBP: case R_BP: 
            return R_EBP;
        case R_ESP: case R_SP: 
            return R_ESP;
        default:
            oassert(0);
            fatal_error();
    };
};

bool X86_register_is_XMMx(enum X86_register r)
{
    switch (r)
    {
    case R_XMM0:
    case R_XMM1:
    case R_XMM2:
    case R_XMM3:
    case R_XMM4:
    case R_XMM5:
    case R_XMM6:
    case R_XMM7:
    case R_XMM8:
    case R_XMM9:
    case R_XMM10:
    case R_XMM11:
    case R_XMM12:
    case R_XMM13:
    case R_XMM14:
    case R_XMM15:
        return true;
    default:
        return false;
    };
};

enum X86_register _32_bit_X86_register_is_part_of_64_bit_reg (enum X86_register r)
{
    switch (r)
    {
    case R_EAX: return R_RAX;
    case R_EBX: return R_RBX;
    case R_ECX: return R_RCX;
    case R_EDX: return R_RDX;
    case R_ESI: return R_RSI;
    case R_EDI: return R_RDI;
    case R_EBP: return R_RSP;
    case R_ESP: return R_RBP;
    case R_EIP: return R_RIP;
    
    case R_R8D:  return R_R8;
    case R_R9D:  return R_R9;
    case R_R10D: return R_R10;
    case R_R11D: return R_R11;
    case R_R12D: return R_R12;
    case R_R13D: return R_R13;
    case R_R14D: return R_R14;
    case R_R15D: return R_R15;
    default: oassert(0);
    };
}

/* vim: set expandtab ts=4 sw=4 : */
