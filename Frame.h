#define Frame_width 128
#define Frame_height 50
#define W2_width 10
#define W2_height 8
#define W3_width 10
#define W3_height 8
#define W4_width 10
#define W4_height 8
#define W5_width 10
#define W5_height 8
#define Img_Battery_0_width 16
#define Img_Battery_0_height 8
#define Img_Battery_1_width 16
#define Img_Battery_1_height 8
#define Img_Battery_2_width 16
#define Img_Battery_2_height 8
#define Img_Battery_3_width 16
#define Img_Battery_3_height 8
#define Img_BigBattery_low_width 65
#define Img_BigBattery_low_height 37

const char Frame_bits[] PROGMEM = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x80,
  0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, };

const char W2_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x30, 0x00, 0x30, 0x00, };

const char W3_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x84, 0x00, 
  0x30, 0x00, 0x30, 0x00, };

const char W4_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x02, 0x01, 0xFC, 0x00, 0x84, 0x00, 
  0x30, 0x00, 0x30, 0x00, };

const char W5_bits[] PROGMEM = {
  0xFF, 0x03, 0x01, 0x02, 0xFE, 0x01, 0x02, 0x01, 0xFC, 0x00, 0x84, 0x00, 
  0x30, 0x00, 0x30, 0x00, };

const char Img_Battery_0[] PROGMEM = {
    0xFF, 0x7F, 0x01, 0x40, 0x01, 0xC0, 0x01, 0x80, 0x01, 0x80, 0x01, 0xC0,
  0x01, 0x40, 0xFF, 0x7F,};												//
												//
const char Img_Battery_1[] PROGMEM = {
    0xFF, 0x7F, 0x01, 0x40, 0x1D, 0xC0, 0x1D, 0x80, 0x1D, 0x80, 0x1D, 0xC0,
  0x01, 0x40, 0xFF, 0x7F,};
												//
const char Img_Battery_2[] PROGMEM = {
    0xFF, 0x7F, 0x01, 0x40, 0xDD, 0xC1, 0xDD, 0x81, 0xDD, 0x81, 0xDD, 0xC1,
  0x01, 0x40, 0xFF, 0x7F,};
												//
const char Img_Battery_3[] PROGMEM = {
    0xFF, 0x7F, 0x01, 0x40, 0xDD, 0xDD, 0xDD, 0x9D, 0xDD, 0x9D, 0xDD, 0xDD,
  0x01, 0x40, 0xFF, 0x7F,};
												//
const char Img_BigBattery_low[] PROGMEM = {
    0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x80, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x3F, 0x00, 0x00, 0x80, 0x03, 0xF8, 0x03, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x80, 0x03, 0xF0, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x80, 0x03, 0xE0,
  0x0F, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x80, 0x03, 0xC0, 0x1F, 0x00, 0x00,
  0xF8, 0x01, 0x00, 0x80, 0x03, 0x80, 0x3F, 0x00, 0x00, 0xF8, 0x01, 0x00,
  0x80, 0x03, 0x00, 0x7F, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00,
  0xFE, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0xFC, 0x01, 0x00,
  0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0xF8, 0x03, 0x00, 0xC0, 0x01, 0x00,
  0x80, 0x03, 0x00, 0xF0, 0x07, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00,
  0xE0, 0x0F, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0xC0, 0x1F, 0x00,
  0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x3F, 0x00, 0xC0, 0x01, 0x00,
  0x80, 0x03, 0x00, 0x00, 0x7F, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00,
  0x00, 0xFE, 0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x00, 0xFC, 0x01,
  0xF8, 0x01, 0x00, 0x80, 0x03, 0x00, 0x00, 0xF8, 0x03, 0xF8, 0x01, 0x00,
  0x80, 0x03, 0x00, 0x00, 0xF0, 0x07, 0xF8, 0x01, 0x00, 0x80, 0x03, 0x00,
  0x00, 0xE0, 0x0F, 0x38, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0xC0, 0x1F,
  0x38, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00,
  0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x80, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};
