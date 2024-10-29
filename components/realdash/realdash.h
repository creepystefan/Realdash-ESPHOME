#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace realdash { 

class REALDASH : public Component {
 public:
void setup() override
{
  Serial.begin(115200);
}

void dataframe()
{
 data[0] = 0x01;
 data[1] = 0x02;
 data[2] = 0x03;
 data[3] = 0x04;
 data[4] = 0x05;
 data[5] = 0x06;
 data[6] = 0x07;
 data[7] = 0x08;
}
  
void loop() override
{
  dataframe();
  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
  const byte canID[4] = { 0x1 };
  const byte Data[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
  Serial.write(serialBlockTag, 4);
  Serial.write(canID, 4);
  Serial.write(Data, 8);
  delay(5);
}
};
}  // namespace realdash
}  // namespace esphome
