#include "BluetoothSerial.h"
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int DHTPin = 25;     
DHT dht(DHTPin, DHTTYPE);

int limite;
int alerta = 12;
String Mensaje;
int captura;

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
     //Mensaje = SerialBT.readString();
     SerialBT.println("INTRODUCIR 1(PARA ACTIVAR) y 0 (PARA DESCATIVAR LA ALARMA)\n\n"); 
     
     int captura = SerialBT.parseInt(); //CAPTURO LOS DATOS DEL SERIAL EN FORMA DE ENTEROS PARA PODER MANIPULAR LOS LIMITES DEL SENSOR
    
    if(captura >= 0)
    {
      limite = captura;
      if (captura == 1) 
      {
        digitalWrite(alerta, HIGH);
        SerialBT.println("Alarma activada\n\n");
      }
      else if (Mensaje == 0) 
      {
        digitalWrite(alerta, LOW);
        SerialBT.println("Alarma apagada\n\n");
      }
        SerialBT.print("\n");
        SerialBT.print("El limite de temperatura y humedad ha cambiado a: ");
        SerialBT.println(limite);
        SerialBT.print("\n");
    }
  }

  ///ESTABLECIENDO LOS LIMITES DE LA ALARMA
  if(limite >= 0)
  {
    if (h >= limite)
    {
      digitalWrite(alerta,HIGH);
      SerialBT.println("ALERTA: DEMASIADA HUMEDAD\n");
    }
    else if(t >= limite)
    {
     digitalWrite(alerta,HIGH);
     SerialBT.println("ALERTA: TEMPERATURA ALTA\n");
    }
    else
    {
      digitalWrite(alerta,LOW);
      SerialBT.println("TODO BIEN...\n");
    }
  }
  else
  {
    SerialBT.println("EL LIMITE NO ES REAL");
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
