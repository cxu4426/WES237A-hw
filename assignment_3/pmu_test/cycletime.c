#include <stdint.h>

/* Initialize PMU counters */
void pmu_init(int32_t do_reset, int32_t enable_divider)
{
    int32_t value = 1;

    if (do_reset)
        value |= 6;     // reset all counters
    if (enable_divider)
        value |= 8;

    value |= 16;

    asm volatile ("MCR p15, 0, %0, c9, c12, 0\n\t" :: "r"(value));
    asm volatile ("MCR p15, 0, %0, c9, c12, 1\n\t" :: "r"(0x8000000f));
    asm volatile ("MCR p15, 0, %0, c9, c12, 3\n\t" :: "r"(0x8000000f));
}

/* Read cycle counter */
unsigned int pmu_get_cyclecount(void)
{
    unsigned int value;
    asm volatile ("MRC p15, 0, %0, c9, c13, 0\n\t" : "=r"(value));
    return value;
}
