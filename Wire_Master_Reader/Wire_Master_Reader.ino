/* I2CBus MASTER
 *  Created by Amir Rajabifar 
 */

// including the Wire library 
#include <Wire.h>

// an array to store the received data from device #8 
byte Data[2];

void setup() {
  Wire.begin();                    // join i2c bus (address optional for master)
  Serial.begin(9600);              // starts the erial communication 
}

void loop() {
  Wire.requestFrom(8, 2);          // request 2 bytes from slave device #8

  while (Wire.available()) {       //check if data is available   
    for(byte i = 0; i < 2; i++){
    Data [i] = Wire.read();        // it assigne the data to the array
    Serial.print(Data[i]);         // print the array  
    Serial.print('\t');

/*     
 *      Variabls can be decleard in global scope and can be written to from 
 *      array. 
 *      
 *      RPM = Data[0];
 *      Vol = Data[1];
 *      
 *     So one.... (depending on the application) 
 */
    }
  }
  
  Serial.println();                // Print a new line 

//******************** DO STUFF ********************\\ 
 
}


