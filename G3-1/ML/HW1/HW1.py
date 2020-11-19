import matplotlib.pyplot as plt
import numpy as np

argument_ok = False
argument_list_float = []
coordinates_list_float = []
x_up = []
y_up = []
x_down = []
y_down = []
x_on = []
y_on = []

Learning_Rate = 0.0003

while argument_ok == False:
    input_string = input("Hi , please enter '4' value for the formula : aX^3+bX^2+cX+d(seperate by ,)\n")
    argument_list = input_string.split(',')
    if(len(argument_list)!=4):
        print("you only enter {} arguments , please refill\n".format(len(argument_list)))
        continue
    for symbol,number in enumerate(argument_list):
        try:
            argument_list_float.append(float(number))
        except ValueError:
            print("argument ",chr(ord('a')+symbol) ,": '{}'".format(number), "can not convert to number","please refill the argument again\n")
            argument_list_float.clear()
            break
    if(len(argument_list_float)==4):
        argument_ok = True
   
print("all argument is good")
argument_ok = False
while argument_ok == False:
    input_string = input("Input the coordinates of five points\n")
    argument_list = input_string.split(',')
    if(len(argument_list)!=10):
        print("you only enter {} coordinates , please refill".format(len(argument_list)))
        if(len(argument_list)%2==1):
            print("and you only input odd number of coordinates\n")
        continue
    for symbol,number in enumerate(argument_list):
        try:
            coordinates_list_float.append(float(number))
        except ValueError:
            print("coordinates number",symbol+1 ,": '{}'".format(number), "can not convert to number","please refill the argument again\n")
            coordinates_list_float.clear()
            break
    if(len(coordinates_list_float)==10):
        argument_ok = True

for index in range(0,10,2):
    cX = coordinates_list_float[index]
    cY = coordinates_list_float[index+1]
    Line_Y = argument_list_float[0]*cX**3+argument_list_float[1]*cX**2+argument_list_float[2]*cX+argument_list_float[3]
    if Line_Y > cY:
        x_down.append(cX)
        y_down.append(cY)
    elif Line_Y == cY:
        x_on.append(cX)
        y_on.append(cY)
    elif Line_Y < cY:
        x_up.append(cX)
        y_up.append(cY)

start_x = 5
for num in range(1000):
    start_x = start_x - Learning_Rate*(3*argument_list_float[0]*cX**2+2*argument_list_float[1]*cX+argument_list_float[2])
    #print(start_x)
if start_x<0:
    Min_x = 0
elif start_x>10:
    Min_x = 10
else:
    Min_x = start_x
start_x = 5
for num in range(1000):
    start_x = start_x + Learning_Rate*(3*argument_list_float[0]*cX**2+2*argument_list_float[1]*cX+argument_list_float[2])
    #print(start_x)
if start_x<0:
    Max_x = 0
elif start_x>10:
    Max_x = 10
else:
    Max_x = start_x

Min_y = argument_list_float[0]*Min_x**3+argument_list_float[1]*Min_x**2+argument_list_float[2]*Min_x+argument_list_float[3]
Max_y = argument_list_float[0]*Max_x**3+argument_list_float[1]*Max_x**2+argument_list_float[2]*Max_x+argument_list_float[3]

print(Min_x,Min_y)
print(Max_x,Max_y)
x = np.arange(0.0, 10.0, 0.01)
y = np.float_power(x,3)*argument_list_float[0] + np.float_power(x,2)*argument_list_float[1] + x*argument_list_float[2] + argument_list_float[3]

fig , ax = plt.subplots()
ax.plot(x,y,'m',x_up,y_up,'rp',x_on,y_on,'gp',x_down,y_down,'bp',Min_x,Min_y,'ko',Max_x,Max_y,'ko')

plt.show()
