UTest
-------------------
![UTestpython app](https://github.com/pigetArduino/utest/raw/master/doc/utestapp.png)
* Download link: utestapp.madnerd.org
* Download arduino code : utest.madnerd.org
* Download arduino nano drivers : nano.madnerd.org

Utest is a test application that will turn on/off a led on an arduino nano clone   

This is a *python* application make with *tkinter* to use arduino as reliable usb devices.
This application use a python module that will manage the arduino so you can focus on   
Features:
* Autodetect correct port (even if you change serial port by plugging your arduino on another port)
* Reconnect automatically when a messsage isn't received correctly
* Complete abstraction of the arduino detection/serial communication.
Using this python module, you can plugged as much arduino nano you want and control them seperately   
For now message reception is not managed but it should be easy to add

# Issues
This application won't works on Windows 7 if it wasn't properly updated, since you will need Universal C Runtime.   
If you run into any issues, please advice me, I want to make the application as simple to install as possible.
* You will need this update: https://support.microsoft.com/en-gb/kb/2999226
* Source: http://stackoverflow.com/questions/34218333/pyinstaller-onefile-does-not-start-on-some-windows-7-machines

# Build it yourself!

## Download
* Download python 3 : https://www.python.org/downloads/
* You need to add python in your PATH during install!

## Dependencies
We need tkinter (bundled with python) and pySerial
* Open a command prompt (Windows Key + cmd)
```
pip install pyserial
```

## Start application
* Open a command prompt (Windows Key + cmd)
* Go to the folder of the application 
* Type:
```
python utest.py
```

# Compile
You will need pyinstaller to create an executable   

```
pip install pyinstaller
```
You can use compile.bat or 
```
pyinstaller --onefile --noconsole utest.py 
```
If you want to debug the application
```
pyinstaller --onefile utest.py 
```

# How to use the library
Check the source code (for the arduino/python app) for more information    
There is only two commands, since the arduino detection is managed in a seperated thread   
You need to have a loop in the main thread   

Connect to your arduino
```
device_name = "CH340" #Device name
device_type = "UTest" #Device type as defined in the arduino code
device_return_string = "OK" #Return string
device_baudrate = 115200 #Baudrate
usb = USB.Device(device_name,device_type,device_return_string,device_baudrate)
```

Send a string to the arduino
```
usb.write("ON")
```

# USB Module
In the source of this application, there is a module that can be easily reuse to communicate with arduino
* You need to copy the lib folder into your application   
Arduino must send OK when the device_type command is sent   
This allow us to be sure we are communicating with the correct arduino   




# Licences
Icon by jpapun
Creative Commons Attribution (by)
Link : http://findicons.com/icon/158595/device_and_hardware

Software by Rémi Sarrailh (madnerd.org)
Licence: MIT
