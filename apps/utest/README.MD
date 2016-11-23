Universal Led Test
-------------------
![ULed python app](https://github.com/pigetArduino/universalLed/raw/master/doc/ul_app.png)
Download link: uledapp.madnerd.org

Ul is a test application for UniversalLed : https://github.com/pigetArduino/   
This is a *python* application make with *tkinter* to use arduino as reliable usb devices.
This application use a python module that will manage the arduino so you won't have to worry about it   
Features:
* Autodetect correct port (even if you change serial port by plugging your arduino on another port)
* Reconnect automatically when a messsage isn't received correctly
* Complete abstraction of the arduino detection/serial communication.

This is a good example to autodetect specific arduino (this was tested with multiples serial devices/arduino plugged)
There are still a lot of room for improvements   

Next version will implement 
* websocket
* pixel detection for custom HUD in games
* file modification trigger (share leds as file using samba/windows share)
* Whatever you want!
* Better ui (tkinter will probably be deprecated since it is way too limited)

# Issues
This application won't works on Windows 7 if it wasn't properly updated, since you will need Universal C Runtime.   
If you run into any issues, please advice me, I want to make the application as simple to install as possible.
* You will need this update: https://support.microsoft.com/en-gb/kb/2999226
* Source: http://stackoverflow.com/questions/34218333/pyinstaller-onefile-does-not-start-on-some-windows-7-machines

# Build it yourself!

# Download
* Download python 3 : https://www.python.org/downloads/
* You need to add python in your PATH during install!

# Dependencies
We need tkinter (bundled with python) and pySerial
* Open a command prompt (Windows Key + cmd)
```
pip install pyserial
```

# Start application
* Open a command prompt (Windows Key + cmd)
* Go to the folder of the application 
* Type:
```
python ul.py
```

# Compile
You will need pyinstaller to create an executable   
Don't forget to add the icon file with it in /dist   

```
pip install pyinstaller
```
You can use compile.bat or 
```
pyinstaller --onefile --noconsole --icon=ul.ico ul.py 
```
If you want to debug the application
```
pyinstaller --onefile ul.py 
```

# USB Module
In the source of this application, there is a module that can be easily reuse to communicate with arduino
* You need to copy the lib folder into your application
Arduino must send OK when the device_type command is sent   
This allow us to be sure we are communicating with the correct arduino   
```
from lib import USB
device_name = "CH340"
device_type = "ULed"
device_return_string = "OK"
device_baudrate = 115200
usb = USB.Device(device_name,device_type,device_return_string,device_baudrate,status)
```

```
const String usb_name = "ULed";
void setup() {
  //Setup Serial
  Serial.begin(115200);
}

void loop() {
  //Get Serial as a string
  while (Serial.available()) {
    delay(3); // Wait for data

    //If data is received we convert it as a string for easier usage
    //Of course this isn't optimize but this is easier to modify the code
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }

  //If string received
  if (readString.length() > 0) {
    //If device type is sent return OK
    if (readString == usb_name) {
      Serial.print("OK");
    } else {
      	//
	Serial.println(readString);
    }
  }
  //We clean the serial buffer
  readString = "";
}

```



# Licences
Icon by jpapun
Creative Commons Attribution (by)
Link : http://findicons.com/icon/158595/device_and_hardware

Software by Rémi Sarrailh (madnerd.org)
Licence: MIT
