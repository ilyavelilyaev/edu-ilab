//
//  codes.h
//  Assembler
//
//  Created by Ilya Velilyaev on 20.11.14.
//  Copyright (c) 2014 Ilya Velilyaev. All rights reserved.
//

#ifndef CODES_H
#define CODES_H

enum CODES {
    NO_CODE,
    PUSH_CODE,
    PUSH_A_CODE,
    PUSH_B_CODE,
    PUSH_C_CODE,
    PUSH_D_CODE,
    POP_CODE,
    POP_A_CODE,
    POP_B_CODE,
    POP_C_CODE,
    POP_D_CODE,
    ADD_CODE,
    SUB_CODE,
    MUL_CODE,
    DIV_CODE,
    NEG_CODE,
    INC_CODE,
    DEC_CODE,
    SQRT_CODE,
    JMP_CODE,
    JEA_CODE,
    JEB_CODE,
    JEC_CODE,
    JED_CODE,
    JNEA_CODE,
    JNEB_CODE,
    JNEC_CODE,
    JNED_CODE,
    PRINT_CODE,
    CALL_CODE,
    RET_CODE,
    MARK_CODE,
    END
};


#endif
