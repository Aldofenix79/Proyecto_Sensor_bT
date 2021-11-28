#include "BluetoothSerial.h"
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int DHTPin = 25;     
DHT dht(DHTPin, DHTTYPE);

int alerta = 12;
String Mensaje;

void setup() 
{
  Serial.begin(9600);
  SerialBT.begin("ESP32test");
  SerialBT.println("Conexion exitosa");
  pinMode(alerta,OUTPUT);
  dht.begin();
}

void loop() 
{
  /// LECTURA DE VARIABLES DEL SENSOR DHT 11
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  ///COMUNICACION SERIAL BLUETOOTH 

  if (SerialBT.available()) {
     Mensaje = SerialBT.readString();
    if (Mensaje == "ON") {
      digitalWrite(alerta, HIGH);
      SerialBT.println("Sensor Prendido\n\n");
    }
    else if (Mensaje == "OFF") {
      digitalWrite(alerta, LOW);
      SerialBT.println("Sensor Apagado\n\n");
    }
  }

  ///ALERTAS 
  
  if (h >= 60)
  {
    digitalWrite(alerta,HIGH);
    SerialBT.println("ALERTA: DEMASIADA HUMEDAD\n");
  }
  else if(t >= 60)
  {
   digitalWrite(alerta,HIGH);
   SerialBT.println("ALERTA: TEMPERATURA ALTA\n");
  }
  else
  {
    digitalWrite(alerta,LOW);
    SerialBT.println("TODO BIEN...\n");
  }

  //MOSTRAR LOS DATOS EN LOS 2 MONITORES SERIALES
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print("\n");
    
    SerialBT.print("Humedad: ");
    SerialBT.print(h);
    SerialBT.print("%\n");
    SerialBT.print("Temperatura: ");
    SerialBT.print(t);
    SerialBT.println("*C\n\n");
    delay(5000);
}
