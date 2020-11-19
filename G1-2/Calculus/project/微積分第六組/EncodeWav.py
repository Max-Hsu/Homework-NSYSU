import wave
import os
import sys
import numpy as np
filenameToOutput = input("Please input the output file name:")
filenameToOutput=filenameToOutput+".wav"
filenameToOutput = os.path.abspath(os.path.expanduser(filenameToOutput))
if os.path.exists(filenameToOutput):
	print("File is here.", file=sys.stderr)
	sys.exit(1)
writeFile=wave.open(filenameToOutput,"wb")

writeFile.setframerate(44100)
writeFile.setsampwidth(2)
def inverseIntoWav(inputa):
	for i in inputa:
		change=int(i)
		if change<0:
			change=change+65536
		lastE=change%128
		firstE=change>>8
		#print((firstE).to_bytes(1, byteorder='big'),(lastE).to_bytes(1, byteorder='big'))
		writeFile.writeframes((lastE).to_bytes(1, byteorder='big'))
		writeFile.writeframes((firstE).to_bytes(1, byteorder='big'))
def inverseIntoWav(L_IFFT,R_IFFT):
	for l,r in zip(L_IFFT,R_IFFT):
		change=int(l)
		if change<0:
			change=change+65536
		lastE=change%128
		firstE=change>>8
		#print((firstE).to_bytes(1, byteorder='big'),(lastE).to_bytes(1, byteorder='big'))
		try:
			writeFile.writeframes((lastE).to_bytes(1, byteorder='big'))
			writeFile.writeframes((firstE).to_bytes(1, byteorder='big'))
		except:
			print(change)
		change=int(r)
		if change<0:
			change=change+65536
		lastE=change%128
		firstE=change>>8
		#print((firstE).to_bytes(1, byteorder='big'),(lastE).to_bytes(1, byteorder='big'))
		try:
			writeFile.writeframes((lastE).to_bytes(1, byteorder='big'))
			writeFile.writeframes((firstE).to_bytes(1, byteorder='big'))
		except:
			print(change)
#writeFile.close()
