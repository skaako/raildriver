/*
Custom Hardware for use with Train Sim World 2 using my custom pieHid64.dll
By Skaako (Michael Huggins 2021)
*/

//int analogPin0 = A0; // potentiometer wiper (middle terminal) connected to analog pin
int analogPin1 = A1;
//int analogPin2 = A2;  // Uncomment as needed. I was testing only a few channels at a time
//int analogPin3 = A3;
//int analogPin4 = A4;
//int analogPin5 = A5;

int val[7] = {0}; // variable to store the value read

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}


void loop() {
  
  //val[0] = analogRead(analogPin0);
  val[0] = map(val[0], 0, 388, 1, 64);    // I had to remap for how my pot was setup
  val[0] = val[0] * 4;                    // Was trying to reduce number of steps here
  if (val[0] == 256){val[0] = 254;}

  delay(10);
  
  val[1] = analogRead(analogPin1);
  val[1] = map(val[1], 0, 388, 1, 64);
  val[1] = val[1] * 4;
  if (val[1] == 256){val[1] = 254;}

  delay(10);
  
  //val[2] = analogRead(analogPin2);
  val[2] = map(val[2], 0, 388, 1, 64);
  val[2] = val[2] * 4;
  if (val[2] == 256){val[2] = 254;}

  delay(10);
  
  //val[3] = analogRead(analogPin3);
  val[3] = map(val[3], 0, 388, 1, 64);
  val[3] = val[3] * 4;
  if (val[3] == 256){val[3] = 254;}

  delay(10);
  
  //val[4] = analogRead(analogPin4);
  val[4] = map(val[4], 0, 388, 1, 64);
  val[4] = val[4] * 4;
  if (val[4] == 256){val[4] = 254;}
  
  delay(10);
  
  //val[5] = analogRead(analogPin5);
  val[5] = map(val[5], 0, 388, 1, 64);
  val[5] = val[5] * 4;
  if (val[5] == 256){val[5] = 254;}

  delay(10);
  
  // If you require all 7 analog channels you will need to add in the extra one here

  // Start of string output
  Serial.print("Output: ");
  
  // Padding for numbers
  for(int i = 0; i < 7; i++){
    if(val[i] < 10){
      Serial.print("  ");
    } else if(val[i] < 100){
      Serial.print(" ");
    }
    Serial.print(val[i]);
    Serial.print(" ");
  }
  Serial.println("");
  
  
}
