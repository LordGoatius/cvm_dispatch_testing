#include "machine.h"

#include <stdbool.h>
#include <stddef.h>

void run(machine *machine) {
    while (true) {
        instr instr = machine->instrs[machine->ip];
        reg rd = instr.rd;
        reg r1 = instr.r1;
        u16 rdv = machine->regs[rd];
        u16 r1v = machine->regs[r1];
        u16 imm = instr.imm;
        switch (instr.op) {
            case HALT:
                return;
            case ADD:
                machine->regs[rd] = rdv + (r1v + imm);
                machine->ip++;
            break;
            case SUB:
                machine->regs[rd] = rdv - (r1v + imm);
                machine->ip++;
            break;
            case MUL:
                machine->regs[rd] = rdv * (r1v + imm);
                machine->ip++;
            break;
            case DIV:
                machine->regs[rd] = rdv / (r1v + imm);
                machine->ip++;
            break;
            case BGT:
                if (rdv > r1v) {
                    machine->ip = imm;
                } else {
                    machine->ip++;
                }
            break;
            case BLEQ:
                if (rdv <= r1v) {
                    machine->ip = imm;
                } else {
                    machine->ip++;
                }
            break;
        }
    }
}


