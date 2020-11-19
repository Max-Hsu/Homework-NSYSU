#%%
import numpy
import matplotlib.pyplot as plt

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
	
ndarray=numpy.fft.fft(arraylist)
'''
fig, ax = plt.subplots()
ax.plot(41,1) # plotting the spectrum
ax.set_xlabel('Freq (Hz)')
ax.set_ylabel('|Y(freq)|')

plt.show()
'''