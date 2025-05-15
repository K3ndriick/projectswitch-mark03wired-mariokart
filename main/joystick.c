// joystick.c
#include "joystick.h"
#include "bsp/board.h"
#include "tusb.h"

USB_JoystickReport_Input_t joystick_report = {
  .Button = 0,
  .HAT = 0x08,  // Default to center (null state)
  .LX = 128,
  .LY = 128,
  .RX = 128,
  .RY = 128,
  .VendorSpec = 0
};

void joystick_init(void) {
  board_init();
  tusb_init();
}

void send_report(void) {
  if (tud_hid_ready()) {
    tud_hid_report(0, &joystick_report, sizeof(joystick_report));
  }
}

// Optional callbacks for HID
uint16_t tud_hid_get_report_cb(uint8_t report_id, hid_report_type_t report_type,
                                uint8_t* buffer, uint16_t reqlen) {
  // Not used in this example
  return 0;
}

void tud_hid_set_report_cb(uint8_t report_id, hid_report_type_t report_type,
                           uint8_t const* buffer, uint16_t bufsize) {
  // Not used, but this is where OUT reports from host would be handled
}
