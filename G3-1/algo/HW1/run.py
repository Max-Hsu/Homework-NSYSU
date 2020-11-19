import matplotlib.pyplot as plt
coordinates = []
best_case=[] #traveled_points,travel_value
best_case_avail = False
def calc_distance(last_point,now_point):
    x_last_point , y_last_point = last_point
    x_now_point  , y_now_point  = now_point
    return ((x_now_point-x_last_point)**2 + (y_now_point-y_last_point)**2)**0.5
def select(list_of_point_not_yet_travel,list_of_traveled,traveled_distance):
    #print(list_of_point_not_yet_travel,"sep",list_of_traveled,"sep",traveled_distance)
    global best_case_avail
    #print(len(list_of_point_not_yet_travel))
    if(len(list_of_point_not_yet_travel)) > 1:
        for index_pick_point in range(len(list_of_point_not_yet_travel)):
            picked_case = list_of_point_not_yet_travel[index_pick_point]
            #print(picked_case)
            if best_case_avail == True and best_case[-1] >traveled_distance:
                case = list_of_point_not_yet_travel.copy()
                case.pop(index_pick_point)
                case_travel = list_of_traveled.copy()
                #traveled_distance += calc_distance(list_of_traveled[-1],picked_case)
                case_travel.append(picked_case)
                traveled_distance_copy = traveled_distance + calc_distance(list_of_traveled[-1],picked_case)
                select(case,case_travel,traveled_distance_copy)
            elif best_case_avail == False:
                case = list_of_point_not_yet_travel.copy()
                case.pop(index_pick_point)
                case_travel = list_of_traveled.copy()
                #traveled_distance += calc_distance(list_of_traveled[-1],picked_case)
                traveled_distance_copy = traveled_distance + calc_distance(list_of_traveled[-1],picked_case)
                case_travel.append(picked_case)
                select(case,case_travel,traveled_distance_copy)
            '''
            picked_case = list_of_point_not_yet_travel[index_pick_point]
            case = list_of_point_not_yet_travel.copy()
            case.pop(index_pick_point)
            case_travel = list_of_traveled.copy()
            traveled_distance += calc_distance(list_of_traveled[-1],picked_case)
            case_travel.append(picked_case)
            select(case,case_travel,traveled_distance)
            '''
    else:
        #print("here")
        last_point = list_of_traveled[-1]
        traveled_distance += calc_distance(last_point,list_of_point_not_yet_travel[0])
        traveled_distance += calc_distance(list_of_point_not_yet_travel[0],list_of_traveled[0])
        result_travel = list_of_traveled.copy()
        #print(traveled_distance)
        if best_case_avail == False:
            result_travel.append(list_of_point_not_yet_travel[0])
            result_travel.append(list_of_traveled[0])
            best_case.append(result_travel)
            best_case.append(traveled_distance)
            best_case_avail = True
        elif best_case_avail ==True and best_case[-1] > traveled_distance:
            result_travel.append(list_of_point_not_yet_travel[0])
            result_travel.append(list_of_traveled[0])
            best_case[0] = result_travel
            best_case[1] = traveled_distance
        #print(best_case[0],best_case[1])




with open('readfile.txt') as f:
    line = f.readline()
    while line:
        _ ,x , y = line.split()
        x = int(x)
        y = int(y)
        coordinates.append((x,y))
        line = f.readline()

for index_pick_point in range(len(coordinates)):
    start_point = coordinates[index_pick_point]
    case = coordinates.copy()
    case.pop(index_pick_point)
    list_of_traveled = []
    list_of_traveled.append(coordinates[index_pick_point])
    select(case,list_of_traveled,0)
    #print("end")
print(best_case)
x_list = []
y_list = []
point_list = []
for x,y in best_case[0]:
    x_list.append(x)
    y_list.append(y)
    point_list.append(coordinates.index((x,y))+1)
print(point_list)
with open('output.txt','w') as f:
    f.write("points_traveled:\t")
    for num in point_list:
        f.write(str(num)+" ")
    f.write("\n")
    f.write("travel_distances:\t")
    f.write(str(best_case[1]))
    f.write("\n")


fig , ax = plt.subplots()
ax.plot(x_list,y_list,'m',x_list,y_list,'o')
plt.savefig('outputfig.jpg')