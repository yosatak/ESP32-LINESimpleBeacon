#include "LineBeacon.h"

LINEBeacon::LINEBeacon(uint8_t *hardwareId, m_deviceMessage *dm) {

  BLEDevice::init("");
  server = BLEDevice::createServer();
  advertising = server->getAdvertising();

  beaconData.uuid = 0xfe6f;
  beaconData.frameType = 0x02;
  beaconData.hardwareId = hardwareId;
  beaconData.txPower = 0x7f;
  beaconData.dm = dm;

  _isStarted = 0;

}

uint16_t LINEBeacon::getFrameType() {
  return beaconData.frameType;
}

uint8_t* LINEBeacon::getHardwareId() {
  return beaconData.hardwareId;
}

uint8_t LINEBeacon::getSignalPower() {
  return beaconData.txPower;
}

m_deviceMessage *LINEBeacon::getDeviceMessage() {
  return beaconData.dm;
}

void LINEBeacon::setUuid(uint16_t uuid) {
  beaconData.uuid = uuid;
}

void LINEBeacon::setFrameType(uint8_t frameType) {
  beaconData.frameType = frameType;
}

void LINEBeacon::setHardwareId(uint8_t *hardwareId) {
  beaconData.hardwareId = hardwareId;
}

void LINEBeacon::setSignalPower(uint8_t signalPower) {
  beaconData.txPower = signalPower;
}

void LINEBeacon::setDeviceMessage(m_deviceMessage *dm) {
  if(dm->size > 13) return;
  beaconData.dm = dm;
}

void LINEBeacon::start() {

  if(!_isStarted){
    BLEAdvertisementData advertisementData = BLEAdvertisementData();
    advertisementData.setFlags(0x06);

    std::string strAdvertisementData = "";
    strAdvertisementData += (char)(sizeof(beaconData.uuid)+1);
    strAdvertisementData += (char)0x03;
    strAdvertisementData += std::string((char *)&beaconData.uuid, sizeof(beaconData.uuid));
    strAdvertisementData += (char)(sizeof(beaconData.uuid) +
                                   sizeof(beaconData.frameType) +
                                   5 +
                                   beaconData.dm->size +
                                   1 );
    strAdvertisementData += (char)0x16;
    strAdvertisementData += std::string((char *)&beaconData.uuid, sizeof(beaconData.uuid));
    strAdvertisementData += beaconData.frameType;
    strAdvertisementData += std::string((char *)beaconData.hardwareId, 5);
    strAdvertisementData += std::string((char *)beaconData.dm->dm, beaconData.dm->size);

   
    advertisementData.addData(strAdvertisementData);
 

    advertising->setAdvertisementData(advertisementData);
    advertising->start();
  }else{

  }

}

void LINEBeacon::stop() {

  if(_isStarted) {
    advertising->stop();
  } else {

  }
}

void LINEBeacon::restart() {

  if(_isStarted){
    stop();
    start();
  }else {

  }
}
