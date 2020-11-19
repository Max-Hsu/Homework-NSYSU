
import numpy


arraylist=[]
fileuni = open("c:/Users/Max-Hsu/Desktop/homework/G1-2/Calculus/project/unichannel")
fileuni.readline()
fileuni.readline()
while True:
	getnum=fileuni.readline()
	if(getnum == ""):
		break
	getnum=getnum[:-1]
	arraylist+=[int(getnum)]
	
ndarray=numpy.fft.fft(arraylist)
print(len(ndarray))