// joystick.h
#ifndef _TINYUSB_JOYSTICK_H_
#define _TINYUSB_JOYSTICK_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Structure matching the HID report descriptor
typedef struct {
  uint16_t Button;    // 16 buttons
  uint8_t  HAT;       // Hat switch (4 bits used)
  uint8_t  LX;        // Left Stick X
  uint8_t  LY;        // Left Stick Y
  uint8_t  RX;        // Right Stick X
  uint8_t  RY;        // Right Stick Y
  uint8_t  VendorSpec;// Vendor-specific byte
} __attribute__((packed)) USB_JoystickReport_Input_t;

// Declare global report data
extern USB_JoystickReport_Input_t joystick_report;

// Initialize any hardware or state needed
void joystick_init(void);

// Fill and send the HID report to the host
void send_report(void);

#ifdef __cplusplus
}
#endif

#endif // _TINYUSB_JOYSTICK_H_