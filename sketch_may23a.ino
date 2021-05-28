
// NRF24L01 Module Tutorial - Code for Receiver using Arduino UNO

//Include needed Libraries at beginning
#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"
#include "FastLED.h" // FastLED library for WS2812 RGB Stick http://fastled.io/

// #define NUM_LEDS 8 // Number of leds on stick
// #define LED_PIN 8 // Digital In (DI) of RGB Stick connected to pin 8 of the UNO

const int pinBuz = 8; 


// CRGB leds[NUM_LEDS]; // FastLED Library Init

int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01

RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the UNO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(void){

 Serial.begin(9600); // Opens Serial communication
 pinMode(pinBuz,OUTPUT); //Defines pinBuz as an Output



radio.begin(); // Start the NRF24L01

radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive

radio.startListening(); // Listen to see if information received

}

void loop(void){

while (radio.available())
{
radio.read(ReceivedMessage, 1); // Read information from the NRF24L01

if (ReceivedMessage[0] == 111) // Indicates switch is pressed
{
digitalWrite(pinBuz,1); //Switch pressed, buzzer on
  }
  else
  {
   digitalWrite(pinBuz,0);
  }
  delay(10);
}
}
