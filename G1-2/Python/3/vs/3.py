# In this file, fill in the ... parts with lines of code. Do not
# create new functions.

from random import seed, randrange
P=" ♟♝♜♞♛♚"; LX,RX,BL,TL="▌▐▄▀"
Chest=('Q','K','N','B','R','P')
ChestIcon=(P[5],P[6],P[4],P[2],P[3],P[1])
B=[]
W=[]
WorB=[]
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
		print(WonB,P[0]*3,GonB,LX,sep="",end="")
	if(w==True):
		if(c<7):
			print(WonB,x,BonR,LX,sep="",end="")
		else:
			print(WonB,x,sep="",end="")
	else:
		if(c<7):
			print(DonB,x,BonR,LX,sep="",end="")
		else:
			print(DonB,x,sep="",end="")
	if(c==7):
		print(GonB,RX,WonB,sep="",end="")


def Red(x,w,c):
	if(c==0):
		print(WonB,P[0]*3,GonR,LX,sep="",end="")
	if(w==True):
		if(c<7):
			print(WonR,x,RonB,LX,sep="",end="")
		else:
			print(WonR,x,sep="",end="")
	else:
		if(c<7):
			print(DonR,x,RonB,LX,sep="",end="")
		else:
			print(DonR,x,sep="",end="")
	if(c==7):
		print(GonR,RX,WonR,sep="",end="")




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
				for check in range(len(W)):
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
	global B
	global W
	r=P[2:]+P[4:1:-1]
	s=P[1]*8
	b=[r,s,P[0]*8,P[0]*8,P[0]*8,P[0]*8,s,r]
	B=b
	l=[]
	for i in range(6,8):
		for j in range(0,8):
			l.append(complex(i,j))
	W=l
	DrawBoard(b,l)

DrawAnInitialBoard()


def GetAMove(WorB=None):
	if(WorB is None):
		inputs=input("White\nMove:")
		#print(inputs)
		IsLegal,Position,ToPosition=Legal(True,*inputs)
		while(IsLegal==False):
			inputs=input("Wrong Input\nWhite\nMove:")
			IsLegal,Position,ToPosition=Legal(True,*inputs)
		WorB=[]
		WorB.append("white")
		return WorB,Position,ToPosition,True
	else:
		inputs=input("Black\nMove:")
		IsLegal,Position,ToPosition=Legal(False,*inputs)
		while(IsLegal==False):
			inputs=input("Wrong Input\nBlack\nMove:")
			IsLegal,Position,ToPosition=Legal(False,*inputs)
		return None,Position,ToPosition,False

def checkRange_alphabet(stra):
	if(stra<='h' and stra >='a'):
		return True
	else:
		return False

def checkRange_number(stra):
	if(stra.isdigit()):
		pass
	else:
		return False
	if((int(stra)<9) and (int(stra)>0)):
		return True
	else:
		return False
		
		

def Legal(WorB,*inputs):
	lenOfInputs=len(inputs)
	TrueColumn=abs(int(inputs[lenOfInputs-1])-8)
	TrueRow=int(ord(inputs[lenOfInputs-2])-ord('a'))
	ToPosition=(TrueColumn,TrueRow)
	if(SyntacticallyLegal(inputs)):
		SemantLegal,Position=SemanticallyLegal(WorB,inputs)
		if(SemantLegal==True):
			return True,Position,ToPosition
	return False,[],[]

def SyntacticallyLegal(inputs):
	lenOfInputs=len(inputs)
	if(lenOfInputs<2):
		return False
	if((inputs[lenOfInputs-1]).isdigit()):
		if(checkRange_number(inputs[lenOfInputs-1])):
			pass
		else:
			return False
	else:
		return False
	"""
	to check last input
	"""
	if(inputs[lenOfInputs-2].isalpha() and inputs[lenOfInputs-2].islower()):
		if(checkRange_alphabet(inputs[lenOfInputs-2])):
			pass
		else:
			return False
	else:
		return False
	"""
	to check second last input
	"""
	lenOfInputs-=2
	if(lenOfInputs==0):
		return True
	"""
	Any Pawn
	"""
	
	"""
	Any chest move or kill with first character is uppercase
	"""
	if(inputs[0].isalpha() and inputs[0].isupper()):
		for testify in range(5):
			if(inputs[0]==Chest[testify]):
				if(lenOfInputs==1):
					return True
				elif(lenOfInputs==2):
					if(checkRange_alphabet(inputs[1]) or checkRange_number(inputs[1]) or inputs[1]=='x'):
						return True
				elif(lenOfInputs==3):
					if((checkRange_alphabet(inputs[1]) and checkRange_number(inputs[2])) or ((checkRange_alphabet(inputs[1]) or checkRange_number(inputs[1])) and inputs[2]=='x')):
						return True
				elif(lenOfInputs==4):
					if(checkRange_alphabet(inputs[1]) and checkRange_number(inputs[2]) and inputs[3]=='x'):
						return True
						

	
	elif (lenOfInputs==1 and inputs[0]=='x'):
		return True

	elif (lenOfInputs==2 and (checkRange_alphabet(inputs[0]) or checkRange_number(inputs[0])) and inputs[1]=='x'):
		return True
	'''
	elif(lenOfInputs==3 and checkRange_alphabet(inputs[0]) and checkRange_number(inputs[1]) and inputs[2]=='x'):
		return True
	'''
	"""
	Pawn kill
	"""
	return False

def FindChest(Column,Row,chest,WorB):
	createcomplex=complex(Column,Row)
	if(B[Column][Row]==ChestIcon[chest]):
		if(WorB==True):
			for checkWhite in range(len(W)):
				if(createcomplex==W[checkWhite]):
					return 1
			return -9 #collision with color black
		else:
			for checkWhite in range(len(W)):
				if(createcomplex==W[checkWhite]):
					return -9 #collision with color white
			return 1 
	else:
		for runchest in range(6):
			if(runchest!=chest and B[Column][Row]==ChestIcon[runchest]):
				return -10 #return if collision with other type of chest
	return 0 #return when nothing happen

def UL(Column,Row,count):
	Column-=count
	Row-=count
	return (Column,Row)
def U(Column,Row,count):
	Column-=count
	return (Column,Row)
def UR(Column,Row,count):
	Column-=count
	Row+=count
	return (Column,Row)
def L(Column,Row,count):
	Row-=count
	return (Column,Row)
def R(Column,Row,count):
	Row+=count
	return (Column,Row)
def DL(Column,Row,count):
	Column+=count
	Row-=count
	return (Column,Row)
def D(Column,Row,count):
	Column+=count
	return (Column,Row)
def DR(Column,Row,count):
	Column+=count
	Row+=count
	return (Column,Row)
def arrayRangeCheck(Column,Row):
	if(Column<0 or Column>7 or Row<0 or Row>7):
		return False
	else:
		return True
def Kwalk(Column,Row,chest,WorB):
	Klist=[0,0,0,0,0,0,0,0]
	Kfind=[]
	KContinueFind=[True,True,True,True,True,True,True,True]
	TColumn=Column
	TRow=Row
	far=1
	if(KContinueFind[0]==True):
		Column,Row=UL(TColumn,TRow,far)
		KContinueFind[0]=arrayRangeCheck(Column,Row)
	if(KContinueFind[0]==True):
		if(Klist[0]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[0]+=Eva
			elif(Eva==-10):
				KContinueFind[0]=False
			else:
				Klist[0]+=Eva
		
	
	if(KContinueFind[1]==True):
		Column,Row=U(TColumn,TRow,far)
		KContinueFind[1]=arrayRangeCheck(Column,Row)
	if(KContinueFind[1]==True):
		if(Klist[1]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[1]+=Eva
			elif(Eva==-10):
				KContinueFind[1]=False
			else:
				Klist[1]+=Eva
	
	if(KContinueFind[2]==True):
		Column,Row=UR(TColumn,TRow,far)
		KContinueFind[2]=arrayRangeCheck(Column,Row)
	if(KContinueFind[2]==True):
		if(Klist[2]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[2]+=Eva
			elif(Eva==-10):
				KContinueFind[2]=False
			else:
				Klist[2]+=Eva
	
	if(KContinueFind[3]==True):
		Column,Row=R(TColumn,TRow,far)
		KContinueFind[3]=arrayRangeCheck(Column,Row)
	if(KContinueFind[3]==True):
		if(Klist[3]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[3]+=Eva
			elif(Eva==-10):
				KContinueFind[3]=False
			else:
				Klist[3]+=Eva
	
	if(KContinueFind[4]==True):
		Column,Row=DR(TColumn,TRow,far)
		KContinueFind[4]=arrayRangeCheck(Column,Row)
	if(KContinueFind[4]==True):
		if(Klist[4]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[4]+=Eva
			elif(Eva==-10):
				KContinueFind[4]=False
			else:
				Klist[4]+=Eva
	
	if(KContinueFind[5]==True):
		Column,Row=D(TColumn,TRow,far)
		KContinueFind[5]=arrayRangeCheck(Column,Row)
	if(KContinueFind[5]==True):
		if(Klist[5]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[5]+=Eva
			elif(Eva==-10):
				KContinueFind[5]=False
			else:
				Klist[5]+=Eva
	
	if(KContinueFind[6]==True):
		Column,Row=DL(TColumn,TRow,far)
		KContinueFind[6]=arrayRangeCheck(Column,Row)
	if(KContinueFind[6]==True):
		if(Klist[6]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[6]+=Eva
			elif(Eva==-10):
				KContinueFind[6]=False
			else:
				Klist[6]+=Eva
	
	if(KContinueFind[7]==True):
		Column,Row=UL(TColumn,TRow,far)
		KContinueFind[7]=arrayRangeCheck(Column,Row)
	if(KContinueFind[7]==True):
		if(Klist[7]>=0):
			Eva=FindChest(Column,Row,chest,WorB)
			if(Eva==1):
				Kfind+=[(Column,Row)]
				Klist[7]+=Eva
			elif(Eva==-10):
				KContinueFind[7]=False
			else:
				Klist[7]+=Eva
	return Klist,Kfind

def Qwalk(Column,Row,chest,WorB):
	Qlist=[0,0,0,0,0,0,0,0]
	Qfind=[]
	QContinueFind=[True,True,True,True,True,True,True,True]
	TColumn=Column
	TRow=Row
	
	for far in range(1,8):
		if(QContinueFind[0]==True):
			Column,Row=UL(TColumn,TRow,far)
			QContinueFind[0]=arrayRangeCheck(Column,Row)
		if(QContinueFind[0]==True):
			if(Qlist[0]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[0]+=Eva
				elif(Eva==-10):
					QContinueFind[0]=False
				else:
					Qlist[0]+=Eva


		if(QContinueFind[1]==True):
			Column,Row=U(TColumn,TRow,far)
			QContinueFind[1]=arrayRangeCheck(Column,Row)
		if(QContinueFind[1]==True):
			if(Qlist[1]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[1]+=Eva
				elif(Eva==-10):
					QContinueFind[1]=False
				else:
					Qlist[1]+=Eva

		if(QContinueFind[2]==True):
			Column,Row=UR(TColumn,TRow,far)
			QContinueFind[2]=arrayRangeCheck(Column,Row)
		if(QContinueFind[2]==True):
			if(Qlist[2]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[2]+=Eva
				elif(Eva==-10):
					QContinueFind[2]=False
				else:
					Qlist[2]+=Eva

		if(QContinueFind[3]==True):
			Column,Row=R(TColumn,TRow,far)
			QContinueFind[3]=arrayRangeCheck(Column,Row)
		if(QContinueFind[3]==True):
			if(Qlist[3]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[3]+=Eva
				elif(Eva==-10):
					QContinueFind[3]=False
				else:
					Qlist[3]+=Eva
	
		if(QContinueFind[4]==True):
			Column,Row=DR(TColumn,TRow,far)
			QContinueFind[4]=arrayRangeCheck(Column,Row)
		if(QContinueFind[4]==True):
			if(Qlist[4]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[4]+=Eva
				elif(Eva==-10):
					QContinueFind[4]=False
				else:
					Qlist[4]+=Eva
	
		if(QContinueFind[5]==True):
			Column,Row=D(TColumn,TRow,far)
			QContinueFind[5]=arrayRangeCheck(Column,Row)
		if(QContinueFind[5]==True):
			if(Qlist[5]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[5]+=Eva
				elif(Eva==-10):
					QContinueFind[5]=False
				else:
					Qlist[5]+=Eva
	
		if(QContinueFind[6]==True):
			Column,Row=DL(TColumn,TRow,far)
			QContinueFind[6]=arrayRangeCheck(Column,Row)
		if(QContinueFind[6]==True):
			if(Qlist[6]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[6]+=Eva
				elif(Eva==-10):
					QContinueFind[6]=False
				else:
					Qlist[6]+=Eva
	
		if(QContinueFind[7]==True):
			Column,Row=UL(TColumn,TRow,far)
			QContinueFind[7]=arrayRangeCheck(Column,Row)
		if(QContinueFind[7]==True):
			if(Qlist[7]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Qfind+=[(Column,Row)]
					Qlist[7]+=Eva
				elif(Eva==-10):
					QContinueFind[7]=False
				else:
					Qlist[7]+=Eva
	return Qlist,Qfind

def Rwalk(Column,Row,chest,WorB):
	Rlist=[0,0,0,0]
	Rfind=[]
	RContinueFind=[True,True,True,True]
	TColumn=Column
	TRow=Row
	
	for far in range(1,8):
		if(RContinueFind[0]==True):
			Column,Row=U(TColumn,TRow,far)
			RContinueFind[0]=arrayRangeCheck(Column,Row)
		if(RContinueFind[0]==True):
			if(Rlist[0]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Rfind+=[(Column,Row)]
					Rlist[0]+=Eva
				elif(Eva==-10):
					RContinueFind[0]=False
				else:
					Rlist[0]+=Eva

		if(RContinueFind[1]==True):
			Column,Row=R(TColumn,TRow,far)
			RContinueFind[1]=arrayRangeCheck(Column,Row)
		if(RContinueFind[1]==True):
			if(Rlist[1]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Rfind+=[(Column,Row)]
					Rlist[1]+=Eva
				elif(Eva==-10):
					RContinueFind[1]=False
				else:
					Rlist[1]+=Eva

		if(RContinueFind[2]==True):
			Column,Row=D(TColumn,TRow,far)
			RContinueFind[2]=arrayRangeCheck(Column,Row)
		if(RContinueFind[2]==True):
			if(Rlist[2]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Rfind+=[(Column,Row)]
					Rlist[2]+=Eva
				elif(Eva==-10):
					RContinueFind[2]=False
				else:
					Rlist[2]+=Eva

		if(RContinueFind[3]==True):
			Column,Row=L(TColumn,TRow,far)
			RContinueFind[3]=arrayRangeCheck(Column,Row)
		if(RContinueFind[3]==True):
			if(Rlist[3]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Rfind+=[(Column,Row)]
					Rlist[3]+=Eva
				elif(Eva==-10):
					RContinueFind[3]=False
				else:
					Rlist[3]+=Eva
	return Rlist,Rfind

def Bwalk(Column,Row,chest,WorB):
	Blist=[0,0,0,0]
	Bfind=[]
	BContinueFind=[True,True,True,True]
	TColumn=Column
	TRow=Row
	
	for far in range(1,8):
		if(BContinueFind[0]==True):
			Column,Row=UL(TColumn,TRow,far)
			BContinueFind[0]=arrayRangeCheck(Column,Row)
		if(BContinueFind[0]==True):
			if(Blist[0]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Bfind+=[(Column,Row)]
					Blist[0]+=Eva
				elif(Eva==-10):
					BContinueFind[0]=False
				else:
					Blist[0]+=Eva

		if(BContinueFind[1]==True):
			Column,Row=UR(TColumn,TRow,far)
			BContinueFind[1]=arrayRangeCheck(Column,Row)
		if(BContinueFind[1]==True):
			if(Blist[1]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Bfind+=[(Column,Row)]
					Blist[1]+=Eva
				elif(Eva==-10):
					BContinueFind[1]=False
				else:
					Blist[1]+=Eva

		if(BContinueFind[2]==True):
			Column,Row=DR(TColumn,TRow,far)
			BContinueFind[2]=arrayRangeCheck(Column,Row)
		if(BContinueFind[2]==True):
			if(Blist[2]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Bfind+=[(Column,Row)]
					Blist[2]+=Eva
				elif(Eva==-10):
					BContinueFind[2]=False
				else:
					Blist[2]+=Eva

		if(BContinueFind[3]==True):
			Column,Row=DL(TColumn,TRow,far)
			BContinueFind[3]=arrayRangeCheck(Column,Row)
		if(BContinueFind[3]==True):
			if(Blist[3]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Bfind+=[(Column,Row)]
					Blist[3]+=Eva
				elif(Eva==-10):
					BContinueFind[3]=False
				else:
					Blist[3]+=Eva
	return Blist,Bfind

def Nwalk(Column,Row,chest,WorB):
	Nlist=[0,0,0,0,0,0,0,0]
	Nfind=[]
	NContinueFind=[True,True,True,True,True,True,True,True]
	TColumn=Column
	TRow=Row
	
	for far in range(1,2):
		if(NContinueFind[0]==True):
			Column,Row=UL(TColumn,TRow,far)
			Column,Row=U(TColumn,TRow,far)
			NContinueFind[0]=arrayRangeCheck(Column,Row)
		if(NContinueFind[0]==True):
			if(Nlist[0]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[0]+=Eva
				elif(Eva==-10):
					NContinueFind[0]=False
				else:
					Nlist[0]+=Eva


		if(NContinueFind[1]==True):
			Column,Row=UR(TColumn,TRow,far)
			Column,Row=U(TColumn,TRow,far)
			NContinueFind[1]=arrayRangeCheck(Column,Row)
		if(NContinueFind[1]==True):
			if(Nlist[1]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[1]+=Eva
				elif(Eva==-10):
					NContinueFind[1]=False
				else:
					Nlist[1]+=Eva

		if(NContinueFind[2]==True):
			Column,Row=UR(TColumn,TRow,far)
			Column,Row=R(TColumn,TRow,far)
			NContinueFind[2]=arrayRangeCheck(Column,Row)
		if(NContinueFind[2]==True):
			if(Nlist[2]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[2]+=Eva
				elif(Eva==-10):
					NContinueFind[2]=False
				else:
					Nlist[2]+=Eva

		if(NContinueFind[3]==True):
			Column,Row=DR(TColumn,TRow,far)
			Column,Row=R(TColumn,TRow,far)
			NContinueFind[3]=arrayRangeCheck(Column,Row)
		if(NContinueFind[3]==True):
			if(Nlist[3]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[3]+=Eva
				elif(Eva==-10):
					NContinueFind[3]=False
				else:
					Nlist[3]+=Eva
	
		if(NContinueFind[4]==True):
			Column,Row=DR(TColumn,TRow,far)
			Column,Row=D(TColumn,TRow,far)
			NContinueFind[4]=arrayRangeCheck(Column,Row)
		if(NContinueFind[4]==True):
			if(Nlist[4]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[4]+=Eva
				elif(Eva==-10):
					NContinueFind[4]=False
				else:
					Nlist[4]+=Eva
	
		if(NContinueFind[5]==True):
			Column,Row=DL(TColumn,TRow,far)
			Column,Row=D(TColumn,TRow,far)
			NContinueFind[5]=arrayRangeCheck(Column,Row)
		if(NContinueFind[5]==True):
			if(Nlist[5]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[5]+=Eva
				elif(Eva==-10):
					NContinueFind[5]=False
				else:
					Nlist[5]+=Eva
	
		if(NContinueFind[6]==True):
			Column,Row=DL(TColumn,TRow,far)
			Column,Row=L(TColumn,TRow,far)
			NContinueFind[6]=arrayRangeCheck(Column,Row)
		if(NContinueFind[6]==True):
			if(Nlist[6]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[6]+=Eva
				elif(Eva==-10):
					NContinueFind[6]=False
				else:
					Nlist[6]+=Eva
	
		if(NContinueFind[7]==True):
			Column,Row=UL(TColumn,TRow,far)
			Column,Row=L(TColumn,TRow,far)
			NContinueFind[7]=arrayRangeCheck(Column,Row)
		if(NContinueFind[7]==True):
			if(Nlist[7]>=0):
				Eva=FindChest(Column,Row,chest,WorB)
				if(Eva==1):
					Nfind+=[(Column,Row)]
					Nlist[7]+=Eva
				elif(Eva==-10):
					NContinueFind[7]=False
				else:
					Nlist[7]+=Eva
	return Nlist,Nfind


def Pwalk(Column,Row,chest,WorB):
	Plist=[0,0]
	Pfind=[]
	PContinueFind=[True,True]
	TColumn=Column
	TRow=Row
	if(WorB==True):
		if(Column>5):
			return [-11,-11],Pfind
		elif(Column==4 or Column==5):
			if(PContinueFind[0]==True):
				Column,Row=D(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva

			if(PContinueFind[1]==True):
				Column,Row=D(TColumn,TRow,2)
				PContinueFind[1]=arrayRangeCheck(Column,Row)
			if(PContinueFind[1]==True):
				if(Plist[1]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[1]+=Eva
					elif(Eva==-10):
						PContinueFind[1]=False
					else:
						Plist[1]+=Eva
		else:
			if(PContinueFind[0]==True):
				Column,Row=D(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva
	else:
		if(Column<2):
			return [-11,-11],Pfind
		elif(Column==2 or Column==3):
			if(PContinueFind[0]==True):
				Column,Row=U(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva

			if(PContinueFind[1]==True):
				Column,Row=U(TColumn,TRow,2)
				PContinueFind[1]=arrayRangeCheck(Column,Row)
			if(PContinueFind[1]==True):
				if(Plist[1]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[1]+=Eva
					elif(Eva==-10):
						PContinueFind[1]=False
					else:
						Plist[1]+=Eva
		else:
			if(PContinueFind[0]==True):
				Column,Row=U(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva
	return Plist,Pfind
def PKillwalk(Column,Row,chest,WorB):
	Plist=[0,0]
	Pfind=[]
	PContinueFind=[True,True]
	TColumn=Column
	TRow=Row
	if(WorB==True):
		if(Column>5):
			return [-11,-11],Pfind
		else:
			if(PContinueFind[0]==True):
				Column,Row=DL(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva
			if(PContinueFind[1]==True):
				Column,Row=DR(TColumn,TRow,1)
				PContinueFind[1]=arrayRangeCheck(Column,Row)
			if(PContinueFind[1]==True):
				if(Plist[1]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[1]+=Eva
					elif(Eva==-10):
						PContinueFind[1]=False
					else:
						Plist[1]+=Eva
	else:
		if(Column<2):
			return [-11,-11],Pfind
		else:
			if(PContinueFind[0]==True):
				Column,Row=UL(TColumn,TRow,1)
				PContinueFind[0]=arrayRangeCheck(Column,Row)
			if(PContinueFind[0]==True):
				if(Plist[0]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[0]+=Eva
					elif(Eva==-10):
						PContinueFind[0]=False
					else:
						Plist[0]+=Eva

			if(PContinueFind[1]==True):
				Column,Row=UR(TColumn,TRow,2)
				PContinueFind[1]=arrayRangeCheck(Column,Row)
			if(PContinueFind[1]==True):
				if(Plist[1]>=0):
					Eva=FindChest(Column,Row,chest,WorB)
					if(Eva==1):
						Pfind+=[(Column,Row)]
						Plist[1]+=Eva
					elif(Eva==-10):
						PContinueFind[1]=False
					else:
						Plist[1]+=Eva
	return Plist,Pfind
def FindKill(Column,Row,WorB):
	createcomplex=complex(Column,Row)
	for runchest in range(6):
		if(B[Column][Row]==ChestIcon[runchest]):
			if(WorB==False):
				for checkWhite in range(16):
					if(createcomplex==W[checkWhite] and WorB==False):
						return True
			elif(WorB==True):
				return True
	return False
def interpretFind(Column,Row,chest,kill,WorB,*,dColumn=-1,dRow=-1):
	TColumn=Column
	TRow=Row
	if(chest==5):
		if(kill==False):
			Plist,Pfind=Pwalk(TColumn,TRow,chest,WorB)
			add=0
			for run in range(len(Plist)):
				add+=Plist[run]
			if(add==0):
				return False,[]
			elif(add>1):
				if(dColumn==-1 and dRow==-1):
					return False,[]
				elif(dColumn!=-1 and dRow!=-1):
					TdColumn=abs(int(dColumn)-8)
					TdRow=int(ord(dRow)-ord('a'))
					for runColumn in range(add):
						if(Pfind[runColumn][0]==TdColumn):
							if(Pfind[runColumn][1]==TdRow):
								if(kill==True):
									if(FindKill(TColumn,TRow,WorB)):
										return True,Pfind[runColumn]
								else:
									return True,Pfind[runColumn]
					return False,[]
				elif(dColumn!=-1):
					TdColumn=abs(int(dColumn)-8)
					for runColumn in range(add):
						if(Pfind[runColumn][0]==TdColumn):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Pfind[runColumn]
							else:
								return True,Pfind[runColumn]
					return False,[]
				elif(dRow!=-1):
					TdRow=int(ord(dRow)-ord('a'))
					for runColumn in range(add):
						if(Pfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Pfind[runColumn]
							else:
								return True,Pfind[runColumn]
					return False,[]
				else:
					return False,[]
			elif(add==1):
				if(dColumn!=-1 or dRow!=-1):
					return False,[]
				else:
					if(kill==True):
						if(FindKill(TColumn,TRow,WorB)):
							return True,Pfind[0]
					else:
						return True,Pfind[0]
			else:
				return False,[]
		elif(kill==True):
			Plist,Pfind=PKillwalk(TColumn,TRow,chest,WorB)
			add=0
			for run in range(len(Plist)):
				add+=Plist[run]
			if(add==0):
				return False,[]
			elif(add>1):
				if(dColumn==-1 and dRow==-1):
					return False,[]
				elif(dColumn!=-1 and dRow!=-1):
					TdColumn=abs(int(dColumn)-8)
					TdRow=int(ord(dRow)-ord('a'))
					for runColumn in range(add):
						if(Pfind[runColumn][0]==TdColumn):
							if(Pfind[runColumn][1]==TdRow):
								if(kill==True):
									if(FindKill(TColumn,TRow,WorB)):
										return True,Pfind[runColumn]
								else:
									return True,Pfind[runColumn]
					return False,[]
				elif(dColumn!=-1):
					TdColumn=abs(int(dColumn)-8)
					for runColumn in range(add):
						if(Pfind[runColumn][0]==TdColumn):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Pfind[runColumn]
							else:
								return True,Pfind[runColumn]
					return False,[]
				elif(dRow!=-1):
					TdRow=int(ord(dRow)-ord('a'))
					for runColumn in range(add):
						if(Pfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Pfind[runColumn]
							else:
								return True,Pfind[runColumn]
					return False,[]
				else:
					return False,[]
			elif(add==1):
				if(dColumn!=-1 or dRow!=-1):
					return False,[]
				else:
					if(kill==True):
						if(FindKill(TColumn,TRow,WorB)):
							return True,Pfind[0]
					else:
						return True,Pfind[0]
			else:
				return False,[]
	elif(chest==4):
		Rlist,Rfind=Rwalk(TColumn,TRow,chest,WorB)
		add=0
		for run in range(len(Rlist)):
			add+=Rlist[run]
		if(add==0):
			return False,[]
		elif(add>1):
			if(dColumn==-1 and dRow==-1):
				return False,[]
			elif(dColumn!=-1 and dRow!=-1):
				TdColumn=abs(int(dColumn)-8)
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Rfind[runColumn][0]==TdColumn):
						if(Rfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Rfind[runColumn]
							else:
								return True,Rfind[runColumn]
				return False,[]
			elif(dColumn!=-1):
				TdColumn=abs(int(dColumn)-8)
				for runColumn in range(add):
					if(Rfind[runColumn][0]==TdColumn):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Rfind[runColumn]
						else:
							return True,Rfind[runColumn]
				return False,[]
			elif(dRow!=-1):
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Rfind[runColumn][1]==TdRow):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Rfind[runColumn]
						else:
							return True,Rfind[runColumn]
				return False,[]
			else:
				return False,[]
		elif(add==1):
			if(dColumn!=-1 or dRow!=-1):
				return False,[]
			else:
				if(kill==True):
					if(FindKill(TColumn,TRow,WorB)):
						return True,Rfind[0]
				else:
					return True,Rfind[0]
		else:
			return False,[]
	elif(chest==3):
		Blist,Bfind=Bwalk(TColumn,TRow,chest,WorB)
		add=0
		for run in range(len(Blist)):
			add+=Blist[run]
		if(add==0):
			return False,[]
		elif(add>1):
			if(dColumn==-1 and dRow==-1):
				return False,[]
			elif(dColumn!=-1 and dRow!=-1):
				TdColumn=abs(int(dColumn)-8)
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Bfind[runColumn][0]==TdColumn):
						if(Bfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Bfind[runColumn]
							else:
								return True,Bfind[runColumn]
				return False,[]
			elif(dColumn!=-1):
				TdColumn=abs(int(dColumn)-8)
				for runColumn in range(add):
					if(Bfind[runColumn][0]==TdColumn):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Bfind[runColumn]
						else:
							return True,Bfind[runColumn]
				return False,[]
			elif(dRow!=-1):
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Bfind[runColumn][1]==TdRow):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Bfind[runColumn]
						else:
							return True,Bfind[runColumn]
				return False,[]
			else:
				return False,[]
		elif(add==1):
			if(dColumn!=-1 or dRow!=-1):
				return False,[]
			else:
				if(kill==True):
					if(FindKill(TColumn,TRow,WorB)):
						return True,Bfind[0]
				else:
					return True,Bfind[0]
		else:
			return False,[]
	elif(chest==2):
		Nlist,Nfind=Nwalk(TColumn,TRow,chest,WorB)
		add=0
		for run in range(len(Nlist)):
			add+=Nlist[run]
		if(add==0):
			return False,[]
		elif(add>1):
			if(dColumn==-1 and dRow==-1):
				return False,[]
			elif(dColumn!=-1 and dRow!=-1):
				TdColumn=abs(int(dColumn)-8)
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Nfind[runColumn][0]==TdColumn):
						if(Nfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Nfind[runColumn]
							else:
								return True,Nfind[runColumn]
				return False,[]
			elif(dColumn!=-1):
				TdColumn=abs(int(dColumn)-8)
				for runColumn in range(add):
					if(Nfind[runColumn][0]==TdColumn):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Nfind[runColumn]
						else:
							return True,Nfind[runColumn]
				return False,[]
			elif(dRow!=-1):
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Nfind[runColumn][1]==TdRow):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Nfind[runColumn]
						else:
							return True,Nfind[runColumn]
				return False,[]
			else:
				return False,[]
		elif(add==1):
			if(dColumn!=-1 or dRow!=-1):
				return False,[]
			else:
				if(kill==True):
					if(FindKill(TColumn,TRow,WorB)):
						return True,Nfind[0]
				else:
					return True,Nfind[0]
		else:
			return False,[]
	elif(chest==1):
		Klist,Kfind=Kwalk(TColumn,TRow,chest,WorB)
		add=0
		for run in range(len(Klist)):
			add+=Klist[run]
		if(add==0):
			return False,[]
		elif(add>1):
			if(dColumn==-1 and dRow==-1):
				return False,[]
			elif(dColumn!=-1 and dRow!=-1):
				TdColumn=abs(int(dColumn)-8)
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Kfind[runColumn][0]==TdColumn):
						if(Kfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Kfind[runColumn]
							else:
								return True,Kfind[runColumn]
				return False,[]
			elif(dColumn!=-1):
				TdColumn=abs(int(dColumn)-8)
				for runColumn in range(add):
					if(Kfind[runColumn][0]==TdColumn):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Kfind[runColumn]
						else:
							return True,Kfind[runColumn]
				return False,[]
			elif(dRow!=-1):
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Kfind[runColumn][1]==TdRow):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Kfind[runColumn]
						else:
							return True,Kfind[runColumn]
				return False,[]
			else:
				return False,[]
		elif(add==1):
			if(dColumn!=-1 or dRow!=-1):
				return False,[]
			else:
				if(kill==True):
					if(FindKill(TColumn,TRow,WorB)):
						return True,Kfind[0]
				else:
					return True,Kfind[0]
		else:
			return False,[]
	elif(chest==0):
		Qlist,Qfind=Qwalk(TColumn,TRow,chest,WorB)
		add=0
		for run in range(len(Qlist)):
			add+=Qlist[run]
		if(add==0):
			return False,[]
		elif(add>1):
			if(dColumn==-1 and dRow==-1):
				return False,[]
			elif(dColumn!=-1 and dRow!=-1):
				TdColumn=abs(int(dColumn)-8)
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Qfind[runColumn][0]==TdColumn):
						if(Qfind[runColumn][1]==TdRow):
							if(kill==True):
								if(FindKill(TColumn,TRow,WorB)):
									return True,Qfind[runColumn]
							else:
								return True,Qfind[runColumn]
				return False,[]
			elif(dColumn!=-1):
				TdColumn=abs(int(dColumn)-8)
				for runColumn in range(add):
					if(Qfind[runColumn][0]==TdColumn):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Qfind[runColumn]
						else:
							return True,Qfind[runColumn]
				return False,[]
			elif(dRow!=-1):
				TdRow=int(ord(dRow)-ord('a'))
				for runColumn in range(add):
					if(Qfind[runColumn][1]==TdRow):
						if(kill==True):
							if(FindKill(TColumn,TRow,WorB)):
								return True,Qfind[runColumn]
						else:
							return True,Qfind[runColumn]
				return False,[]
			else:
				return False,[]
		elif(add==1):
			if(dColumn!=-1 or dRow!=-1):
				return False,[]
			else:
				if(kill==True):
					if(FindKill(TColumn,TRow,WorB)):
						return True,Qfind[0]
				else:
					return True,Qfind[0]
		else:
			return False,[]
	else:
		return False,[]

def SemanticallyLegal(WorB,inputs):
	lenOfInputs=len(inputs)
	TrueColumn=int(inputs[lenOfInputs-1])-1
	TrueRow=int(ord(inputs[lenOfInputs-2])-ord('a'))
	ReverseTrueColumn=abs(TrueColumn-7)
	checkAfterInterpret=False
	listOfChangePosition=[]
	#print(ReverseTrueColumn,TrueRow)
	
	if(lenOfInputs==2):
		checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,5,False,WorB)
	"""
	Any Pawn don't kill
	"""
	lenOfInputs-=2
	"""
	Any chest move or kill with first character is uppercase
	"""

	if(inputs[0].isalpha() and inputs[0].isupper()):
		for testify in range(5):
			if(inputs[0]==Chest[testify]):
				if(lenOfInputs==1):
					checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,False,WorB)
				elif(lenOfInputs==2):
					if(checkRange_alphabet(inputs[1])):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,False,WorB,dColumn=inputs[1])
					elif(checkRange_number(inputs[1])):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,False,WorB,dRow=inputs[1])
					elif(inputs[1]=='x'):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,True,WorB)
				elif(lenOfInputs==3):
					if(checkRange_alphabet(inputs[1]) and checkRange_number(inputs[2])):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,False,WorB,dColumn=inputs[1],dRow=inputs[2])
					elif(checkRange_alphabet(inputs[1]) and inputs[2]=='x'):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,True,WorB,dColumn=inputs[1])
					elif(checkRange_number(inputs[1]) and inputs[2]=='x'):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,testify,True,WorB,dRow=inputs[1])
				elif(lenOfInputs==4):
					if(checkRange_alphabet(inputs[1]) and checkRange_number(inputs[2]) and inputs[3]=='x'):
						checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,True,WorB,dColumn=inputs[1],dRow=inputs[2])
						

	
	elif (lenOfInputs==1 and inputs[0]=='x'):
		checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,5,True,WorB)

	elif (lenOfInputs==2 and checkRange_alphabet(inputs[0]) and inputs[1]=='x'):
		checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,5,True,dColumn=inputs[0])
	elif (lenOfInputs==2 and checkRange_number(inputs[0]) and inputs[1]=='x'):
		checkAfterInterpret,listOfChangePosition=interpretFind(ReverseTrueColumn,TrueRow,5,True,dRow=inputs[0])
	
	return checkAfterInterpret,listOfChangePosition
	"""
	elif(lenOfInputs==3 and checkRange_alphabet(inputs[0]) and checkRange_number(inputs[1]) and inputs[2]=='x'):
		return True
	"""
	"""
	Pawn kill
	"""


def PlayGame():
	global B
	global W
	Changelist=[]
	WorB=None
	while(True):
		WorB,Position,ToPosition,TrueColor=GetAMove(WorB)
		#print(Position,ToPosition)
		#print(type(B),B[ToPosition[0]],type(ToPosition[0]))
		#
		#Don't support str change how to fix??
		#
		
		Changelist=list(B[ToPosition[0]])
		Changelist[ToPosition[1]]=B[Position[0]][Position[1]]
		NewStr=''
		for runNewStr in range(8):
			NewStr+=Changelist[runNewStr]
		
		#print(NewStr)
		Changelist=list(B[Position[0]])
		Changelist[Position[1]]=P[0]
		OldStr=''
		for runOldStr in range(8):
			OldStr+=Changelist[runOldStr]
		#print(OldStr)
		for runB in range(8):
			if(runB==ToPosition[0]):
				B[runB]=NewStr
			if(runB==Position[0]):
				B[runB]=OldStr
		#print(B)
		if(TrueColor==True):
			PositionComplex=complex(Position[0],Position[1])
			NewPositionComplex=complex(ToPosition[0],ToPosition[1])
			for runComplex in range(len(W)):
				if(W[runComplex]==PositionComplex):
					W.pop(runComplex)
					W.append(NewPositionComplex)
		elif(TrueColor==False):
			PositionComplex=complex(Position[0],Position[1])
			NewPositionComplex=complex(ToPosition[0],ToPosition[1])
			for runComplex in range(len(W)):
				if(W[runComplex]==PositionComplex):
					W.pop(runComplex)
		
		DrawBoard(B,W)

PlayGame()