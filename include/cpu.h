#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct CPU {
  uint16_t accumulator;
  uint16_t base;
  uint16_t count;
  uint16_t data;
  uint16_t stack_pointer;
  uint16_t base_pointer;
  uint16_t source_index;
  uint16_t destination_index;

  uint16_t code_segment;
  uint16_t data_segment;
  uint16_t stack_segment;
  uint16_t extra_segment;

  uint16_t instruction_pointer;
  uint16_t flags;
} CPU;

typedef uint8_t Flag;
#define FLAG_CARRY (1 << 0)
#define FLAG_PARITY (1 << 2)
#define FLAG_AUXILIARY (1 << 4)
#define FLAG_ZERO (1 << 6)
#define FLAG_SIGN (1 << 7)
#define FLAG_TRAP (1 << 8)
#define FLAG_INTERRUPT (1 << 9)
#define FLAG_DIRECTION (1 << 10)
#define FLAG_OVERFLOW (1 << 11)

void cpu_reset(CPU *cpu);
void cpu_set_flag(CPU *cpu, Flag f);
void cpu_unset_flag(CPU *cpu, Flag f);

void cpu_dump_state(CPU *cpu);

#endif
