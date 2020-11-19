import wave
import matplotlib.pyplot as plt
import numpy as np
import os
import sys
filename = ""
def decodewav(filename):
    filename = os.path.abspath(os.path.expanduser(filename))
    if not os.path.exists(filename):
        print("File not found.", file=sys.stderr)
        sys.exit(1)
    f = wave.open(filename, 'rb')
    params = f.getparams()
    nchannels, sampwidth, framerate, nframes = params[:4]
    strData = f.readframes(nframes)
    waveData = np.fromstring(strData,dtype=np.int16)

# plot the wave
    if nchannels == 1:
        fileuni = open("unichannel",'w')
        fileuni.write("channel:"+str(nchannels)+'\n')
        fileuni.write("sampleRate:"+str(framerate)+'\n')
        for i in np.nditer(waveData):
            fileuni.write(str(i))
            fileuni.write("\n")
        fileuni.close()
    elif nchannels == 2:
        L_file = open("leftchannel",'w')
        R_file = open("rightchannel",'w')
        L_file.write("channel:"+str(nchannels)+'\n')
        L_file.write("sampleRate:"+str(framerate)+'\n')
        R_file.write("channel:"+str(nchannels)+'\n')
        R_file.write("sampleRate:"+str(framerate)+'\n')
        iterOfWaveData = np.nditer(waveData)
        for l in iterOfWaveData:
            L_file.write(str(l))
            L_file.write("\n")
            r=next(iterOfWaveData)
            R_file.write(str(r))
            R_file.write("\n")
        L_file.close()
        R_file.close()

    return nchannels,nframes
