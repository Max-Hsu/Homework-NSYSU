#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
Notebook for streaming data from a microphone in realtime

audio is captured using pyaudio
then converted from binary data to ints using struct
then displayed using matplotlib

scipy.fftpack computes the FFT

if you don't have pyaudio, then run

>>> pip install pyaudio

note: with 2048 samples per chunk, I'm getting 20FPS
when also running the spectrum, its about 15FPS
"""

import pyaudio
import os
import struct
import numpy as np
import matplotlib.pyplot as plt
from scipy.fftpack import fft
import time
from tkinter import TclError

# to display in separate Tk window
get_ipython().run_line_magic('matplotlib', 'tk')

# constants
CHUNK = 100           # samples per frame
FORMAT = pyaudio.paInt16     # audio format (bytes per sample?)
CHANNELS = 1                 # single channel for microphone
RATE = 44100                 # samples per second

arraylist=[]
fileuni = open("C:\\Users\\Max-Hsu\\Desktop\\homework\\G1-2\\Calculus\\project\\unichannel")
fileuni.readline()
fileuni.readline()
while True:
	getnum=fileuni.readline()
	if(getnum == ""):
		break
	getnum=getnum[:-1]
	arraylist+=[int(getnum)]


# create matplotlib figure and axes
fig, (ax1, ax2) = plt.subplots(2, figsize=(15, 7))

'''
# pyaudio class instance
p = pyaudio.PyAudio()

# stream object to get data from microphone
stream = p.open(
    format=FORMAT,
    channels=CHANNELS,
    rate=RATE,
    input=True,
    output=True,
    frames_per_buffer=CHUNK
)
'''
# variable for plotting
x = np.arange(0,CHUNK, 1)       # samples (waveform)
xf = np.linspace(0, RATE, CHUNK)     # frequencies (spectrum)

# create a line object with random data
line, = ax1.plot(x, np.random.rand(CHUNK), '-', lw=1)


line_fft, = ax2.plot(xf, np.random.rand(CHUNK), '-', lw=1)

# format waveform axes
ax1.set_title('AUDIO WAVEFORM')
ax1.set_xlabel('samples')
ax1.set_ylabel('volume')
ax1.set_ylim(0, 65536)
ax1.set_xlim(0, CHUNK)
plt.setp(ax1, xticks=[0, CHUNK], yticks=[0, 32768, 65536])

# format spectrum axes
ax2.set_xlim(20, RATE / 2)

print('stream started')

position = 0
while True:
    
    data_int = arraylist[position:position+CHUNK]
    #print(data_int,len(data_int),"data_int\n\n")
    # create np array and offset by 128
    data_np = np.array(data_int)+32768
    #print(data_np,len(data_np))
    line.set_ydata(data_np)
    
    # compute FFT and update line
    yf = fft(data_int)
    #print(len(yf))
    line_fft.set_ydata(np.abs(yf[0:CHUNK])  / (32768 * CHUNK))
    position+=CHUNK
    # update figure canvas
    try:
        fig.canvas.draw()
        fig.canvas.flush_events()
 
        
    except TclError:
        
        # calculate average frame rate
        print('stream stopped')
        break


# In[ ]:





# In[ ]:




