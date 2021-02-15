/*
 * MIT License
 *
 * Copyright (c) 2021 veleth
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <Arduino.h>
#include <Tiny4kOLED.h>
#include <LM35.h>

#define LM35_PIN 3

LM35 lm35;

void setup() {
  oled.begin();
  
  oled.setFont(FONT6X8);
  
  // clears the memory before turning on the display.
  oled.clear();
  // turns on the display.
  oled.on();

  oled.switchRenderFrame();
  lm35.begin(LM35_PIN);
}

void loop() {
  unsigned long uptime = millis() / 60000;
  
  oled.clear();
  oled.setCursor(0, 0);
  
  oled.print(F("temp: "));
  oled.print(lm35.temperature());
  oled.println(F(" C"));
  
  oled.setCursor(0, 3);

  if (uptime >= 1) {
    oled.print(F("up: "));
    oled.print((int) uptime);
    oled.print(F(" min "));
  }
  
  oled.switchFrame();
  delay(5000);
}
