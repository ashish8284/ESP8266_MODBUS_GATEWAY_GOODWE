

AsyncWebServer server(80);
AsyncEventSource events("/events");

unsigned long lastTime = 0;
unsigned long timerDelay = 3000;  // send readings timer

String processor(const String& var) {
  if (WiFi.status() != WL_CONNECTED)   Wifi_Status = "Not Connected";
  else  Wifi_Status = "Connected";
  Wifi_Sig_Strenth = WiFi.RSSI();
  if (var == "Wifi_Status") {
    return String(Wifi_Status);
  }
  if (var == "MQTT_Status") {
    return String(MQTT_Status);
  }
  if (var == "Wifi_CL_IP") {
    return String(Wifi_CL_IP);
  }
  else if (var == "Wifi_Sig_Strenth") {
    return String(Wifi_Sig_Strenth);
  }
  /*
    else if (var == "Energy_Total") {
      return String(Energy_Total);
    }
    else if (var == "Panel_Volatge") {
      return String(Panel_Volatge);
    }
    else if (var == "Panel_Amps") {
      return String(Panel_Amps);
    }
    else if (var == "Panel_Power") {
      return String(Panel_Power);
    }
    else if (var == "Fault") {
      return String(Fault);
    }
    else if (var == "Warning") {
      return String(Warning);
    }
    else if (var == "CL_IP") {
      return String(CL_IP);
    }
  */
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Techno Automation</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    p {  font-size: 1.5rem;}
    body {  margin: 0;}
    .topnav { overflow: hidden; background-color: #4B1D3F; color: white; font-size:1.5rem; }
    .content { padding: 10px; }
    .card { background-color: white; box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5); }
    .cards { max-width: auto; margin: 0 auto; display: grid; grid-gap: 1rem; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); }
    .reading { font-size: 2rem; }
    .card.Wifi_Status { color: #0b7c7b; }
    .card.MQTT_Status { color: #0e7c7b; }
    .card.Wifi_CL_IP { color: #037c7b; }
    .card.Wifi_Sig_Strenth { color: #3fca6b; }
/*
    .card.Energy_Total { color: #d62246; }
    .card.Panel_Volatge { color: ##bb10eb; }
    .card.Panel_Amps { color: ##ba10eb; }
    .card.Panel_Power { color: ##bc10eb; }
    .card.Fault { color: #17bebb; }
    .card.Warning { color: ##bb10eb; }
    .card.CL_IP { color: ##bb10eb; }
*/
  </style>
</head>
<body>
  <div class="topnav">
    <h4>Growatt_Inverter(TA)V1</h4>
  </div>
  <div class="content">
    <div class="cards">
      <div class="card Wifi_Status">
        <h4><i class="fas fa-plug"></i> Wifi_Status</h4><p><span class="reading"><span id="M_S">%Wifi_Status%</span></span></p>
      </div>
      <div class="card MQTT_Status">
        <h4><i class="fas fa-plug"></i> MQTT_Status</h4><p><span class="reading"><span id="M_S">%MQTT_Status%</span></span></p>
      </div>
            <div class="card Wifi_CL_IP">
        <h4><i class="fas fa-temperature-high"></i> Wifi_CL_IP</h4><p><span class="reading"><span id="M_S">%Wifi_CL_IP%</span></span></p>
      </div>
      <div class="card Wifi_Sig_Strenth">
        <h4><i class="fas fa-charging-station"></i> Wifi_Sig_Strenth</h4><p><span class="reading"><span id="W_L">%Wifi_Sig_Strenth%</span></span></p>
      </div>  
    </div>
  </div>
<script>
if (!!window.EventSource) {
 var source = new EventSource('/events');

 source.addEventListener('open', function(e) {
  console.log("Events Connected");
 }, false);
 source.addEventListener('Fault', function(e) {
  if (e.target.readyState != EventSource.OPEN) {
    console.log("Events Disconnected");
  }
 }, false);

 source.addEventListener('message', function(e) {
  console.log("message", e.data);
 }, false);

 source.addEventListener('Wifi_Status', function(e) {
  console.log("Wifi_Status", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('MQTT_Status', function(e) {
  console.log("MQTT_Status", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('Wifi_CL_IP', function(e) {
  console.log("Wifi_CL_IP", e.data);
  document.getElementById("M_S").innerHTML = e.data;
 }, false);

 source.addEventListener('Wifi_Sig_Strenth', function(e) {
  console.log("Wifi_Sig_Strenth", e.data);
  document.getElementById("W_L").innerHTML = e.data;
 }, false);
/*
 source.addEventListener('Energy_Total', function(e) {
  console.log("Energy_Total", e.data);
  document.getElementById("L_S").innerHTML = e.data;
 }, false);

  source.addEventListener('Panel_Volatge', function(e) {
  console.log("Panel_Volatge", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);

  source.addEventListener('Panel_Amps', function(e) {
  console.log("Panel_Amps", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);

   source.addEventListener('Panel_Power', function(e) {
  console.log("Panel_Power", e.data);
  document.getElementById("R_H").innerHTML = e.data;
 }, false);
 source.addEventListener('Fault', function(e) {
  console.log("Fault", e.data);
  document.getElementById("Fault").innerHTML = e.data;
 }, false);

  source.addEventListener('Warning', function(e) {
  console.log("Warning", e.data);
  document.getElementById("WRN").innerHTML = e.data;
 }, false);

  source.addEventListener('CL_IP', function(e) {
  console.log("CL_IP", e.data);
  document.getElementById("CL_IP").innerHTML = e.data;
 }, false);
*/
}
</script>
</body>
</html>)rawliteral";

void Webpabe_Update() {
  if (WiFi.status() != WL_CONNECTED)   Wifi_Status = "Not Connected";
  else  Wifi_Status = "Connected";
  Wifi_Sig_Strenth = WiFi.RSSI();
  Serial.print(Wifi_Status); Serial.print("\t"); Serial.println(MQTT_Status);
  events.send("ping", NULL, millis());
  events.send(String(Wifi_Status).c_str(), "Wifi_Status", millis());
  events.send(String(MQTT_Status).c_str(), "MQTT_Status", millis());
  Wifi_CL_IP = WiFi.localIP().toString();
  events.send(String(Wifi_CL_IP).c_str(), "Wifi_CL_IP", millis());
  events.send(String(WiFi.RSSI()).c_str(), "Wifi_Sig_Strenth", millis());
  /*
    events.send(String(Energy_Total).c_str(), "Energy_Total", millis());
    events.send(String(Panel_Volatge).c_str(), "Panel_Volatge", millis());
    events.send(String(Panel_Amps).c_str(), "Panel_Amps", millis());
    events.send(String(Panel_Power).c_str(), "Panel_Power", millis());
    events.send(String(Warning).c_str(), "Warning", millis());
    events.send(String(Fault).c_str(), "Fault", millis());
    CL_IP = WiFi.localIP().toString();
    events.send(String(CL_IP).c_str(), "CL_IP", millis());
  */
  ArduinoOTA.handle();
}
