#pragma once

#include "machine.h"

void dir_run(machine *machine);

void hlt(machine *machine, instr instr);
void add(machine *machine, instr instr);
void sub(machine *machine, instr instr);
void mul(machine *machine, instr instr);
void dvi(machine *machine, instr instr);
void bgt(machine *machine, instr instr);
void blq(machine *machine, instr instr);

static void (*handlers[7])(machine*, instr) = {
    hlt,
    add,
    sub,
    mul,
    dvi,
    bgt,
    blq,
};

