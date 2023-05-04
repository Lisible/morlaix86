#include "cpu.h"
#include <stdio.h>

void cpu_reset(CPU *cpu) {
  cpu->code_segment = 0xffff;
  cpu->data_segment = 0x0000;
  cpu->stack_segment = 0x0000;
  cpu->extra_segment = 0x0000;

  cpu->instruction_pointer = 0x0000;
  cpu->flags = 0xF000;
}

void cpu_set_flag(CPU *cpu, Flag f) { cpu->flags |= f; }
void cpu_unset_flag(CPU *cpu, Flag f) { cpu->flags &= ~f; }
uint8_t cpu_flag(CPU *cpu, Flag f) { return (cpu->flags & f) != 0; }

void cpu_dump_state(CPU *cpu) {
  printf("CPU dump:\n");
  printf("General registers\n");
  printf("\tax: 0x%04X\n", cpu->accumulator);
  printf("\tbx: 0x%04X\n", cpu->base);
  printf("\tcx: 0x%04X\n", cpu->count);
  printf("\tdx: 0x%04X\n", cpu->data);
  printf("Segment registers\n");
  printf("\tcs: 0x%04X\n", cpu->code_segment);
  printf("\tds: 0x%04X\n", cpu->data_segment);
  printf("\tss: 0x%04X\n", cpu->stack_segment);
  printf("\tes: 0x%04X\n", cpu->extra_segment);
  printf("Instruction pointer: 0x%04X\n", cpu->instruction_pointer);
  printf("Flags\n");
  printf("status word: 0x%04X\n", cpu->flags);
  printf("\tcarry: %d\n", cpu_flag(cpu, FLAG_CARRY));
  printf("\tparity: %d\n", cpu_flag(cpu, FLAG_PARITY));
  printf("\tauxiliary_carry: %d\n", cpu_flag(cpu, FLAG_AUXILIARY_CARRY));
  printf("\tzero: %d\n", cpu_flag(cpu, FLAG_ZERO));
  printf("\tsign: %d\n", cpu_flag(cpu, FLAG_SIGN));
  printf("\ttrap: %d\n", cpu_flag(cpu, FLAG_TRAP));
  printf("\tinterrupt_enable: %d\n", cpu_flag(cpu, FLAG_INTERRUPT_ENABLE));
  printf("\tdirection: %d\n", cpu_flag(cpu, FLAG_DIRECTION));
  printf("\toverflow: %d\n", cpu_flag(cpu, FLAG_OVERFLOW));
}