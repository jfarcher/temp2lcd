#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// DS18b2 is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;

void setup(void)
{
  lcd.begin(16, 2);
  sensors.begin();
  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
  sensors.setResolution(insideThermometer, 9);
 }

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  lcd.print("Temp C: ");
  lcd.print(tempC);
  //comment the next line out or decrease the value for faster response
  delay(1000);
}

void loop(void)
{ 
  lcd.setCursor(0, 0);
  sensors.requestTemperatures(); 
  printTemperature(insideThermometer); 
}

