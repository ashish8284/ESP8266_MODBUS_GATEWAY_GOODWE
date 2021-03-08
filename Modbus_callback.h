int MB_STS1;
int MB_STS2;
int cbreturn1 = 0;
int cbreturn2 = 0;
bool cbWrite1(Modbus::ResultCode event1, uint16_t transactionId1, void* data1) {
  //Serial.printf_P("Request result: 0x%02X, Mem: %d\n", event, ESP.getFreeHeap());
  MB_STS1 = event1;
  cbreturn1 = 1;
  return true;
}
bool cbWrite2(Modbus::ResultCode event2, uint16_t transactionId2, void* data2) {
  //Serial.printf_P("Request result: 0x%02X, Mem: %d\n", event, ESP.getFreeHeap());
  MB_STS2 = event2;
  cbreturn2 = 1;
  return true;
}
