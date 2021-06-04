#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

char result;
const int der = 2;   
const int iz = 4;    
const int rec = 16;  
const int fw = 17;   
const int bw = 5;    
const int id = 18;  

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Camion wannabe");
  Serial.println("Let's get the party started shall we?");
  pinMode ( der , OUTPUT );
  pinMode ( iz , OUTPUT );
  pinMode ( rec , OUTPUT );
  pinMode ( fw , OUTPUT );
  pinMode ( bw , OUTPUT );
  pinMode ( id , OUTPUT );
}

void loop() {
  if ( SerialBT.available() ) {
    result = SerialBT.read();
    Serial.println(result);
    switch ( result ){
      case 'F':
        digitalWrite(fw, true);
        Serial.println("palante");
        delay(20);
        break;
      case 'B':
        digitalWrite(bw, true);
        Serial.println("patra");
        delay(20);
        break;
      case 'S':
        digitalWrite(id, true);
        Serial.println("quietol");
        delay(20);
        break;
      case 'D':
        digitalWrite(der, true);
        Serial.println("Derecha");
        delay(20);
        break;
      case 'I':
        digitalWrite(iz, true);
        Serial.println("Izquierda");
        delay(20);
        break;
      case 'R':
        digitalWrite(rec, true);
        Serial.println("sometimes, going right is not right");
        delay(20);
        break;
    }
  digitalWrite(fw, false);
  digitalWrite(bw, false);
  digitalWrite(id, false);
  digitalWrite(der, false);
  digitalWrite(iz, false);
  digitalWrite(rec, false);
 }
}
