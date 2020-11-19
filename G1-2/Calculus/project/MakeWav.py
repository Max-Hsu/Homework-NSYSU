import wave
import os
filename = os.path.abspath(os.path.expanduser(filename))
if not os.path.exists(filename):
	print("File not found.", file=sys.stderr)
	sys.exit(1)
writeFile=wave.open("C:\\Users\\Max-Hsu\\Desktop\\homework\\G1-2\\Calculus\\project\\testify.wav","wb")
writeFile.setnchannels(1)
writeFile.setframerate(44100)
writeFile.setsampwidth(2)
def inverseIntoWav(*inputa):
	for i in np.nditer(inputa, op_flags=['readwrite']):
		change=int(i)
		if change<0:
			change=change+65536
		lastE=change%128
		firstE=change>>8
		#print((firstE).to_bytes(1, byteorder='big'),(lastE).to_bytes(1, byteorder='big'))
		writeFile.writeframes((lastE).to_bytes(1, byteorder='big'))
		writeFile.writeframes((firstE).to_bytes(1, byteorder='big'))
writeFile.close()