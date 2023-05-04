#include "cpu.h"

int main() {
  CPU cpu;
  cpu_reset(&cpu);
  cpu_dump_state(&cpu);
  return 0;
}
