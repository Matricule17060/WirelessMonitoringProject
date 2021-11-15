import pyserial
import numpy as np
import matplotlib.pyplot as plt
from drawnow import *

pressure = []
ser = serial.Serial('com11' , 115200)
plt.ion() # interactive mode to plot live data
cnt = 0

def makeFig():
    plt.ylim(800000,900000)
    plt.title('Pression en fonction du temps')
    plt.grid(True)
    plt.xlabel("Temps [sec]")
    plt.ylabel('Pression [Pa]')
    plt.plot(pressure , 'b')


while True:
    while ser.inWaiting() == 0: # attend temps qu'il n'y a pas de données 
        pass
    
    data = float(ser.readline())
    pressure.append(data)
    drawnow(makeFig)
    plt.pause(.00001)
    cnt = cnt + 1
    if cnt > 50:
        pressure.pop(0)


