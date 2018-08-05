#include "LINESimpleBeacon.h"

uint8_t hardwareId[] = {0x01,0x02,0x03,0x04,0x05,0x06};
uint8_t devicemessage[] = {0x02,0x03,0x04};
m_deviceMessage dm = {
  devicemessage,
  sizeof(devicemessage)
};

LINEBeacon beacon(hardwareId);


void setup() {
  Serial.begin(115200);
  Serial.println("hello");
  
  beacon.start();
}

// the loop function runs over and over again forever
void loop() {

}
