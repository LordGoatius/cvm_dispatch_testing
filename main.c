#include "machine.h"
#include "direct.h"
#include "types.h"

#include <x86intrin.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void run_switch(i64*, i64*);
void run_direct(i64*, i64*);
void time(void (*fn)(i64*, i64*));

int main(void) {
    printf("Switch:\n    ");
    time(run_switch);
    printf("Direct:\n    ");
    time(run_direct);
    return 0;
}

void time(void (*fn)(i64*, i64*)) {
    i64 start, end;
    fn(&start, &end);
    printf("[cycles] %ld\n", end - start);
}

void run_switch(i64 *start, i64 *end) {
    machine machine = {
        .regs = {0},
        .ip = 0,
    };
    memcpy(&machine.instrs, instrs, sizeof(instrs));
    *start = __rdtsc();
    run(&machine);
    *end   = __rdtsc();

    assert(machine.regs[3] == 720);
}

void run_direct(i64 *start, i64 *end) {
    machine machine = {
        .regs = {0},
        .ip = 0,
    };
    memcpy(&machine.instrs, instrs, sizeof(instrs));

    *start = __rdtsc();
    dir_run(&machine);
    *end   = __rdtsc();

    assert(machine.regs[3] == 720);
}
