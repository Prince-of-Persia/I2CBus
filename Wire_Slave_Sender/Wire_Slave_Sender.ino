/* I2CBus SLAVE (#8)
 *  Created by Amir Rajabifar 
 */
 
// including the Wire library 
#include <Wire.h>

// variable to store the reading from sensors
int pot1;
int pot2;

// an array to store the data that need to be sent
byte data[2]; 

void setup() {
  Serial.begin(9600);           // Begin Serial coomunication 
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
// Read from the sensors and assign to variables  
  pot1 = analogRead(A0);
  pot2 = analogRead(A1);
// more sensors can be added
// change a 10 bit number to 8 bit  
  pot1 /= 4;
  pot2 /= 4;

// Write the value of variables to the array
  data[0] = pot1;
  data[1] = pot2;

//Print the array to Serial buffer (for debuging) 
  for (int i = 0; i < 2; i++){
    Serial.print(data[i]); 
    Serial.print('\t');
  }
  Serial.println();
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
// respond with message of 2 bytes as expected by master
  Wire.write(data, 2);
}

