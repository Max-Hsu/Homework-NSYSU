# In this file, fill in the ... parts with lines of code. Do not
# create new functions.

from random import seed, randrange
P=" ♟♜♝♞♛♚"; L,R,BL,TL="▌▐▄▀"
BonR=WonR=WonB=DonR=DonB=RonB=GonR=GonB=RonG='\033[1;m\033['
WonR+='7;31;47m' # For drawing a white piece on a red background
WonB+='7;30;47m' # For drawing a white piece on a black background
DonR+='2;37;41m' # For drawing a dark piece on a red background
DonB+='2;37;40m' # For drawing a dark piece on a black background
GonR+='2;33;41m' # For drawing gold on a red background
GonB+='2;33;40m' # For drawing gold on a black background
RonG+='2;31;43m' # For drawing red on a gold background
RonB+='7;30;41m' # For drawing red on a black background
BonR+='0;30;41m' # For drawing black on a red background
Norm='\033[1;m'
totalblack='\033[0;30;40m'
def Black(x,w,c):
	if(c==0):
		print(WonB,P[0]*3,GonB,L,sep="",end="")
	if(w==True):
		if(c<7):
			print(WonB,x,BonR,L,sep="",end="")
		else:
			print(WonB,x,sep="",end="")
	else:
		if(c<7):
			print(DonB,x,BonR,L,sep="",end="")
		else:
			print(DonB,x,sep="",end="")
	if(c==7):
		print(GonB,R,WonB,sep="",end="")


def Red(x,w,c):
	if(c==0):
		print(WonB,P[0]*3,GonR,L,sep="",end="")
	if(w==True):
		if(c<7):
			print(WonR,x,RonB,L,sep="",end="")
		else:
			print(WonR,x,sep="",end="")
	else:
		if(c<7):
			print(DonR,x,RonB,L,sep="",end="")
		else:
			print(DonR,x,sep="",end="")
	if(c==7):
		print(GonR,R,WonR,sep="",end="")




def DrawBoard(B,W):
	def DrawRow(r,B,W):
		if(r%2==0):
			for coloum in range(0,8):
				createcomplex=complex(r,coloum)
				white=False
				for check in range(0,16):
					if(createcomplex==W[check]):
						white=True
						break
				#print(coloum,r,white)
				if(coloum%2==0):
					Black(B[r][coloum],white,coloum)
				else:
					Red(B[r][coloum],white,coloum)
		else:
			for coloum in range(0,8):
				createcomplex=complex(r,coloum)
				white=False
				for check in range(0,16):
					if(createcomplex==W[check]):
						white=True
						break
				#print(coloum,r,white)
				if(coloum%2==0):
					Red(B[r][coloum],white,coloum)
				else :
					Black(B[r][coloum],white,coloum)
	print(GonB,P[0]*3,sep="",end="")
	for columna in range(17):
		print(BL,sep="",end="")
	print(Norm,sep="")
	#print()
		
	for i in range(8):
		DrawRow(i,B,W)
		print(Norm,sep="")
	print(GonB,P[0]*3,sep="",end="")
	for columna in range(17):
		print(TL,sep="",end="")
	print(Norm,sep="")
	#print()


def DrawAnInitialBoard():
	r=P[2:]+P[4:1:-1]
	s=P[1]*8
	b=[r,s,P[0]*8,P[0]*8,P[0]*8,P[0]*8,s,r]
	l=[]
	for i in range(6,8):
		for j in range(0,8):
			l.append(complex(i,j))
	DrawBoard(b,l)

DrawAnInitialBoard()


def DrawRandomBoard():
	def RandomPlacement(color,otherColor):
		def checksame(color,otherColor,status,counter,compl):
			if(status==True):
				for run in range(16):
					if(otherColor[run]==compl):
						return True
				for orun in range(counter):
					if(color[orun]==compl):
						return True
			else:
				for orun in range(counter):
					if(color[orun]==compl):
						return True
			return False

		if(len(otherColor)>0):
			for make in range(16):
				compl=complex(randrange(8),randrange(8))
				while (checksame(color,otherColor,True,make,compl)==True):
					compl=complex(randrange(8),randrange(8))
				color.append(compl)
		else:
			for make in range(16):
				compl=complex(randrange(8),randrange(8))
				while (checksame(color,otherColor,False,make,compl)==True):
					compl=complex(randrange(8),randrange(8))
				color.append(compl)
				
	#seed(0) # Comment this line to make it run differently each time
	W=[]
	D=[]
	B=[] #This B object is the board. 
	RandomPlacement(W, D)
	RandomPlacement(D, W)
	#print(W,D,sep="\n")
    # Now that we know where the pieces go, we need to create the
    # eight rows of the board, inserting pieces into those spots.
    # Here, it does not matter how you decide to map the 16 pieces
    # of each color to the 16 positions in the W or D lists.
	pofa_c=list(P[2:5]*2+P[5]+P[6]+P[1]*8)
	pofa_d=list(P[2:5]*2+P[5]+P[6]+P[1]*8)
	for i in range(8):
		c=[]
		d=[]
		a=""
		for count in range(16):
			if(int(W[count].real)==i):
				#print(W[count],W[count].real,W[count].imag)
				c.append(int(W[count].imag))
		for count in range(16):
			if(int(D[count].real)==i):
				#print(D[count],D[count].real,D[count].imag)
				d.append(int(D[count].imag))
		#print("finish\n",c,d)
		c.sort()
		d.sort()
		#print("finisha\n",c,d)
		for colou in range(8):
			status=1
			for ccount in range(len(c)):
				if(colou==c[ccount]):
					randc=randrange(len(pofa_c))
					take=pofa_c[randc]
					del pofa_c[randc]
					a+=take
					status=0
					break
			for dcount in range(len(d)):
				if(colou==d[dcount]):
					randd=randrange(len(pofa_d))
					take=pofa_d[randd]
					del pofa_d[randd]
					a+=take
					status=0
					break
			if(status==1):
				a+=P[0]
		B+=[a]
		#print(B)

	DrawBoard(B,W)
DrawRandomBoard()


