// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include "./src/libraries/Alt_MCP23008/Alt_MCP23008.h"

Alt_MCP23008 mcp_0;
Alt_MCP23008 mcp_1;

#define I2Caddr_sol1_8  0x0
#define I2Caddr_sol9_16 0x1

void setup() {
  Serial.begin(115200);
  mcp_0.begin(I2Caddr_sol1_8);
  mcp_1.begin(I2Caddr_sol9_16);

  for (int i = 0; i < 8; i++) {
    mcp_0.pinMode(i, OUTPUT);
    mcp_1.pinMode(i, OUTPUT);
  }
}

byte x = 0;

uint16_t newState = 0;

void loop() {
  newState = 65535;
  mcp_0.writeGPIO(lowByte(newState));
  mcp_1.writeGPIO(highByte(newState));
//
//    Wire.beginTransmission(I2Caddr_sol1_8 | 0x20);
//    Wire.write(lowByte(newState));
//    Wire.endTransmission();
//    Wire.beginTransmission(I2Caddr_sol9_16 | 0x20);
//    Wire.write(highByte(newState));
//    Wire.endTransmission();
    
  Serial.println("HIGH");
  delay(1000);
  newState = 0;
  mcp_0.writeGPIO(lowByte(newState));
  mcp_1.writeGPIO(highByte(newState));

//    Wire.beginTransmission(I2Caddr_sol1_8 | 0x20);
//    Wire.write(lowByte(newState));
//    Wire.endTransmission();
//    Wire.beginTransmission(I2Caddr_sol9_16 | 0x20);
//    Wire.write(highByte(newState));
//    Wire.endTransmission();
    
  Serial.println("LOW");
  delay(1000);
}
