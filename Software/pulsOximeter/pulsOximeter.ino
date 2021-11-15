// esp32 and max30100 and Raspberry pi for bluetooth


#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "BluetoothSerial.h"

 
#define REPORTING_PERIOD_MS 1000
 
BluetoothSerial SerialBT;

// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
 
 
void onBeatDetected()
{
    //SerialBT.println("Beat Detected!");
}

 
void setup()
{
    SerialBT.begin("ESP32 dev module");
    
    pinMode(19, OUTPUT);
    
 
    SerialBT.println("Initializing Pulse Oximeter..");
 
    if (!pox.begin())
    {
         SerialBT.println("FAILED");
         for(;;);
    }
    else
    {
         SerialBT.println("SUCCESS");
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
        pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
}
 
void loop()
{ 

    pox.update();
 
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {

        SerialBT.print(BPM);SerialBT.print(" , "); SerialBT.println(SpO2);
 
        tsLastReport = millis();
    }
}
