def sd(str,count):
    if(count>0):
        str += "hi "
        sd(str,count-1)
    else:
        print(str)
for i in range(5):
    sot = "wew"
    sd(sot,i)