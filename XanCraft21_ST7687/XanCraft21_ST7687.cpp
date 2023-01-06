/* Arduino library to drive the DFRobot 2.2 inch 128x128 round TFT LCD display with ST7687S driver.
 *
 * This library uses Adafruit_GFX and must be installed with this library in order for this to work.
 *
 * This display is getting very hard to find online and may be discontinued.
 * If you can find the display by itself, it may be possible to make your own with a 74HC595 shift register.
 * As of right now the only place to get this display by itself is only one seller on AliExpress, coming from china.
 *
 * Most of the credit goes to Adafruit for their graphics library and to DFRobot for their original library code.
 */

#include "XanCraft21_ST7687.h"

// Software SPI
XanCraft21_ST7687::XanCraft21_ST7687(int8_t cs_pin, int8_t dc_pin, int8_t mosi_pin, int8_t sclk_pin, int8_t lck_pin, int8_t wr_pin) : Adafruit_SPITFT(TFTWIDTH, TFTHEIGHT, cs_pin, dc_pin, mosi_pin, sclk_pin, -1, -1) {
  _lck_pin = lck_pin;
  _wr_pin = wr_pin;
}

// Hardware SPI
XanCraft21_ST7687::XanCraft21_ST7687(SPIClass *spi, int8_t cs_pin, int8_t dc_pin, int8_t lck_pin, int8_t wr_pin)
  :
  #if defined(ESP8266)
      Adafruit_SPITFT(TFTWIDTH, TFTHEIGHT, cs_pin, dc_pin, -1) {
  #elif defined(__SAM3X8E__)
      Adafruit_SPITFT(TFTWIDTH, TFTHEIGHT, cs_pin, dc_pin, -1) {
  #else
      Adafruit_SPITFT(TFTWIDTH, TFTHEIGHT, spi, cs_pin, dc_pin, -1) {
  #endif

  _lck_pin = lck_pin;
  _wr_pin = wr_pin;
}

// Destructor
XanCraft21_ST7687::~XanCraft21_ST7687(void) {}

// Init display
void XanCraft21_ST7687::begin(uint32_t freq) {
  initSPI(freq);

  pinMode(_lck_pin, OUTPUT);
  pinMode(_wr_pin, OUTPUT);

  digitalWrite(_lck_pin, LOW);
  digitalWrite(_wr_pin, HIGH);

  delay(120);

  sendToDisplay(0xd7, false);
  //writeClock();
  sendToDisplay(0x9f, true);
  //writeClock();

  sendToDisplay(0xe0, false);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();
  delay(10);

  sendToDisplay(0xfa, false);
  //writeClock();
  sendToDisplay(0x01, true);
  //writeClock();
  delay(20);

  sendToDisplay(0xe3, false);
  //writeClock();
  delay(20);
  sendToDisplay(0xe1, false);
  //writeClock();

  sendToDisplay(0x28, false);
  //writeClock();
  sendToDisplay(0x11, false);
  //writeClock();
  delay(30);
  sendToDisplay(0xc0, false);
  //writeClock();
  sendToDisplay(0x17, true);   // ctrL=0x1b 080416 5PCS 0X1E; 8PCS 0X2A
  //writeClock();
  sendToDisplay(0x01, true);
  //writeClock();

  sendToDisplay(0x25, false);
  //writeClock();
  sendToDisplay(0x1e, true);
  //writeClock();
  sendToDisplay(0xc3, false);
  //writeClock();
  sendToDisplay(0x03, true);
  //writeClock();

  sendToDisplay(0xc4, false);
  //writeClock();
  sendToDisplay(0x07, true);
  //writeClock();

  sendToDisplay(0xc5, false);
  //writeClock();
  sendToDisplay(0x01, true);
  //writeClock();

  sendToDisplay(0xcb, false);
  //writeClock();
  sendToDisplay(0x01, true);
  //writeClock();

  sendToDisplay(0xb7, false);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();

  sendToDisplay(0xd0, false);
  //writeClock();
  sendToDisplay(0x1d, true);
  //writeClock();
  sendToDisplay(0xb5, false);
  //writeClock();
  sendToDisplay(0x89, true);
  //writeClock();

  sendToDisplay(0xbd, false);
  //writeClock();
  sendToDisplay(0x02, true);
  //writeClock();

  sendToDisplay(0xf0, false);
  //writeClock();
  sendToDisplay(0x07, true);
  //writeClock();
  sendToDisplay(0x0c, true);
  //writeClock();
  sendToDisplay(0x0c, true);
  //writeClock();
  sendToDisplay(0x12, true);
  //writeClock();

  sendToDisplay(0xf4, false);
  //writeClock();
  sendToDisplay(0x33, true);
  //writeClock();
  sendToDisplay(0x33, true);
  //writeClock();
  sendToDisplay(0x33, true);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();
  sendToDisplay(0x33, true);
  //writeClock();
  sendToDisplay(0x66, true);
  //writeClock();
  sendToDisplay(0x66, true);
  //writeClock();
  sendToDisplay(0x66, true);
  //writeClock();

  sendToDisplay(0x20, false);
  //writeClock();
  sendToDisplay(0x2a, false);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();
  sendToDisplay(0x7f, true);
  //writeClock();

  sendToDisplay(0x2b, false);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();
  sendToDisplay(0x7f, true);
  //writeClock();

  sendToDisplay(0x3a, false);
  //writeClock();
  sendToDisplay(0x05, true);
  //writeClock();

  sendToDisplay(0x36, false);
  //writeClock();
  sendToDisplay(0x80, true); // 0xc3
  //writeClock();

  sendToDisplay(0xb0, false);
  //writeClock();
  sendToDisplay(0x7f, true);
  //writeClock();

  sendToDisplay(0x29, false);
  //writeClock();
  ////////
  sendToDisplay(0xf9, false);
  //writeClock();
  sendToDisplay(0x00, true);
  //writeClock();
  sendToDisplay(0x02, true);
  //writeClock();
  sendToDisplay(0x04, true);
  //writeClock();
  sendToDisplay(0x06, true);
  //writeClock();
  sendToDisplay(0x08, true);
  //writeClock();
  sendToDisplay(0x0a, true);
  //writeClock();
  sendToDisplay(0x0c, true);
  //writeClock();
  sendToDisplay(0x0e, true);
  //writeClock();
  sendToDisplay(0x10, true);
  //writeClock();
  sendToDisplay(0x12, true);
  //writeClock();
  sendToDisplay(0x14, true);
  //writeClock();
  sendToDisplay(0x16, true);
  //writeClock();
  sendToDisplay(0x18, true);
  //writeClock();
  sendToDisplay(0x1a, true);
  //writeClock();
  sendToDisplay(0x1c, true);
  //writeClock();
  sendToDisplay(0x1e, true);
  //writeClock();

  sendToDisplay(0x29, false);
  //writeClock();
}

// Set address window
void XanCraft21_ST7687::setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h) {
  uint16_t x2 = x1 + w - 1, y2 = y1 + h - 1;

  sendToDisplay(0x2a, false);
  //writeClock();
  sendToDisplay(x1, true);
  //writeClock();
  sendToDisplay(x2, true);
  //writeClock();

  sendToDisplay(0x2b, false);
  //writeClock();
  sendToDisplay(y1, true);
  //writeClock();
  sendToDisplay(y2, true);
  //writeClock();

  sendToDisplay(0x2c, false);
  //writeClock();
}

// Swap two 16-bit int values

#ifndef swapInt16

#define swapInt16(int_a, int_b) { \
  int16_t temp = int_a;           \
  int_a = int_b;                  \
  int_b = temp;                   \
}

#endif

// Fill the entire screen a solid color
/*void XanCraft21_ST7687::fillScreen(uint16_t color) {
  fillRect(0, 0, _width, _height, color);
  //fillRectS(0, 0, _width, _height, color);
}*/

// Draw a single pixel
void XanCraft21_ST7687::drawPixel(int16_t x, int16_t y, uint16_t color) {
  // Clip first...
  if ((x >= 0) && (x < _width) && (y >= 0) && (y < _height)) {
    // THEN set up transaction (if needed) and draw...
    startWrite();
    setAddrWindow(x, y, 1, 1);
    sendToDisplay16(color, true);
    endWrite();
  }
}
/*
// Draw a line from 2 points
void XanCraft21_ST7687::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {

  if (x0 == x1) {
    if (y0 > y1)
      swapInt16(y0, y1);
    drawFastVLine(x0, y0, y1 - y0 + 1, color);
  } else if (y0 == y1) {
    if (x0 > x1)
      swapInt16(x0, x1);
    drawFastHLine(x0, y0, x1 - x0 + 1, color);
  } else {
    startWrite();
    writeLine(x0, y0, x1, y1, color);
    endWrite();
  }
}*/

// Draw a straight line from left to right
void XanCraft21_ST7687::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
  startWrite();
  writeLine(x, y, x + w - 1, y, color);
  endWrite();
}

// Draw a straight line from top to bottom
void XanCraft21_ST7687::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
  startWrite();
  writeLine(x, y, x, y + h - 1, color);
  endWrite();
}

// Draw a rectangle
void XanCraft21_ST7687::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  startWrite();
  writeFastHLine(x, y, w, color);
  writeFastHLine(x, y + h - 1, w, color);
  writeFastVLine(x, y, h, color);
  writeFastVLine(x + w - 1, y, h, color);

  //drawFastHLine(x, y, w, color);
  //drawFastHLine(x, y + h - 1, w, color);
  //drawFastVLine(x, y, h, color);
  //drawFastVLine(x + w - 1, y, h, color);  
  endWrite();
}

// Fill a rectangle
void XanCraft21_ST7687::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  startWrite();
  for (int16_t i = x; i < x + w; i++) {
    writeFastVLine(i, y, h, color);

    //drawFastVLine(i, y, h, color);
  }
  endWrite();
}
/*
// Draw a rectangle, modded
void XanCraft21_ST7687::drawRectS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  startWrite();
  writeFastHLine(x, y, w, color);
  writeFastHLine(x, y + h - 1, w, color);
  writeFastVLine(x, y, h, color);
  writeFastVLine(x + w - 1, y, h, color);

  //drawFastHLine(x, y, w, color);
  //drawFastHLine(x, y + h - 1, w, color);
  //drawFastVLine(x, y, h, color);
  //drawFastVLine(x + w - 1, y, h, color);  
  endWrite();
}

// Fill a rectangle, modded
void XanCraft21_ST7687::fillRectS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  startWrite();
  for (int16_t i = x; i < x + w; i++) {
    writeFastVLine(i, y, h, color);

    //drawFastVLine(i, y, h, color);
  }
  endWrite();
}*/

// Write a single pixel
void XanCraft21_ST7687::writePixel(int16_t x, int16_t y, uint16_t color) {
  if ((x >= 0) && (x < _width) && (y >= 0) && (y < _height)) {
    setAddrWindow(x, y, 1, 1);
    sendToDisplay16(color, true);
  }
}

// Write a line from 2 points
void XanCraft21_ST7687::writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
  #if defined(ESP8266)
    yield();
  #endif

  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    swapInt16(x0, y0);
    swapInt16(x1, y1);
  }

  if (x0 > x1) {
    swapInt16(x0, x1);
    swapInt16(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
      writePixel(y0, x0, color);
    } else {
      writePixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

// Write a straight line from left to right
void XanCraft21_ST7687::writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
  // Example: writeLine(x, y, x+w-1, y, color);
  // or writeFillRect(x, y, w, 1, color);
  //drawFastHLine(x, y, w, color);

  //startWrite();
  writeLine(x, y, x+w-1, y, color);
  //endWrite();
}

// Write a straight line from top to bottom
void XanCraft21_ST7687::writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
  // Can be just writeLine(x, y, x, y+h-1, color);
  // or writeFillRect(x, y, 1, h, color);
  //drawFastVLine(x, y, h, color);

  //startWrite();
  writeLine(x, y, x, y+h-1, color);
  //endWrite();
}

// Write a filled rectangle
void XanCraft21_ST7687::writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  fillRect(x, y, w, h, color);
}

// Swap two 16-bit int values

//#ifndef swapInt16

//#define swapInt16(int_a, int_b) { \
//  uint16_t temp = int_a;          \
//  int_a = int_b;                  \
//  int_b = temp;                   \
//}

//#endif

//void XanCraft21_ST7687::swapInt16(int16_t int_a, int16_t int_b) {
//  int16_t temp = int_a;
//  int_a = int_b;
//  int_b = temp;
//}

// Emulate sending data to the display with hardware SPI
void XanCraft21_ST7687::sendToDisplay(uint8_t _data, bool _dc) {
  SPI_CS_LOW();

  if (_dc) {
    SPI_DC_HIGH();
  } else {
    SPI_DC_LOW();
  }

  //SPI.transfer(_data);
  spiWrite(_data);
  writeClock();

  SPI_CS_HIGH();
}

// Emulate sending data to the display with hardware SPI, 16-bit
void XanCraft21_ST7687::sendToDisplay16(uint16_t _data, bool _dc) {
  SPI_CS_LOW();

  if (_dc) {
    SPI_DC_HIGH();
  } else {
    SPI_DC_LOW();
  }

  //SPI.transfer(_data >> 8);
  spiWrite(_data >> 8);
  writeClock();
  //SPI.transfer(_data);
  spiWrite(_data);
  writeClock();

  SPI_CS_HIGH();
}

// Write commands and data to the display
void XanCraft21_ST7687::writeClock() {
  digitalWrite(_lck_pin, HIGH);
  digitalWrite(_lck_pin, LOW);
  digitalWrite(_wr_pin, LOW);
  digitalWrite(_wr_pin, HIGH);
}