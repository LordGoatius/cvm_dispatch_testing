#pragma once

#include "types.h"

#define INSTR(opv, rdv, r1v, immv) { \
   .op = opv, \
   .rd = rdv, \
   .r1 = r1v, \
   .imm = immv, \
} \

#define INSTR_SIZE 256

typedef enum op {
    HALT = 0b0000,
    ADD  = 0b0001,
    SUB  = 0b0010,
    MUL  = 0b0011,
    DIV  = 0b0100,
    BGT  = 0b0101,
    BLEQ = 0b0110,
} op;

typedef struct instr {
    op  op:  4;
    reg rd:  4;
    reg r1:  4;
    u16 imm: 4;
} __attribute__((packed, aligned(2))) instr ;

typedef struct machine {
    u16    regs[16];
    instr  instrs[INSTR_SIZE];
    int ip;
} machine;

static instr instrs[INSTR_SIZE] = {
    INSTR(ADD, 1, 1, 1),
    INSTR(ADD, 2, 2, 6),
    INSTR(ADD, 3, 3, 1),
    INSTR(ADD, 4, 4, 0),
    INSTR(BLEQ, 2, 1, 8),
    INSTR(MUL, 3, 2, 0),
    INSTR(SUB, 2, 1, 0),
    INSTR(BLEQ, 4, 4, 4),
    INSTR(HALT, 0, 0, 0),
    // Zero Initalizes at HALT, which is 0
};

void run(machine *machine);
