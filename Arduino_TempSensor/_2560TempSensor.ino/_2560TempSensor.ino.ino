/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
String CommandString = "f#1= ";
String TempString = "";
char EndOfLine[]={13,10};
String OutputString = "";

void setup() {
  Serial.begin(9600);
    
  mlx.begin();  
}

void loop() {

  TempString = String(mlx.readObjectTempF());
  OutputString = CommandString + TempString;
  /**
  An Example of how to send out a string one character at a time should it be necessary
  
  OutputString = OutputString+'\r'+'\n';

  int StrLength = OutputString.length()+1;
  int i;
  char charBuf[StrLength];
  OutputString.toCharArray(charBuf,StrLength);
  Serial.println(StrLength);
  for (i=0; i<StrLength; i++){

    Serial.write(OutputString[i]);
    
  }
  **/
  Serial.println(OutputString);
  /**
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
 
  Serial.println();
   **/
   
  delay(500);
}
