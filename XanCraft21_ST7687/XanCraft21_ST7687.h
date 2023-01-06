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

#ifndef _XanCraft21_ST7687_H_
#define _XanCraft21_ST7687_H_

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>

class XanCraft21_ST7687 : public Adafruit_SPITFT {
  public:

  // Software SPI
  XanCraft21_ST7687(int8_t cs_pin, int8_t dc_pin, int8_t mosi_pin, int8_t sclk_pin, int8_t lck_pin, int8_t wr_pin);

  // Hardware SPI
  XanCraft21_ST7687(SPIClass *spi, int8_t cs_pin, int8_t dc_pin, int8_t lck_pin, int8_t wr_pin);

  // Destructor
  ~XanCraft21_ST7687(void);

  // Display functions
  void begin(uint32_t freq = 8000000);
  void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h);
  void sendToDisplay(uint8_t _data, bool _dc);
  void sendToDisplay16(uint16_t _data, bool _dc);
  void writeClock();

  // Drawing functions
  //void fillScreen(uint16_t color);
  void drawPixel(int16_t x, int16_t y, uint16_t color) override;
  //void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
  void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
  void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;
  void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;
  /*void drawRectS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  void fillRectS(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);*/

  // Drawing functions 2
  void writePixel(int16_t x, int16_t y, uint16_t color) override;
  void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) override;
  void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
  void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
  void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;

  // Helper functions
  //void swapInt16(int16_t int_a, int16_t int_b);

  // Display resolution
  static const int16_t TFTWIDTH = 128;
  static const int16_t TFTHEIGHT = 128;

  private:

  // Private pins
  uint8_t _lck_pin;
  uint8_t _wr_pin;
};

#endif // _XanCraft21_ST7687_H_