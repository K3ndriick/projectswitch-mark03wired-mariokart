#include "tusb_descriptors.h"
#include "tusb.h"
#include <string.h>

//
// 1. HID REPORT DESCRIPTOR (paste yours here)
//
uint8_t const hid_report_descriptor[] = {
    0x05, 0x01,                    // Usage Page (Generic Desktop)
    0x09, 0x05,                    // Usage (Joystick)
    0xA1, 0x01,                    // Collection (Application)
    
    // Buttons (16 bits = 16 buttons)
    0x15, 0x00,                    // Logical Minimum (0)
    0x25, 0x01,                    // Logical Maximum (1)
    0x35, 0x00,                    // Physical Minimum (0)
    0x45, 0x01,                    // Physical Maximum (1)
    0x75, 0x01,                    // Report Size (1)
    0x95, 0x10,                    // Report Count (16)
    0x05, 0x09,                    // Usage Page (Button)
    0x19, 0x01,                    // Usage Minimum (Button 1)
    0x29, 0x10,                    // Usage Maximum (Button 16)
    0x81, 0x02,                    // Input (Data, Variable, Absolute)
  
    // Hat Switch (1 nibble)
    0x05, 0x01,                    // Usage Page (Generic Desktop)
    0x25, 0x07,                    // Logical Maximum (7)
    0x46, 0x3B, 0x01,              // Physical Maximum (315)
    0x75, 0x04,                    // Report Size (4)
    0x95, 0x01,                    // Report Count (1)
    0x65, 0x14,                    // Unit (Eng Rot: Degrees)
    0x09, 0x39,                    // Usage (Hat Switch)
    0x81, 0x42,                    // Input (Data, Variable, Absolute, Null State)
  
    // Extra nibble (4 bits, unclear usage)
    0x65, 0x00,                    // Unit (None)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x01,                    // Input (Constant)
  
    // Joystick axes (4 bytes)
    0x26, 0xFF, 0x00,              // Logical Maximum (255)
    0x46, 0xFF, 0x00,              // Physical Maximum (255)
    0x09, 0x30,                    // Usage (X)
    0x09, 0x31,                    // Usage (Y)
    0x09, 0x32,                    // Usage (Z)
    0x09, 0x35,                    // Usage (Rz)
    0x75, 0x08,                    // Report Size (8)
    0x95, 0x04,                    // Report Count (4)
    0x81, 0x02,                    // Input (Data, Variable, Absolute)
  
    // Vendor-specific input (1 byte)
    0x06, 0x00, 0xFF,              // Usage Page (Vendor Defined 0xFF00)
    0x09, 0x20,                    // Usage (0x20)
    0x95, 0x01,                    // Report Count (1)
    0x81, 0x02,                    // Input (Data, Variable, Absolute)
  
    // Output report (8 bytes)
    0x0A, 0x21, 0x26,              // Usage (0x2621)
    0x95, 0x08,                    // Report Count (8)
    0x91, 0x02,                    // Output (Data, Variable, Absolute)
  
    0xC0                           // End Collection
  };
  

  uint8_t const * tud_hid_descriptor_report_cb(void)
{
  return hid_report_descriptor;
}

//
// 2. DEVICE DESCRIPTOR
//



//
// 3. CONFIGURATION DESCRIPTOR
//



//
// 4. STRING DESCRIPTORS
//