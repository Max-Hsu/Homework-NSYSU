import numpy as np
import cv2 as cv

img = cv.imread('do2.png')
imgray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
ret, thresh = cv.threshold(imgray, 127, 255, 0)

contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
#print(contours)
cv.drawContours(img, contours, 0, (0,255,0), 3)
cv.imshow("hi",img)
cv.waitKey(-1)

c = np.array(contours[0])
extLeft = tuple(c[c[:, :, 0].argmin()][0])
extRight = tuple(c[c[:, :, 0].argmax()][0])
extTop = tuple(c[c[:, :, 1].argmin()][0])
extBot = tuple(c[c[:, :, 1].argmax()][0])
print(extLeft,extRight,extTop,extBot)

q1 = extTop
q2 = extLeft
q3 = extRight
q4 = extBot
'''
q1,q2,q4,q3 = contours[0]
q1=tuple(q1[0])
q2=tuple(q2[0])
q3=tuple(q3[0])
q4=tuple(q4[0])
'''

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
cv.imshow("hi2",img2)
cv.waitKey(-1)
cv.imshow("warp",warp)
cv.waitKey(-1)