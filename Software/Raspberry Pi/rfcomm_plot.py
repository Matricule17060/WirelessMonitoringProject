#!/usr/bin/env python

import time
import serial
import matplotlib.pyplot as plt
from copy import deepcopy as dcp

ser = serial.Serial(
    #port='/dev/ttyUSB0',
	port='/dev/rfcomm0',
    baudrate = 115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)


t , pulse , oxymetry =  [],[],[]

plt.ion() # animation mode



nb_points = 100

for i in range(nb_points):
    t.append(i)
    
    str_input = ser.readline().decode("utf-8").strip().split(" , ")
    if str_input[0] != "": # transmission error
        int_input = [float(str_input[i]) for i in range(len(str_input))]
        #print(str_input)
    
    print("pulse : {} , oxymetry : {} \n".format(int_input[0],int_input[1]))
    pulse.append(int_input[0])
    oxymetry.append(int_input[1])
    
    plt.figure(10)
    plt.title("Pulsation cardiaque en fonction du temps")
    plt.xlabel("Temps [sec]")
    plt.ylabel("Frequence [bpm]")
    plt.xlim((0 , nb_points))
    plt.ylim((0 , 120))
    plt.plot(t,pulse , "b")

    
    plt.figure(11)
    plt.title("Saturation en oxygene en fonction du temps")
    plt.xlabel("Temps [sec]")
    plt.ylabel("Saturation [%]")
    plt.xlim((0 , nb_points))
    plt.ylim((0 , 120))
    plt.plot(t,oxymetry,"r")
    
    plt.draw()
    plt.pause(1)

    
    
     
        
