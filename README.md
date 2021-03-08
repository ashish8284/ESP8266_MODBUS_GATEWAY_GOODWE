# ESP8266_Modbus_Gateway
##Functionality
Purpose of this project is to read Data from any MODBUS supported Slave devices and send all data using MQTT protocol.
Initially this project is used to read Energy data of Solar Inverter.
###Hardware Functionality/feature
    1, Read MODBUS 485 device DATA (required 485 to TTL converter)
    2, Read MODBUS 232 device DATA (required 232 to TTL converter)
    3, WIFI connection status LED
    4, MQTT Server connection status

###Software Functionality/feature
    1, MODBUS master implementation on Software Serial.
    2, Multiple Slave data read supported if Modbus slaves having 485 support.
    3, Single slave data supported if Modbus slaves having 232 support.
    4, ESP8266 ACT as WIFI AP and host all data over WEBPAGE
        4.1, WIFI AP settings can changed from Settings.h file
    5, ESP8266 ACT as WIFI client. Get IP form WIFI router (DHCP server) host Webpage over Webpage.
            5.1, WIFI router SSID and Password can change from Settings.h file
    6, Connects with MQTT server to send all energy related data to Server.
            6.1, MQTT server settings can changed from setting


##Microcontroller
    ESP8266
##Signal Converter
    485 to TTL converter.
    232 to TTL converter.

If Converter is 5VDC operated then Level shifter (WiringA) or potential divider (WiringB) to be inserted between Rx pin connection.

##Level shifter example
WiringA
    3.3VDC and 5VDC supply required.
    Connect 5V/HV pin of Level shifter to 5VDC Bus.
    Connect 3.3V/LV pin of level shifter to 3.3v Bus.
    Refer Below Schematic
 ______________       __________________               ____________________________        
|  ESP8266     |     |  Level Shifter    |            |  Converter IN              |        
|  3.3VDC      |-----| 3.3v          5v  |---5VDC     |                            |
|  GPIO12(Rx)  |-----| LV1           HV1 |------------|    Rx pin                  |
|  GPIO13(Tx)  |-----| LV2           HV2 |------------|    Tx pin                  |
|  Ground      |-----| Ground     Ground |            |                            |
|______________|     |___________________|            |____________________________| 


##Potential Divider
WiringB
 ______________                    1k 0hm                __________________________________        
|  ESP8266     |               _______                  |          Converter IN            |      
|  GPIO12(Rx)  |---------x----|_______|-----------------|    Rx pin                        |
|              |         |                              |                                  |
|              |         |      2k ohm                  |                                  |
|              |         |     _______                  |                                  |
|              |         x ---|_______|---Ground        |                                  |               
|              |                                        |                                  |
|______________|                                        |__________________________________|  


##Wiring for 484 to TTL Converter
GPOI can changed from Settings.h file
VCC pin of converter required to be connected with 3.3V DC
In case Converter is 5VDC operated then below connection will damaged RX pin of ESP8266.
Use Level shifter to protect ESP8266 RX pin(as shown in Wiring A)
WiringB
 ______________            ___________________________________          ____________________ 
|  ESP8266     |          |  ConverterIN     Converter out    |        | Modbus Slave ID1   |
|  GPIO12(Rx)  |--------- |    Rx pin              A+         |--------|                    |
|  GPIO13(Tx)  |--------- |    Tx pin              B-         |--------|                    |
|______________|          |___________________________________|   | |  |____________________|
                                                                  | |    ____________________     
                                                                  | |  | Modbus Slave IDN   |
                                                                  | ---|                    |
                                                                  -----|                    |
                                                                       |____________________|

##Wiring for 232 to TTL Converter
GPOI can changed from Settings.h file
VCC pin of converter required to be connected with 3.3V DC
In case Converter is 5VDC operated then below connection will damaged RX pin of ESP8266.
Use Level shifter to protect ESP8266 RX pin(as shown in Wiring A)

WiringC
 ______________            _____________________________________                 ___________________ 
|  ESP8266     |          |  ConverterIN     Converter Out DB9  |               | Modbus Slave IDN  |
|  GPIO12(Rx)  |--------- |    Rx pin           1               |-x           x-|         1         |
|  GPIO13(Tx)  |--------- |    Tx pin           2               |---------------|         3         |
|  Groudn      |--------- |    Ground           3               |---------------|         2         |
|______________|          |                     4               |-x           x-|         4         |
                          |                     5               |---------------|         5         |
                          |                     6               |-x           x-|         6         |
                          |                     7               |-x           x-|         7         |                
                          |                     8               |-x           x-|         8         |
                          |                     9               |-x           x-|         9         |
                          |_____________________________________|-x           x-|___________________|
                          
                          
##Solar Inverters Checked with this module
01:- Growatt Solar inverter.
        Webpage support working
02:- Goodwe Solar inverter.
        Webpage not configured as its code is developed for multiple slaves. Webpage implementation is pending for multiple slaves.

Currently two different code is there for both solar inverters.
##Future Plan: - 
    Provide single code for all Modbus supported meter by introducing Address templets.
    Multiple slave data monitoring webpage by drill down buttion.
    All setting configuration over Webpage.
    Wifi AP and Slave functionality selection using Webui.( initial boot as AP & after configuration Final operation mode decided).
    Bug fixing for Modbus connection timeout status.



