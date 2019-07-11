
int AnalogInput1 = A0; // Connect to sensors analog output (sensor AO pin > Arduino pin A0)
int AnalogInput2 = A1; //Connect to sensors analog output (sensor AO pin > Arduino pin A1)
float AnalogValue1 =  0;  // Store analog value mic 1
float AnalogValue2 =  0; // Store analog value mic 2
int printvalue1; // integer value to have rounded numbers
int printvalue2; // integer value to have rounded numbers
int Vibra1 = 9; // integer value to adress output pin 9
int Vibra2 = 10; // integer value to adress output pin 10
int ledPin  =  13;   // Connect to internal LED  (Arduino pin 13) debug purpose
int Ref1 = 0; // create a reference value to compare
int Ref2 = 0; // create a reference value to compare
int PotPin = A3; // input pin for potmeter
int PotValue = 0;


void setup(){
Serial.begin(9600); //default is 9600
pinMode(ledPin,OUTPUT);  // set led pin as OUTPUT for debugging purpose
pinMode (Vibra1,OUTPUT); // Sets pin 9 to output
pinMode (Vibra2,OUTPUT); // Sets pin 10 to output
}

void loop(){
//Analog data
PotValue= (1023-analogRead(PotPin))/100; // create a 1 to 10 integer value and invert value lowest=10, highest=0)
Ref1 = printvalue1 + PotValue; // add margin to int pintvalue for easy calculation later on
Ref2 = printvalue2 + PotValue;
AnalogValue1 =  analogRead(AnalogInput1); //   lees analoge waarde uit van beide mics
AnalogValue2 =  analogRead(AnalogInput2);//  
printvalue1 =(int) AnalogValue1; // zet de analoge decimale float om in een afgeronde integer
printvalue2 =(int) AnalogValue2;

Serial.print("gevoeligheid:");
Serial.print(PotValue);
Serial.print("Mic A:");
Serial.print(printvalue1); // print the values of both mics to serial line for callibration and debug purpose
Serial.print(" ");
Serial.print("Mic B:");
Serial.println(printvalue2);
Serial.print(" ");
Serial.write(27);       // ESC command
Serial.print("[2J");    // clear screen command
Serial.write(27);
Serial.print("[H");     // cursor to home command




if (printvalue1 < Ref1) {} // make sure that mic levels are right to trigger motor ; todo: add validation LED for both mics
else {
  digitalWrite(Vibra1, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(55);
  digitalWrite(Vibra1, LOW);
  digitalWrite(ledPin,LOW);
  delay(55);
  }


if (printvalue2 < Ref2) {}
else {
  digitalWrite(Vibra2, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(55);
  digitalWrite(Vibra2, LOW);
  digitalWrite(ledPin,LOW);
  delay(55);
  }
}

