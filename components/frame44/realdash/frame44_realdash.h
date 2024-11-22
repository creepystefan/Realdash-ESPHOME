#pragma once

#include "esphome/core/component.h"
#include "esphome.h"


namespace esphome {
namespace frame44_ { 


uint16_t data0 = 2815;
uint8_t data1 = 10; 
int data2 = 11; 
unsigned int data3 = 10;  
int can_id_;

//class RealdashFrame44 : public realdash::Realdash, public PollingComponent  {
class RealdashFrame44 : public PollingComponent {
 public:
  RealdashFrame44() : PollingComponent(10) {}

void set_can_id(int can_id) { can_id_ = can_id; }

void setup() override
{
  Serial.begin(115200);
  
}

void update() override
{
  SendCANFramesToSerial();
 if (data0++ > 10000)
  {
    data0 = 500;
  }
  if (data1++ > 10000)
  {
    data1 = 10;
  }
  if (data2++ > 10000)
  {
    data2 = 0;
  }
  if (data3++ > 10000)
  {
    data3 = 0;
  }
 delay(5);
}

void SendCANFramesToSerial()
{
  byte buf[8];
  memcpy(buf, &data0, 2);
  memcpy(buf + 2, &data1, 2);
  memcpy(buf + 4, &data2, 2);
  memcpy(buf + 6, &data3, 2);
  SendCANFrameToSerial(can_id_, buf);
}
//void SendCANFrameToSerial(unsigned long canFrameId, const byte* frameData)
//{
//  const byte serialBlockTag[4] = { 0x44, 0x33, 0x22, 0x11 };
//  Serial.write(serialBlockTag, 4);
//  Serial.write((const byte*)&canFrameId, 4);
//  Serial.write(frameData, 8);
//}


};
}  // namespace frame44_
}  // namespace esphome
