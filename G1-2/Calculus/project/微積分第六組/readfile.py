num = 17
def readfile(fileName, offset=0):
    fileuni = open(fileName)
    fileuni.seek(offset)
    if offset == 0:
        fileuni.readline()
        fileuni.readline()
    
    status=True
    pos=0
    arrayList=[]
    counter=0
    while counter<(1<<num) and status == True:
        getnum=fileuni.readline()
        getnum=getnum[:-1]
        if(getnum == ""):
            status=False
            break
        arrayList+=[int(getnum)]
        counter+=1
    pos=fileuni.tell()
    if(status == False):
        pos=-1
        for i in range((1<<num)-counter):
            arrayList.append(0)
    return pos,arrayList
