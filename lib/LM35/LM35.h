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

#ifndef ATTINY_LM35_H
#define ATTINY_LM35_H

class LM35 {
public:
  void begin(uint8_t pin);
  int16_t temperature(bool fahrenheit = false);

private:
  uint8_t pin;
  float t;
};

// Init LM35.
void LM35::begin(uint8_t pin_) {
  pin = pin_;
  analogReference(INTERNAL);
  pinMode(pin, INPUT);
}

// Return temperature in Celsius by default. With `true` as argument - in Fahrenheit.
int16_t LM35::temperature(bool fahrenheit) {
  t = (float) analogRead(pin);
  if (!fahrenheit) {
    t = (float) analogRead(pin) / 1024.f * 110.f;
  } else {
    t = ((float) analogRead(pin) / 1024.f * 110.f) * 1.8f + 32.f;
  }
  return (int16_t) t;
}

#endif //ATTINY_LM35_H
