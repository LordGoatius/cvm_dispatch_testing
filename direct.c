#include "direct.h"
#include "machine.h"

void dir_run(machine *machine) {
    instr instr = machine->instrs[0];
    handlers[instr.op](machine, instr);
}

void add(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];
    machine->regs[rd] = rdv + (r1v + imm);
    
    int ip = ++machine->ip;
    struct instr next = machine->instrs[ip];
    handlers[next.op](machine, next);
}

void sub(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];
    machine->regs[rd] = rdv - (r1v + imm);
    
    int ip = ++machine->ip;
    struct instr next = machine->instrs[ip];
    handlers[next.op](machine, next);
}

void mul(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];
    machine->regs[rd] = rdv * (r1v + imm);
    
    int ip = ++machine->ip;
    struct instr next = machine->instrs[ip];
    handlers[next.op](machine, next);
}

void dvi(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];
    machine->regs[rd] = rdv / (r1v + imm);
    
    int ip = ++machine->ip;
    struct instr next = machine->instrs[ip];
    handlers[next.op](machine, next);
}

void bgt(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];

    if (rdv > r1v)
        machine->ip = imm;
    else
        machine->ip++;

    struct instr next = machine->instrs[machine->ip];
    handlers[next.op](machine, next);
}

void blq(machine *machine, instr instr) {
    reg rd = instr.rd;
    reg r1 = instr.r1;
    reg imm = instr.imm;
    u16 rdv = machine->regs[rd];
    u16 r1v = machine->regs[r1];

    if (rdv <= r1v)
        machine->ip = imm;
    else
        machine->ip++;

    struct instr next = machine->instrs[machine->ip];
    handlers[next.op](machine, next);
}

void hlt(machine *machine, instr instr) {
    return;
}
