import sys
import os
import wave

#filename = sys.argv[1]
def decodewav(filename):
	filename = os.path.abspath(os.path.expanduser(filename))
	if not os.path.exists(filename):
		print("File not found.", file=sys.stderr)
		sys.exit(1)
	getpara = wave.open(filename,'rb')
	channel = getpara.getnchannels()
	print("channel",channel)
	print("sampleRate",getpara.getframerate())
	getpara.close()
	counter=0
	toOuput=False
	with open(filename, "rb") as f:
		if(channel==1):
			fileuni = open("unichannel",'w')
			fileuni.write("channel:"+str(channel)+'\n')
			fileuni.write("sampleRate:"+str(getpara.getframerate())+'\n')
			byte1 = f.read(1)
			byte2 = f.read(1)
			while (byte1 != b""):
				counter+=1
				if(counter>22):
					counter=22
					toOuput=True
				#os.write(1,byte)
				ans1=ord(byte1)<< 8
				ans2=ord(byte2)
				ans=ans1+ans2
				if(ans>=32768):
					ans-=65536
				if(toOuput):
					fileuni.write(str(ans)+'\n')
					#print(ans)
				
				# Do stuff with byte.
				byte1 = f.read(1)
				byte2 = f.read(1)
			fileuni.close()
		elif(channel==2):
			filel = open("leftchannel",'w')
			filer = open("rightchannel",'w')
			filel.write("channel:"+str(channel)+'\n')
			filer.write("channel:"+str(channel)+'\n')
			filel.write("sampleRate:"+str(getpara.getframerate())+'\n')
			filer.write("sampleRate:"+str(getpara.getframerate())+'\n')
			byte1 = f.read(1)
			byte2 = f.read(1)
			byte3 = f.read(1)
			byte4 = f.read(1)
			while (byte1 != b""):
				counter+=1
				if(counter>11):
					counter=11
					toOuput=True
					#print(counter)
				#os.write(1,byte)
				ans1=ord(byte1)<< 8
				ans2=ord(byte2)
				ansl=ans1+ans2
				ans3=ord(byte3)<< 8
				ans4=ord(byte4)
				ansr=ans3+ans4
				if(ansl>=32768):
					ansl-=65536
				if(ansr>=32768):
					ansr-=65536
				if(toOuput):
					filel.write(str(ansl)+'\n')
					filer.write(str(ansr)+'\n')
				
				# Do stuff with byte.
				byte1 = f.read(1)
				byte2 = f.read(1)
				byte3 = f.read(1)
				byte4 = f.read(1)
			filel.close()
			filer.close()
	print("end")

if(__name__ == '__main__'):
	decodewav(sys.argv[1])