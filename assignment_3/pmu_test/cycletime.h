#include <stdint.h>

void pmu_init(int32_t do_reset, int32_t enable_divider);
unsigned int pmu_get_cyclecount(void);