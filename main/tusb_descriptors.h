#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include "tusb.h"

// Endpoint packet size
#define JOYSTICK_EPSIZE 64

// HID report descriptor length (must match your actual size)
extern uint8_t const desc_hid_report[];
extern uint8_t const *tud_hid_descriptor_report_cb(void);

// Descriptor callbacks
uint8_t const *tud_descriptor_device_cb(void);
uint8_t const *tud_descriptor_configuration_cb(uint8_t index);
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid);

#endif
