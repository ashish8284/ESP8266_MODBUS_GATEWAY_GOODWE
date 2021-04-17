void jsonpack() {
  char msg[512];
  char Topic[25] ;
  StaticJsonDocument<512> doc;
  if (Slave_Sts1 == 0 && Slave_Sts2 == 0) {
    doc["MBSTS"] = "1";
  }
  else doc["MBSTS"] = "0";

  JsonObject PV = doc.createNestedObject("PV");
  PV["PV1V"] = DC_Voltage_on_PV1;
  PV["PV2V"] = DC_Voltage_on_PV2;
  PV["PV1A"] = DC_Current_on_PV1;
  PV["PV2A"] = DC_Current_on_PV2;

  JsonObject Grid = doc.createNestedObject("Grid");
  Grid["L1V"] = AC_Voltage_on_L1;
  Grid["L2V"] = AC_Voltage_on_L2;
  Grid["L3V"] = AC_Voltage_on_L3;
  Grid["L1A"] = AC_Current_on_L1;
  Grid["L2A"] = AC_Current_on_L2;
  Grid["L3A"] = AC_Current_on_L3;
  Grid["L1F"] = AC_Frequency_on_L1;
  Grid["L2F"] = AC_Frequency_on_L1;
  Grid["L3F"] = AC_Frequency_on_L1;
  Grid["PWR"] = Actual_Power;

  JsonObject Inverter = doc.createNestedObject("Inverter");
  Inverter["Sts"] = Status;
  Inverter["TMP"] = Inner_Temperature;
  Inverter["ER1"] = Error_Message_H;
  Inverter["ER2"] = Error_Message_L;

  JsonObject ENR = doc.createNestedObject("ENR");
  ENR["TOT"] = Energy_Total;
  ENR["TOD"] = Energy_Today;
  serializeJson(doc, msg);
  snprintf(Topic, 25, MQTT_Topic, slave_id);
  if (MQTT_Enable)client.publish(Topic, msg);
  Serial.print(Topic); Serial.print(":"); Serial.println(msg);
  ArduinoOTA.handle();
}
void jsonpack_01() {
  char msg01[16];
  char Topic[25] ;
  StaticJsonDocument<16> doc;
  doc["MBSTS"] = 0;
  serializeJson(doc, msg01);
  snprintf(Topic, 25, MQTT_Topic, slave_id);
  if (MQTT_Enable)client.publish(Topic, msg01);
  Serial.print(Topic); Serial.print(":"); Serial.println(msg01);
  ArduinoOTA.handle();
}
