num = 17
from fft import *
from DecodeWav import *
from reduceNoise import *
from readfile import *
import numpy as np
noiseGenerate()
readNoiseDataFile()

generateSN()

filename = input("Please input the process Wave file:")
nchannel,nframes=decodewav(filename)
from EncodeWav import *
writeFile.setnchannels(nchannel)


continueComputeSuitableNoise = input("Does this sound file contain a lot of noise?(y/n)")
if continueComputeSuitableNoise == 'y':
    continueComputeSuitableNoise = True
else:
    continueComputeSuitableNoise = False

findMode = eval(input("Use Absolute or Power to find suitable noise? \n\tinput==0 is using absolute,\n\t input>0 is using power of input.\n:"))




isFirstTime = True
if nchannel == 1:
    pos = 0
    while(pos >= 0):
        pos,rawWav = readfile("unichannel", pos)
        rawFileFreq = fft_T(rawWav)
    
        if isFirstTime:
            findSuitableNoise(rawFileFreq, findMode)
            isFirstTime = False

        After_Sub_FFT = subtraction(rawFileFreq, findMode, continueComputeSuitableNoise)
        Inverse_FFT = ifft_T(After_Sub_FFT)
        inverseIntoWav(Inverse_FFT)
elif nchannel == 2:
    lpos = 0
    rpos = 0
    while(lpos >= 0 and rpos >=0 ):
        lpos,L_rawWav = readfile("leftchannel", lpos)
        rpos,R_rawWav = readfile("rightchannel",rpos)
        L_rawFileFreq = fft_T(L_rawWav)
        R_rawFileFreq = fft_T(R_rawWav)

        if isFirstTime:
            findSuitableNoise(L_rawFileFreq, findMode)
            isFirstTime = False

        L_After_Sub_FFT = subtraction(L_rawFileFreq, findMode, continueComputeSuitableNoise)
        R_After_Sub_FFT = subtraction(R_rawFileFreq, findMode, continueComputeSuitableNoise)
        
        
        L_Inverse_FFT = ifft_T(L_After_Sub_FFT)
        R_Inverse_FFT = ifft_T(R_After_Sub_FFT)
        
        #L_Inverse_FFT = np.fft.ifft(L_After_Sub_FFT)
        #R_Inverse_FFT = np.fft.ifft(R_After_Sub_FFT)

        inverseIntoWav(L_Inverse_FFT,R_Inverse_FFT)

writeFile.close() # this is the output wave


