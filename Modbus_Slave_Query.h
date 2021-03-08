long Previous_Enr = 0;
long LastScan = 0;
void MBslaveQuery(int slaveID) {
  if (Call_Stp == 1) {
    if (!mb.slave()) {//Read first 20 reg
      mb.readHreg(slaveID, 768, Mread, 20, cbWrite1);
      Slave_Sts1 = MB_STS1;
      Call_Stp = 2;
    }
  }
  if (cbreturn1 & Call_Stp == 2) {//Read last reg.
    if (!mb.slave()) {
      mb.readHreg(slaveID, 800, Mread1, 1, cbWrite2);
      Slave_Sts2 = MB_STS2;
      Call_Stp = 3;
    }
  }
  if (cbreturn2 & Call_Stp == 3) {//move buffer data
    slave_id = slaveID;
    Movedata();
    if (Energy_Total != Previous_Enr) {
      jsonpack();
      Previous_Enr = Energy_Total;
    }
    else {
      jsonpack_01();
    }
    Call_Stp = 1;
    cbreturn1 = 0;
    cbreturn2 = 0;
    Slave_ID++;
    if (Slave_ID > End_ID) {
      Slave_ID = Start_ID;
    }
    LastScan = millis();
  }
}
