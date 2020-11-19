#!/usr/bin/env python
# coding: utf-8

# In[17]:


import wave
import matplotlib.pyplot as plt
import numpy as np
import os
import sys
def decodewav(filename):
    filename = os.path.abspath(os.path.expanduser(filename))
    if not os.path.exists(filename):
        print("File not found.", file=sys.stderr)
        sys.exit(1)
    f = wave.open(filename,'rb')
    params = f.getparams()
    nchannels, sampwidth, framerate, nframes = params[:4]
    strData = f.readframes(nframes)#讀取音訊，字串格式
    waveData = np.fromstring(strData,dtype=np.int16)#將字串轉化為int

# plot the wave
    fileuni = open("unichannel",'w')
    fileuni.write("channel:"+str(nchannels)+'\n')
    fileuni.write("sampleRate:"+str(framerate)+'\n')
    for i in np.nditer(waveData):
        fileuni.write(str(i))
        fileuni.write("\n")
    fileuni.close()

