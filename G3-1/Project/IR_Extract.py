import cv2
import numpy as np

cap1 = cv2.VideoCapture("F-laser/output1.mp4")

fgbg1 = cv2.createBackgroundSubtractorMOG2() 


while(True):
	ret, img = cap1.read()
	cv2.convertScaleAbs(img,img,0.9,50)

	img = cv2.resize(img,(640,360))
	HLS = cv2.cvtColor(img,cv2.COLOR_BGR2HLS)
	fgmask1 = fgbg1.apply(HLS)

	HSV = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
	XYZ = cv2.cvtColor(img,cv2.COLOR_BGR2XYZ)
	S_extract = HSV.copy()
	S_extract = S_extract[:,:,2]
	GRAY = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

	wow = cv2.mean(HSV)
	low_value = 230 if wow[2]+60 > 230 else wow[2]+60
	_ , HSV_Range_b = cv2.threshold(S_extract,254,255,cv2.THRESH_BINARY)
	HSV_Range = cv2.inRange(HSV,(130,90,wow[2]+60),(150,130,255))
	HSV_Range = cv2.bitwise_or(HSV_Range,HSV_Range_b)
	cv2.imshow("orig",img)
	cv2.imshow("HSV",HSV)				
	cv2.imshow("mask",fgmask1)
	AN_HSV = cv2.bitwise_and(fgmask1,HSV_Range)
	
	cv2.imshow("HSV_Range",HSV_Range)				#1
	cv2.imshow("HSV_Rangae",AN_HSV)				#1
	cv2.imshow("XYZ",XYZ)				#1
	
	
	x = cv2.Scharr(S_extract, cv2.CV_16S, 1, 0)
	y = cv2.Scharr(S_extract, cv2.CV_16S, 0, 1)
	abs_grad_x = cv2.convertScaleAbs(x)
	abs_grad_y = cv2.convertScaleAbs(y)
	dstee = cv2.addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0)
	
	#canny = cv2.Canny(S_extract,200,80)
	cv2.imshow("dst",dstee)
	laser_extract = AN_HSV.copy()			#choose method to utilise laser extract
	find_moment = cv2.moments(laser_extract)
	#print(find_moment)
	cX = 0
	cY = 0
	laser_extract = cv2.cvtColor(laser_extract,cv2.COLOR_GRAY2BGR)
	if find_moment['m00'] != 0:
		cX = int(find_moment['m10']/find_moment['m00'])
		cY = int(find_moment['m01']/find_moment['m00'])
		cv2.circle(laser_extract,(cX,cY),4,(255,0,255),-1)
	cv2.imshow("laser_extract",laser_extract)
	
	#cv2.imshow("HC",hc)
	key = cv2.waitKey(20) & 0xFF
	if key == ord('q'):
		break
	elif key == ord('k'):
		cv2.waitKey()

#HSV = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#HSV = cv2.threshold(HSV, 180, 255, cv2.THRESH_BINARY)[1]
#hist = cv2.calcHist( [HSV], [2], None, [256], [0, 256] )

#cv2.imshow("edge",edge)
cap1.release()
cv2.destroyAllWindows()



'''
cv2.imshow("HLS_Range",HLS_Range)				#2
cv2.imshow("dst_my_enhance",dst_my_enhance)		#3
cv2.imshow("HSV_and_fgmask",HSV_and_fgmask)		#4
cv2.imshow("HLS_and_fgmask",HLS_and_fgmask)		#5
cv2.imshow("fmask_my_enhance",fmask_my_enhance)	#6
#cv2.imshow("S_extract",S_extract)
#cv2.imshow("my_enhance",my_enhance)
'''
'''
HSV_Range_s_NFmask = cv2.subtract(HSV_Range,fgmask2)
HLS_Range_s_NFmask = cv2.subtract(HLS_Range,fgmask2)
dst_my_enhance_s_NFmask = cv2.subtract(dst_my_enhance,fgmask2)
HSV_and_fgmask_s_NFmask = cv2.subtract(HSV_and_fgmask,fgmask2)
HLS_and_fgmask_s_NFmask = cv2.subtract(HLS_and_fgmask,fgmask2)
fmask_my_enhance_s_NFmask = cv2.subtract(fmask_my_enhance,fgmask2)

cv2.imshow("HSV_Range_s_NFmask",HSV_Range_s_NFmask)					#7
cv2.imshow("HLS_Range_s_NFmask",HLS_Range_s_NFmask)					#8
cv2.imshow("dst_my_enhance_s_NFmask",dst_my_enhance_s_NFmask)		#9
cv2.imshow("HSV_and_fgmask_s_NFmask",HSV_and_fgmask_s_NFmask)		#10
cv2.imshow("HLS_and_fgmask_s_NFmask",HLS_and_fgmask_s_NFmask)		#11
cv2.imshow("fmask_my_enhance_s_NFmask",fmask_my_enhance_s_NFmask)	#12
'''
'''

Norm_and_fmask = cv2.bitwise_and(Norm_light,fgmask2)

HSV_Range_s_NFlight_Mask = cv2.subtract(HSV_Range,Norm_and_fmask)
HLS_Range_s_NFlight_Mask = cv2.subtract(HLS_Range,Norm_and_fmask)
dst_my_enhance_s_NFlight_Mask = cv2.subtract(dst_my_enhance,Norm_and_fmask)
HSV_and_fgmask_s_NFlight_Mask = cv2.subtract(HSV_and_fgmask,Norm_and_fmask)
HLS_and_fgmask_s_NFlight_Mask = cv2.subtract(HLS_and_fgmask,Norm_and_fmask)
fmask_my_enhance_s_NFlight_Mask = cv2.subtract(fmask_my_enhance,Norm_and_fmask)

cv2.imshow("HSV_Range_s_NFlight_Mask",HSV_Range_s_NFlight_Mask)					#13
cv2.imshow("HLS_Range_s_NFlight_Mask",HLS_Range_s_NFlight_Mask)					#14
cv2.imshow("dst_my_enhance_s_NFlight_Mask",dst_my_enhance_s_NFlight_Mask)		#15
cv2.imshow("HSV_and_fgmask_s_NFlight_Mask",HSV_and_fgmask_s_NFlight_Mask)		#16
cv2.imshow("HLS_and_fgmask_s_NFlight_Mask",HLS_and_fgmask_s_NFlight_Mask)		#17
cv2.imshow("fmask_my_enhance_s_NFlight_Mask",fmask_my_enhance_s_NFlight_Mask)	#18

'''