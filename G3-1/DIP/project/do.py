import numpy as np
import cv2 as cv
import sys
import math
from optparse import OptionParser
import os

def my_show(in_img_cv2,options):
    if options.show_pic == True:
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
def transpose(filename,options,after_filename):
    img = cv.imread(filename)
    imgray = cv.cvtColor(img, cv.COLOR_BGR2HSV)
    _, _, imgray = cv.split(imgray)
    ret, thresh = cv.threshold(imgray, np.mean(imgray), 255, 0)
    my_show(thresh,options)


    imgrayx= cv.convertScaleAbs(thresh, alpha=1.5, beta=0)
    kernel = np.array([[-3,-3,-3], [-3,24,-3], [-3,-3,-3]])
    im = cv.filter2D(imgrayx, -1, kernel)
    my_show(im,options)

    blurred = cv.GaussianBlur(im, (3, 3), 0)
    my_show(blurred,options)
    binaryIMG = cv.Canny(blurred, 10, 15)
    my_show(binaryIMG,options)

    binaryIMG = cv.dilate(binaryIMG,(3,3),iterations = 3)

    '''
    contours, hierarchy = cv.findContours(binaryIMG, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    '''
    contours, hierarchy = cv.findContours(binaryIMG.copy(), cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
    cnts = sorted(contours, key=cv.contourArea, reverse=True)

    img_for_show = img.copy()
    for c in cnts:
        peri = cv.arcLength(c, True)
        approx = cv.approxPolyDP(c, 0.02*peri, True)
        cv.drawContours(img_for_show, c, -1, (0,0,255), 3)
        my_show(img_for_show,options)
        if len(approx) == 4:
            screenCnt = approx
            break

    #print(contours)
    cv.drawContours(img_for_show, [screenCnt], -1, (0,255,0), 3)
    cv.drawContours(img_for_show, cnts[0], -1, (0,0,255), 3)
    my_show(img_for_show,options)

    c = np.array(screenCnt)
    list_arr = []
    for extract in screenCnt:
        list_arr.append(list(extract[0]))
    min_extract = math.inf
    min_saver = None
    max_extract = -math.inf
    max_saver = None
    for extract in range(len(list_arr)):
        evalue = list_arr[extract][0]**2 + list_arr[extract][1]**2
        if(evalue < min_extract):
            min_saver = extract
            min_extract = evalue
        if(evalue > max_extract):
            max_saver = extract
            max_extract = evalue
    q1 = list_arr[min_saver]
    q4 = list_arr[max_saver]
    list_arr.remove(q1)
    list_arr.remove(q4)
    if(list_arr[0][0] < list_arr[1][0]):
        q2 = list_arr[0]
        q3 = list_arr[1]
    else:
        q2 = list_arr[1]
        q3 = list_arr[0]

    '''
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
        print("wrong")
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

    '''
    
    #print(q1,q2,q3,q4)

    height , width ,_ = img.shape
    dst = np.array([[0,0],[0,height],[width,0],[width,height]], dtype = "float32")
    src = np.array([list(q1),list(q2),list(q3),list(q4)], dtype = "float32")
    M = cv.getPerspectiveTransform(src, dst)
    if not options.quiet:
        print(q1,q2,q3,q4)
        print(M)
    warp = cv.warpPerspective(img,M,(width,height))
    img2 = cv.circle(img,tuple(q1),8,(255,0,0),thickness = -1)
    img2 = cv.circle(img2,tuple(q2),8,(0,0,255),thickness = -1)
    img2 = cv.circle(img2,tuple(q3),8,(0,0,255),thickness = -1)
    img2 = cv.circle(img2,tuple(q4),8,(0,0,255),thickness = -1)
    my_show(img2,options)
    my_show(warp,options)
    cv.imwrite(after_filename , warp)

if __name__ == '__main__':
    usage = "python3 do.py file_to_execute [options]"
    parser = OptionParser(usage=usage)
    parser.add_option("-s","--show",action="store_true", dest="show_pic", default=False,help="show the picture during processing , any key to proceed")
    parser.add_option("-o","--output",action="store_true",help="the template for output image format,must contain %s for seperating files")
    parser.add_option("-r","--ocr",action="store_true", dest="ocr", default=False,help="apply ocr application")
    parser.add_option("-q","--quiet",action="store_true", dest="quiet", default=False,help="show the picture during processing , any key to proceed")
    
    (options, args) = parser.parse_args()
    if options.output == None or options.output == True:
        output_string = "processed_%s"
    else:
        output_string = options.output
    
    for run in args:
        dirname = os.path.dirname(run)
        file_name = os.path.basename(run)
        if dirname != "":
            dirname += "/"
        after_filename = dirname + output_string %(file_name)
        if options.quiet == False:
            print(run ,"\tinto\t",after_filename)
        transpose(run,options,after_filename)
