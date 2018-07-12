#ifndef LINE_BEACON_H
#define LINE_BEACON_H
#include "BLEUUID.h"
#include "BLEServer.h"
#include "BLEDevice.h"
#include "BLEAdvertising.h"

typedef struct {
  uint8_t *dm;
  short int size;
} __attribute__((packed))m_deviceMessage;


class LINEBeacon {
private:

  typedef struct {
    uint16_t uuid;
    uint8_t frameType;
    uint8_t *hardwareId;
    uint8_t txPower;
    uint8_t minor;
    int8_t signalPower;
    m_deviceMessage *dm;
  } __attribute__((packed))m_beaconData;

  m_beaconData beaconData;

  BLEServer *server;
  BLEAdvertising *advertising;

  int _isStarted;


public:


  LINEBeacon(uint8_t *hardwareId, m_deviceMessage *dm);
  BLEUUID getUuid();
  uint16_t getFrameType();
  uint8_t* getHardwareId();
  uint8_t getSignalPower();
  m_deviceMessage *getDeviceMessage();

  void setUuid(uint16_t  uuid);
  void setFrameType(uint8_t frameType);
  void setHardwareId(uint8_t *hardwareId);
  void setSignalPower(uint8_t signalPower);
  void setDeviceMessage(m_deviceMessage *dm);
  void start();
  void stop();

  void restart();

};

#endif
