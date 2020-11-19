import numpy as np
from scipy import signal

fp = open("Pattern/input1.txt",'r')
c1 = open("lenet_weights/lenet_weight_c1.txt",'r')
pic = []
for i in range(28):
    temp = []
    
    dig = fp.readline()
    temp = dig.split(' ')
    for j in range(28):
        temp[j] = float(temp[j])/255
    pic.append(temp)
    
pic = np.array(pic)
print(pic)

c1k = []
c1w = []
for i in range(6):
    temp = []
    for j in range(25):
        dig = c1.readline()
        temp.append(float(dig))
    dig = c1.readline()
    c1w.append(float(dig))
    c1k.append(temp)
c1k = np.array(c1k)
print(c1k)
#arr2 = np.flipud(np.fliplr(arr2))