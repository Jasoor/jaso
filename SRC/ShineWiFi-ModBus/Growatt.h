#ifndef _GROWATT_H_
#define _GROWATT_H_

#include "Arduino.h"
#include "GrowattTypes.h"

class Growatt {
  public:
    Growatt();
    void begin(Stream &serial, uint16_t version);
    bool ReadData();
    eDevice_t GetWiFiStickType();
    sGrowattModbusReg_t GetInputRegister(SupportedModbusInputRegisters_t register);
    sGrowattModbusReg_t GetHoldingRegister(SupportedModbusHoldingRegisters_t register);
    bool ReadInputReg(uint16_t adr, uint32_t* result);
    bool ReadInputReg(uint16_t adr, uint16_t* result);
    bool ReadHoldingReg(uint16_t adr, uint32_t* result);
    bool ReadHoldingReg(uint16_t adr, uint16_t* result);
    bool WriteHoldingReg(uint16_t adr, uint16_t value);

    void CreateJson(char *Buffer, const char* MacAddress);

    eGrowattStatus_t GetStatus();
    float GetAcPower();

  private:
    sProtocolDefinition_t _Protocol;
    eDevice_t _eDevice;
    bool _GotData;
    uint32_t _PacketCnt;

    eDevice_t _InitModbusCommunication();
    bool _ReadRegisterData(uint16_t registerCount, sGrowattModbusReg_t *registers, uint8_t fragmentCount, sGrowattReadFragment_t *readFragments);
};

#endif // _GROWATT_H_