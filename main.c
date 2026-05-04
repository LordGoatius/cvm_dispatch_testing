#include "machine.h"
#include "direct.h"
#include "types.h"

#include <x86intrin.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void run_switch();
void run_direct();

int main(void) {
    run_switch();
    run_direct();
    return 0;
}

void run_switch() {
    i64 start, end;
    machine machine = {
        .regs = {0},
        .ip = 0,
    };
    memcpy(&machine.instrs, instrs, sizeof(instrs));
    start = __rdtsc();
    run(&machine);
    end   = __rdtsc();

    assert(machine.regs[3] == 720);
    printf("[switch] %hu\n", machine.regs[3]);
    printf("[switch-cycles] %ld\n", end - start);
}

void run_direct() {
    i64 start, end;
    machine machine = {
        .regs = {0},
        .ip = 0,
    };
    memcpy(&machine.instrs, instrs, sizeof(instrs));

    start = __rdtsc();
    dir_run(&machine);
    end   = __rdtsc();

    assert(machine.regs[3] == 720);
    printf("[direct] %hu\n", machine.regs[3]);
    printf("[direct-cycles] %ld\n", end - start);
}
