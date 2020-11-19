import glob
import math
import os
from DecodeWav import *
from readfile import *
from fft import *
from scipy import signal
import matplotlib.pyplot as plt
noiseData = []
SuitableNoise = []
sN = []
num = 17
filterTable=[0]*(1<<num)
lowerBound = [90,2000,6000]#90,6000
upperBound = [1300,5000,10000]#1300,10000
for l in range(len(lowerBound)):
    lowerBound[l] = round(lowerBound[l]/(44100/(1<<num)))
    upperBound+=[(1<<num)-lowerBound[l]]
for u in range(int(len(upperBound))//2):
    upperBound[u] = round(upperBound[u]/(44100/(1<<num)))
    lowerBound+=[(1<<num)-upperBound[u]]
lowerBound.sort()
upperBound.sort()
expand = 1000
example = [0]*(1<<num)
"""
def impluse():
    for l,u in zip(lowerBound,upperBound):
        for run in range(l,u):
            example[run] = 1
    plt.plot(example)
    #plt.show()

impluse()
"""
def gaussGenerate():
    for l,u in zip(lowerBound,upperBound):
        sig = signal.general_gaussian((u-l)+expand*2 ,sig = (u-l)//2 , p = 3)
        for run in range((u-l)+expand*2):
            cac = run-expand+l
            if(cac >= 0 and cac < 131072):
                filterTable[cac] = sig[run]

gaussGenerate()
plt.plot(filterTable)
plt.show()
print("this is lower",lowerBound)
print("this is higher",upperBound)
def freqFilter(freqTable):
    # 1<<num is sample rate
    # so num is same as fft.py
    global num
    global filterTable
    After_filter = [0]*(1<<num)
    for run in range(1<<num):
        After_filter[run] = filterTable[run] * freqTable[run]
    '''
    plt.plot(freqTable)
    plt.show()
    plt.plot(After_filter)
    plt.show()
    '''
    return After_filter


def readNoiseDataFile():
    # noiseData_* should be a frequence graph, and had been filted
    path = "./noiseTXT_*"
    for fileName in glob.glob(path):
        noiseFile = []
        with open(fileName, "r") as f:
            for line in f:
                noiseFile.append(complex(line[:-1]))
        #noiseFile = freqFilter (noiseFile)
        noiseData.append(noiseFile)


def findSuitableNoise(filtedData, mode=0):
    global SuitableNoise
    '''
    filtedData is the frequency graph which had beed filted by freqFilter
    mode = 0 is abslute
         = 1, 1.4, 2... etc. is power
            (Real number not complex)
    '''
    if mode :
        processFunction = testingPower
    else:
        processFunction = testingAbs
    success, times = processFunction(filtedData, mode)
    print(success,times)
    SuitableNoise = [x * times for x in noiseData[success[1]]]


def subtraction(rawFreqData, mode=0, toFindSuitableNoise=False):
    #filtedData = freqFilter(rawFreqData)
    
    after_sub = []
    
    if toFindSuitableNoise == True:
        findSuitableNoise(rawFreqData, mode)
    for a,b in zip(rawFreqData, SuitableNoise):
        
        x = a-b
        if np.abs(a)-np.abs(b) < 0:
            x = 0
        
        after_sub += [x]
    
    return freqFilter(after_sub)

'''
def getNoiseFileLoopTimes(filename):
    global num
    with open(filename, 'r') as f:
        return math.ceil((len(f.readlines()) - 2) / (1 << num))
'''

def noiseGenerate():
    '''
    the initial noise file name should be raw name at line 44.
    eg: "air_conditioner", "fan", "foot_step" etc.
    '''

    path = "./noiseData_*"
    for fileName in glob.glob(path):
        fileName=fileName[2:]
        print(glob.glob(path))
        offset = 0
        nchannel, loopTotalTimes = decodewav(str(fileName))
        loopTotalTimes/=(1<<num)
        if(nchannel == 1):
            outputNoiseData = [0+0j]*(1<<num)
            outputFile = open("noiseTXT_" + fileName[:-3] + "txt", 'w')
        
            while offset >= 0:
                offset, noiseSubList = readfile("unichannel", offset)
                noiseSubList = fft_T(noiseSubList)
                filtedNoiseSubData = freqFilter(noiseSubList)
                for i in range(1<<num):
                    outputNoiseData[i] += filtedNoiseSubData[i]/loopTotalTimes


            for x in outputNoiseData:
                outputFile.write(str(x)+'\n')
            outputFile.close()
                
        elif(nchannel == 2):
            outputNoiseDataL = [0+0j]*(1<<num)
            outputLeft = open("noiseTXT_" + fileName[:-3] + "txt", 'w')
                
            while offset >= 0:
                offset, noiseSubListL = readfile("leftchannel", offset)
                noiseSubListL = fft_T(noiseSubListL)
                filtedNoiseSubDataL = freqFilter(noiseSubListL)

                for i in range(1<<num):
                    outputNoiseDataL[i] += filtedNoiseSubDataL[i]/loopTotalTimes
            
            for x in outputNoiseDataL:
                outputLeft.write(str(x)+'\n')
            outputLeft.close()
        os.rename(fileName,"X"+fileName)


def generateSN():
    for i in range(len(noiseData)):
        summation = sum(noiseData[i])
        sN.append(abs(summation))


def testingAbs(rawData, mode):
    rawDataSum = 0
    result = []

    rawDataSum = sum(rawData)
    for i in range(len(noiseData)):
        subtract = 0
        #print(len(noiseData[i]))
        #print(len(rawData))
        for j in range(len(noiseData[i])):
            tmp = noiseData[i][j] * (rawDataSum / sN[i])
            subtract += abs(rawData[j] - tmp)
        result.append((subtract, i))

    bestNoise = min(result)
    return bestNoise, abs(rawDataSum) / sN[bestNoise[1]]


def testingPower(rawData, power):
    rawDataSum = 0
    result = []
    for low, high in zip(lowerBound, upperBound):
        rawDataSum = sum(rawData[low:high + 1])

    for i in range(len(noiseData)):
        subtract = 0
        for j in range(len(noiseData[i])):
            tmp = noiseData[i][j] * (rawDataSum / sN[i])
            subtract += (rawData[j] - tmp)**power
        result.append((subtract, i))

    bestNoise = min(result)
    return bestNoise, abs(rawDataSum) / sN[bestNoise[1]]

#readNoiseDataFile()
#generateSN()

