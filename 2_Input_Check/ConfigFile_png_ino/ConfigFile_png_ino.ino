
/*
  DigitalReadSerial
  Reads a digital input on pin 2, prints the result to the serial monitor

  This example code is in the public domain.
*/


// digital pin 37 is used for the gate interlock. Give it a name:
// digital pin 38 is used for the pushbutton.  Give it a name:

int GateInterLock = 37;
int GateInterlockState = 0;
boolean GateLocked = false;
String GateString = "";

int PushButton = 36;
int PushButtonState = 0;
boolean ButtonPushed = false;
String PushButtonString = "";

String Output = "";

unsigned long GateStartTime = 0;
const long interval = 1000;
unsigned long PushButtonStartTime = 0;

// the setup routine runs once when you press reset:
void setup() {
  // Serial3 is for the USB connection, Serial is used for the local serial port.
  // initialize serial communication at 9600 bits per second:
  Serial3.begin(9600);
  
  // make the Gate Interlock pin an input:
  pinMode(GateInterLock, INPUT_PULLUP);
  pinMode(PushButton, INPUT_PULLUP);
  
}



// the loop routine runs over and over again forever:
void loop() {


  String content = "";
  char character;


  while (Serial3.available()) {
    character = Serial3.read();
    content.concat(character);
  }

    unsigned long CurrentTime = millis();
    // read the input pins only when prompted:
    int GateInterlockState = digitalRead(GateInterLock);
    if (GateInterlockState == 0)
    {
      // If the gate is locked
      GateStartTime = CurrentTime; 
      GateLocked = true;
    }
  
    PushButtonState = digitalRead(PushButton);

    if (PushButtonState == 0)
    {
      PushButtonStartTime = CurrentTime;
      ButtonPushed = true;
    }
  

  if (content.indexOf("T") >= 0)
  {
    
    if (CurrentTime - GateStartTime <= interval)
    {
      //Serial3.println("Y");
      GateString="1";
      
    }
    else
    {
      //Serial3.println("N");
      GateString="0";
      GateLocked=false;
    }
    if (CurrentTime - PushButtonStartTime <= interval)
    {
      PushButtonString="1";
      
    }
    else
    {
      PushButtonString="0";
      ButtonPushed = false;
    }
  
  Output=GateString+PushButtonString;
  Serial3.println(Output);
   
  }
  
}
