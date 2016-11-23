#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Example application for Universal Led 
# Doc : http://github.com/pigetArduino/UniversalLed
# Author : Rémi Sarrailh (madnerd.org)
# Licence : MIT

# Arduino communication is completely managed by arduino module
# If connection is lost it will try to reconnect
from lib import USB
from tkinter import *

device_name = "CH340"
device_type = "UTest"
device_return_string = "OK"
device_baudrate = 115200

def on():
	print("on")
	usb.write("ON")

def off():
	print("off")
	usb.write("OFF")

root = Tk()
Button(text="on",command=on).pack()
Button(text="off",command=off).pack()
status = Label(text="Searching...")
status.pack()

usb = USB.Device(device_name,device_type,device_return_string,device_baudrate,status)

root.mainloop()
