void Movedata() {
  DC_Voltage_on_PV1   = Mread [0]   / 10.0 ;
  DC_Voltage_on_PV2   = Mread [1]   / 10.0 ;
  DC_Current_on_PV1   = Mread [2]   / 10.0 ;
  DC_Current_on_PV2   = Mread [3]   / 10.0 ;
  AC_Voltage_on_L1    = Mread [4]   / 10.0 ;
  AC_Voltage_on_L2    = Mread [5]   / 10.0 ;
  AC_Voltage_on_L3    = Mread [6]   / 10.0 ;
  AC_Current_on_L1    = Mread [7]   / 10.0 ;
  AC_Current_on_L2    = Mread [8]   / 10.0 ;
  AC_Current_on_L3    = Mread [9]   / 10.0 ;
  AC_Frequency_on_L1  = Mread [10]  / 100.0 ;
  AC_Frequency_on_L2  = Mread [11]  / 100.0 ;
  AC_Frequency_on_L3  = Mread [12]  / 100.0 ;
  Actual_Power        = Mread [13] ;
  Status              = Mread [14]   ;
  Inner_Temperature   = Mread [15]  / 10.0 ;
  Error_Message_H     = Mread [16] ;
  Error_Message_L     = Mread [17] ;
  Energy_Total        = InttoDint(Mread[18], Mread[19]);
  Energy_Today        = Mread1[0 ]  / 10.0 ;
/*
    Serial.print(  slave_id  ); Serial.print(",");
    Serial.print( Slave_Sts  ); Serial.print(",");
    Serial.print( DC_Voltage_on_PV1 ); Serial.print(",");
    Serial.print( DC_Voltage_on_PV2 ); Serial.print(",");
    Serial.print( DC_Current_on_PV1 ); Serial.print(",");
    Serial.print( DC_Current_on_PV2 ); Serial.print(",");
    Serial.print( AC_Voltage_on_L1  ); Serial.print(",");
    Serial.print( AC_Voltage_on_L2  ); Serial.print(",");
    Serial.print( AC_Voltage_on_L3  ); Serial.print(",");
    Serial.print( AC_Current_on_L1  ); Serial.print(",");
    Serial.print( AC_Current_on_L2  ); Serial.print(",");
    Serial.print( AC_Current_on_L3  ); Serial.print(",");
    Serial.print( AC_Frequency_on_L1  ); Serial.print(",");
    Serial.print( AC_Frequency_on_L2  ); Serial.print(",");
    Serial.print( AC_Frequency_on_L3  ); Serial.print(",");
    Serial.print( Actual_Power  ); Serial.print(",");
    Serial.print( Status  ); Serial.print(",");
    Serial.print( Inner_Temperature ); Serial.print(",");
    Serial.print( Error_Message_H ); Serial.print(",");
    Serial.print( Error_Message_L ); Serial.print(",");
    Serial.print( Energy_Total  ); Serial.print(",");
    Serial.print( Energy_Today  ); Serial.println(",");
*/
}
