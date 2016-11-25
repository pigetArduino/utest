//Example of Universal device
//This code 
//utest: github.com/pigetArduino/utest
//uled : github.com/pigetArduino/uled


const String usb_name = "UTest";

//Serial string buffer
String readString;

// Serial

//When application asked if this is the correct arduino
void serialCheck(){
    if (readString == usb_name) {
      Serial.print("OK");
   }
}

//Convert characters sent by serial to string
void serialManager(){
    //Get Serial as a string
  while (Serial.available()) {
    delay(3); // Wait for data

    //Convert to String
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }
}

void setup() {
  //Setup Serial
  Serial.begin(115200);
}

void loop() {
  serialManager();

  //If string received
     if (readString.length() > 0) {
      serialCheck();
      //Serial.println(readString);
      if (readString == "ON"){
        digitalWrite(13,1);
      }
      if (readString == "OFF"){
        digitalWrite(13,0);
      }
      
    }

  //We clean the serial buffer
  readString = "";
}
