import numpy as np
import cv2 as cv
import sys

def my_show(in_img_cv2):
    img_cv2 = in_img_cv2.copy()
    max_pix = 800                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv.resize(img_cv2,(dy,dx) )  
    cv.imshow("myshow",sized_img_cv2)
    cv.waitKey(-1)

img = cv.imread(sys.argv[1])
print(sys.argv[1])
imgray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
ret, thresh = cv.threshold(imgray, np.mean(imgray), 255, 0)
my_show(thresh)

blurred = cv.GaussianBlur(thresh, (11, 11), 0)

binaryIMG = cv.Canny(blurred, 20, 160)
contours, hierarchy = cv.findContours(binaryIMG, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
#print(contours)
cv.drawContours(img, contours, 0, (0,255,0), 3)
my_show(img)

c = np.array(contours[0])
extLeft = tuple(c[c[:, :, 0].argmin()][0])
extRight = tuple(c[c[:, :, 0].argmax()][0])
extTop = tuple(c[c[:, :, 1].argmin()][0])
extBot = tuple(c[c[:, :, 1].argmax()][0])
print(extLeft,extRight,extTop,extBot)

checklist = [extLeft,extRight,extTop,extBot]
check_rectangle = 0
for element in checklist:
    remove_first_element = checklist
    remove_first_element.remove(element)
    for second_element in remove_first_element:
        if second_element == element:
            check_rectangle = 1
            break

if check_rectangle == 1 :
    q1,q2,q4,q3 = contours[0]
    q1=tuple(q1[0])
    q2=tuple(q2[0])
    q3=tuple(q3[0])
    q4=tuple(q4[0])
else:
    q1 = extTop
    q2 = extLeft
    q3 = extRight
    q4 = extBot

height , width ,_ = img.shape
dst = np.array([[0,0],[0,height],[width,0],[width,height]], dtype = "float32")
src = np.array([list(q1),list(q2),list(q3),list(q4)], dtype = "float32")
M = cv.getPerspectiveTransform(src, dst)
print(M)
warp = cv.warpPerspective(img,M,(width,height))
img2 = cv.circle(img,tuple(q1),8,(255,0,0),thickness = -1)
img2 = cv.circle(img2,tuple(q2),8,(0,0,255),thickness = -1)
img2 = cv.circle(img2,tuple(q3),8,(0,0,255),thickness = -1)
img2 = cv.circle(img2,tuple(q4),8,(0,0,255),thickness = -1)
my_show(img2)
my_show(warp)

