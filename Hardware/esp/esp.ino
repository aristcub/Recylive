
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include "ThingSpeak.h"
 
//Configuracion Wifi, adaptalo a tu caso
const char* ssid     = "LISSETH";
const char* password = "3126632120";
WiFiClient  client;
 
//Datos acceso Canal ThingSpeak
unsigned long numeroCanal = 1717728;
const char * WriteAPIKey = "LW2SZPKU9PEXIZWY";
 
//Temporizador ThingSpeak XXseg
unsigned long ultimoTiempo = 0; // almacena la ultima vez que se lanzo nuestro evento
unsigned long intervaloEnvio = 20000; // 20 segundos
 
int avg_time_ms; // variable global
//IP a la que vas a realizar el ping (puedes poner cualquiera)
const IPAddress remote_ip(8, 8, 8, 8);

String str;
void setup() {
  Serial.begin(9600);
  while(!Serial){
    Serial.print("esperando");
    delay(100);
    } // esperar conexion
  Serial.print("conectado");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Indicamos los datos de conexión para el monitor serial
  Serial.println("");
  Serial.println("Conectado WiFi");
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Pinging ip "); // Indicamos a la direccion IP a la que vamos a ejecutar el ping
  Serial.println(remote_ip);
  ThingSpeak.begin(client); 
}

void loop() {
/*
 // Comprobar si se ha dado la vuelta
  if (millis() < ultimoTiempo)
  {
    // Asignar un nuevo valor
    ultimoTiempo = millis();
  }
  if ((millis() -  ultimoTiempo) > intervaloEnvio)
  {
    // Marca de tiempo para el siguiente intervalo
    ultimoTiempo = millis();
 
    // Ejecutamos el metodo para saber la intensidad Wifi y lo asignamos a la variable rssi
    long rssi = WiFi.RSSI();
    Serial.print("RSSI: ");
    Serial.print(rssi);
    Serial.println(" dBm");
 
     if(Serial.available()){
      ThingSpeak.setField(1,Serial.read());
      Serial.write(Serial.read());
      //Serial.write(Serial.read());
  }
  else return;
    //ThingSpeak.setField(1, str);

 
    // subimos los datos a nuestro canal en ThingSpeak
    //200 es el codigo tipico de una transmision OK en el protocolo HTTP
    int x = ThingSpeak.writeFields(numeroCanal, WriteAPIKey);
    if (x == 200) {
      Serial.println("Canal actualizado.");
    }
    else {
      Serial.println("Problema actualizando Canal, HTTP error code " + String(x));
    }
  }
*/
if(Serial.available()){
    Serial.write(Serial.read());
  }


  
}
