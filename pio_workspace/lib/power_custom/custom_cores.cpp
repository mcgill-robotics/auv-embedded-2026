#ifdef POWER_H

#include "custom_cores.h"

void pinModeOutputHigh(uint8_t pin)
{
	const struct digital_pin_bitband_and_config_table_struct *p;

	if (pin >= CORE_NUM_DIGITAL) return;
	p = digital_pin_to_info_PGM + pin;

    // This was written with the assitance of AI
    // This preloads the set pin to HIGH before the pin is initalized which prevents the pin from dropping to low on initialization if pulled up with a resistor
    // When inspecting the digitalWrite function in digital.c from the teensy cores, it can be seen that 0x21 corresponds to set (HIGH) and 0x22 corresponds to clear (LOW)
    // Simply loading those pins with a mask sets the pin to either HIGH or to LOW
    // The datasheet of the chip has different specific numbers due to abstraction of the pin numbers by the cores
    // Page 971 (Section 12.6.1.10) of this datasheet https://www.pjrc.com/teensy/IMXRT1060RM_rev3_annotations.pdf deomstrates the equivalent functionality
    *(p->reg + 0x21) = p->mask;
    
    *(p->reg + 1) |= p->mask; // TODO: atomic
    *(p->pad) = IOMUXC_PAD_DSE(7);
	*(p->mux) = 5 | 0x10;
}

#endif
