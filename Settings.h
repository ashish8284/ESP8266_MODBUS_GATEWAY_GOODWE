//TX & RX Pin assignment
int Rx = 12; //RX pin which will connect to RX pin of TTL to 232  or TTL to 485 converter
int Tx = 13; //TX pin which will connect to TX pin of TTL to 232  or TTL to 485 converter
int LED = 2; //Status LED pin. Blinks if Gateway is trying to connects with WIFI or MQTT server. Steady if connectino is successful.
int DE_RE = 4; // If Max 485 to ttl converter is used then this pin required to connect with DE and RE pin of Module.
//Wifi router Credentials
const char* ssid             = "";
const char* passuint16_t     = "";

//MQTT Server Credentials
int WIFI_Reconnect = 200; //wifi reconnection time
bool MQTT_Enable = true; //enable mqtt
int MQTT_Re_Connect_Interval = 60000; //MQTT reconnect interval in case no connection is there 
const char* mqtt_server      = "192.168.0.36"; //MQTT server IP addresss
const char* mqttUser         = ""; //MQTT server username
const char* mqttPassuint16_t = ""; //MQTT server password
const char* ClientID         = "Goodwe_SPH"; // CLient ID required to be unique for all clients.
char* MQTT_Topic       = "Goodwe/Slave"; //Topic text

//Settings for AP Mode
bool WIFIAP = false;
IPAddress AP_IP(192, 168, 11, 4); 
IPAddress AP_gateway(192, 168, 11, 1);
IPAddress AP_subnet(255, 255, 255, 0);
const char* AP_ssid             = "Techno_Automation"; 
const char* AP_passuint16_t     = "Techno$123";

//Modbus next slave inverval milliseconds
long Interval = 10000; // Delay between second slave quary generation

//Modbus Slave ID
byte Start_ID = 1; //First id
byte End_ID = 2; // Last id
