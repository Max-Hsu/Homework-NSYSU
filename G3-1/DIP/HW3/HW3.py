import numpy as np
import tkinter as tk
import tkinter.ttk as ttk
import cv2
import math
import os
import PIL.ImageTk
import PIL.Image
import io
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg)
import matplotlib.pyplot
import matplotlib

now_dir = "./"
file_name = ""
img_cv2 = None
img_mod_cv2 = None
bias_x = 0
bias_y = 0
img_mod_ok = 0
hist_canvas = None
blur_sharp_orig_pic = None
blur_sharp_RGB_p = None
blur_sharp_HSL_p = None
blur_sharp_diff  = None
Orig_StrVar = None
RGB_Pro_StrVar = None
HSL_Pro_StrVar = None
Diff_StrVar = None
Orig_pro_RGB_StrVar = None
Orig_pro_HSL_StrVar = None
RGB_Pro_Diff_StrVar = None
HSI_Pro_Diff_StrVar = None

def ls():                                                                                                       #for viewing the files in the current directory
    global now_dir
    now_dir = currentdir_entry.get()                                                                            #get current pwd
    os.chdir(now_dir)                                                                                           #change dir
    T_lword = "All the files or directory\n"
    currentdir_entry.delete(0,'end')
    for f in os.listdir(now_dir):                                                                               #for every file in the dir
        if os.path.isfile(os.path.join(now_dir, f)):                                                            #tell whether it is file or dir
            T_lword += "file:\t"+str(f)+"\n"                                                                    #if it is file , store with 'file' prefix
        else:
            T_lword += "dir:\t"+str(f)+"\n"                                                                     #if it is dir , store with 'dir' prefix
    ls_label.configure(text = T_lword,justify = 'left',anchor = 'w')                                            #show on the gui
    #currentdir_label.configure(text = "current at: "+os.getcwd(),justify = 'left',anchor = 'w')
    currentdir_entry.insert(0,now_dir)                                                                          #show the current dir on the gui
def choose():                                                                                                   #this is trigger by button 'choose file'
    global file_name                                                                                            
    file_name = os.getcwd()+'/'+input_entry.get()                                                               #get the file name and add to current dir
    read_orig_img()                                                                                             #call to read img

def read_orig_img():
    global img_cv2
    global file_name
    if(file_name!= ""):                                                                                         #prevention
        img_cv2 = cv2.imread(file_name)                                                                         #using opencv to read the img
        #img_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2GRAY)                                                     #prevent color img
        show_orig_img(img_cv2)                                                                                  #call to show img
        show_compl_img(img_cv2)

def show_compl_img(img_cv2):                                                                                     #show the original image
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = 255 - img_PIL
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    compl.imgtk = TKimg                                                                                         #some trivial transform
    compl.config(image = TKimg)  
def RGB_choose():                                                                                               #for the main panel to choose which color space to show
    global img_cv2
    show_RGB_frame(img_cv2)                                                                                     #call to show RGB

def HSL_choose():
    global img_cv2
    show_HSI_frame(img_cv2)                                                                                     #call to show HSI

def show_HSI_frame(img_cv2):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2HSV)                                                     #convert color space to HSI
    H_img_PIL = img_PIL.copy()                                                                                  #for safety copy
    S_img_PIL = img_PIL.copy()
    V_img_PIL = img_PIL.copy()
    H_img_PIL[:,:,1] = 0                                                                                        #hard way to set other value to zero
    H_img_PIL[:,:,2] = 0
    S_img_PIL[:,:,0] = 0
    S_img_PIL[:,:,2] = 0
    V_img_PIL[:,:,0] = 0
    V_img_PIL[:,:,1] = 0
    H_img_PIL = cv2.cvtColor(H_img_PIL,cv2.COLOR_BGR2GRAY)                                                      #convert back to grayscale to show their intensity
    S_img_PIL = cv2.cvtColor(S_img_PIL,cv2.COLOR_BGR2GRAY)
    V_img_PIL = cv2.cvtColor(V_img_PIL,cv2.COLOR_BGR2GRAY)
    H_img_PIL = PIL.Image.fromarray(H_img_PIL)                                                                  #trivial conversion
    S_img_PIL = PIL.Image.fromarray(S_img_PIL)
    V_img_PIL = PIL.Image.fromarray(V_img_PIL)
    HTKimg = PIL.ImageTk.PhotoImage(image=H_img_PIL)                                                            #trivial conversion
    STKimg = PIL.ImageTk.PhotoImage(image=S_img_PIL)
    VTKimg = PIL.ImageTk.PhotoImage(image=V_img_PIL)
    R_frame.imgtk = HTKimg                                                                                      #assign the tk label with image
    G_frame.imgtk = STKimg
    B_frame.imgtk = VTKimg
    R_frame.config (image = HTKimg)                                                                             #assign the tk label with image
    G_frame.config (image = STKimg)
    B_frame.config (image = VTKimg)
    R_StrVar.set("H")                                                                                           #for showing the corresponding frame(label)
    G_StrVar.set("S")
    B_StrVar.set("I")
    
def show_RGB_frame(img_cv2):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #convert color space to RGB
    R_img_PIL = img_PIL.copy()                                                                                  #for safety copy
    G_img_PIL = img_PIL.copy()
    B_img_PIL = img_PIL.copy()
    R_img_PIL[:,:,1] = 0                                                                                        #hard way to set other value to zero
    R_img_PIL[:,:,2] = 0
    G_img_PIL[:,:,0] = 0
    G_img_PIL[:,:,2] = 0
    B_img_PIL[:,:,0] = 0
    B_img_PIL[:,:,1] = 0
    R_img_PIL = PIL.Image.fromarray(R_img_PIL)                                                                  #trivial conversion
    G_img_PIL = PIL.Image.fromarray(G_img_PIL)
    B_img_PIL = PIL.Image.fromarray(B_img_PIL)
    RTKimg = PIL.ImageTk.PhotoImage(image=R_img_PIL)                                                            #trivial conversion
    GTKimg = PIL.ImageTk.PhotoImage(image=G_img_PIL)
    BTKimg = PIL.ImageTk.PhotoImage(image=B_img_PIL)
    R_frame.imgtk = RTKimg                                                                                      #assign the tk label with image
    G_frame.imgtk = GTKimg
    B_frame.imgtk = BTKimg
    R_frame.config (image = RTKimg)                                                                             #assign the tk label with image
    G_frame.config (image = GTKimg)
    B_frame.config (image = BTKimg)
    R_StrVar.set("R")                                                                                           #for showing the corresponding frame(label)
    G_StrVar.set("G")
    B_StrVar.set("B")


def show_orig_img(img_cv2):                                                                                     #show the original image
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    showpic.imgtk = TKimg                                                                                       #some trivial transform
    showpic.config(image = TKimg)                                                                               #some trivial transform

def show_proc_img(img_c_cv2,hist = 0):                                                                          #show the processed image (which include zoom, rotate , shifting,brightness , contrast)
    global bias_x                                                                                               #acquire shift bias
    global bias_y
    img_cv2 = img_c_cv2.copy()                                                                                  #making copy just for safety
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale_ratio = scale_size.get()                                                                              #retrieve zoom value
    rotate_val = rotate_scale.get()                                                                             #retrieve rotate value
        #print(img_cv2)
    img_cv2 = rotate_image(img_cv2,rotate_val)                                                                  #calling the rotate function , on line 227
    center = (round(dx/2+bias_x),round(dy/2+bias_y))                                                            #this define center in zoom situation
    #print(center)
    if scale_ratio != 0:                                                                                        #the scale for zoom is changed
        if scale_ratio > 0:                                                                                     #zoom in
            crop_ratio = dy/dx                                                                                  #always keep the ratio of the image
            #print(img_cv2.shape)
            #print(dx,dy)

            crop_x = round((dx-max_pix)/5 * (scale_ratio))                                                      #define the crop size of x which the max of the zoom scale is 5
            crop_y = round(crop_x*crop_ratio)                                                                   #keep the ratio
            
            #print(crop_x,crop_y)
            #print(center[1]-crop_y,center[1]+crop_y,center[0]-crop_x,center[0]+crop_x)
            img_cv2 = img_cv2[round(center[0]-(dx/2-crop_x)):round(center[0]+(dx/2-crop_x)),round(center[1]-(dy/2-crop_y)):round(center[1]+(dy/2-crop_y))]  #crop is just limit the range of the array
            #print(crop_x,center[0]+(center[0]-crop_x),crop_y,center[1]+(center[1]-crop_y))
            #print(center[0],crop_x)
            #print(round((dy/2)-(dy/2-crop_y/2)),round((dy/2)+(dy/2-crop_y/2)),round((dx/2)-(dx/2-crop_x/2)),round((dx/2)+(dx/2-crop_x/2)))
            #print(dx/2,dy/2)
            dx = img_cv2.shape[0]                                                                               #after crop update the size
            dy = img_cv2.shape[1]
        else:                                                                                                   #zoom out
            bias_x = 0                                                                                          #clear the bias 
            bias_y = 0
            add_ratio = dx/dy                                                                                   #keep the ratio
            add_y = round(250/5*(-scale_ratio))                                                                 #define the black side size , 250 is the max size which doesn't have any meaning
            add_x = round(add_y*add_ratio)                                                                      #keep the ratio on x
            #print(add_x,add_y,img_cv2.shape)
            img_cv2 = cv2.copyMakeBorder(img_cv2,add_x,add_x,add_y,add_y,cv2.BORDER_CONSTANT)                   #add padding on the image , simple
            dx = img_cv2.shape[0]                                                                               #update the image size
            dy = img_cv2.shape[1]
    else:
        bias_x = 0                                                                                              #clean the bias once leaving the zoom in status
        bias_y = 0
    scale = max_pix / max(img_cv2.shape)                                                                        #see line 158
    dx = int(dx*scale)                                                                                          #
    dy = int(dy*scale)                                                                                          #
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #
    pic_processed.imgtk = TKimg                                                                                 #
    pic_processed.config(image = TKimg)                                                                         #                                                                                   #update histogram



def rotate_image(image, angle):                                                                                 #for rotation
    image_center = tuple(np.array(image.shape[1::-1]) / 2)                                                      #get center
    rot_mat = cv2.getRotationMatrix2D(image_center, angle, 1.0)                                                 #get matrix for rotation
    result = cv2.warpAffine(image, rot_mat, image.shape[1::-1], flags=cv2.INTER_LINEAR)                         #applying the matrix on the image
    return result                                                                                               #return the rotated image

window = tk.Tk()                                                                                                #new window , init tk
window.title('DIP HW3')                                                                                         #set title
window.geometry('1200x1000')                                                                                    #set size of window

    

def blur_sharp_new_window():                                                                                    #activate when blur_sharp button was pressed
    global img_cv2
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff
    
    global Orig_StrVar                                                                                          #the string varible will be modified by blur_fun or sharpen_fun , so i make them global
    global RGB_Pro_StrVar                                                                                       #
    global HSL_Pro_StrVar                                                                                       #
    global Diff_StrVar                                                                                          #
    global Orig_pro_RGB_StrVar                                                                                  #
    global Orig_pro_HSL_StrVar                                                                                  #
    global RGB_Pro_Diff_StrVar                                                                                  #
    global HSI_Pro_Diff_StrVar                                                                                  #

    Orig_StrVar = tk.StringVar()                                                                                #init them first
    RGB_Pro_StrVar = tk.StringVar()
    HSL_Pro_StrVar = tk.StringVar()
    Diff_StrVar = tk.StringVar()
    Orig_pro_RGB_StrVar = tk.StringVar()
    Orig_pro_HSL_StrVar = tk.StringVar()
    RGB_Pro_Diff_StrVar = tk.StringVar()
    HSI_Pro_Diff_StrVar = tk.StringVar()

    blur_sharp = tk.Toplevel(window)                                                                            #new window
    blur_sharp.geometry("1000x800")                                                                             #set size of window
    blur_sharp_frame = tk.Frame(blur_sharp)                                                                     #create another root for control
    blur_sharp_frame.pack(side = tk.TOP)

    blur_but = tk.Button(blur_sharp_frame,text = 'BLUR' , command = blur_fun)                                   # blur button
    blur_but.grid(row =1 , column = 1)
    sharp_but = tk.Button(blur_sharp_frame,text = 'SHARP' ,command = sharpen_fun)                               # sharp button
    sharp_but.grid(row = 2 , column = 1)
    Orig_label = tk.Label(blur_sharp_frame,textvariable = Orig_StrVar)                                          # showing "Original img"
    Orig_label.grid(row = 3 ,column = 2)
    Orig_pro_RGB_label = tk.Label(blur_sharp_frame,font = ('Helvetica', 30, 'bold'),textvariable = Orig_pro_RGB_StrVar) #showing the arrow
    Orig_pro_RGB_label.grid(row = 4 ,column = 3)
    Orig_pro_HSL_label = tk.Label(blur_sharp_frame,font = ('Helvetica', 30, 'bold'),textvariable = Orig_pro_HSL_StrVar) #showing the arrow
    Orig_pro_HSL_label.grid(row = 6 ,column = 3)
    blur_sharp_orig_pic = tk.Label(blur_sharp_frame)                                                            # img label for original picture   
    blur_sharp_orig_pic.grid(row = 4 ,column = 2)
    RGB_Pro_label = tk.Label(blur_sharp_frame,textvariable = RGB_Pro_StrVar)                                    # showing "RGB being Blur/sharpen"
    RGB_Pro_label.grid(row = 3 , column = 4)
    blur_sharp_RGB_p = tk.Label(blur_sharp_frame)                                                               # img label for blur/sharp RGB                        
    blur_sharp_RGB_p.grid(row = 4 ,column = 4)
    HSL_Pro_label = tk.Label(blur_sharp_frame,textvariable = HSL_Pro_StrVar)                                    # showing "HSI being Blur/sharpen"
    HSL_Pro_label.grid(row = 5 , column = 4)
    blur_sharp_HSL_p = tk.Label(blur_sharp_frame)                                                               # img label for blur/sharp HSI                            
    blur_sharp_HSL_p.grid(row = 6 ,column = 4)
    HSL_Diff_label = tk.Label(blur_sharp_frame,font = ('Helvetica', 30, 'bold'),textvariable = HSI_Pro_Diff_StrVar) #showing the arrow
    HSL_Diff_label.grid(row = 6 ,column = 5)
    RGB_Diff_label = tk.Label(blur_sharp_frame,font = ('Helvetica', 30, 'bold'),textvariable = RGB_Pro_Diff_StrVar) #showing the arrow
    RGB_Diff_label.grid(row = 4 ,column = 5)
    Diff_label = tk.Label(blur_sharp_frame,textvariable = Diff_StrVar)                                          # showing "Difference between RGB and HSI Blur/sharpen"
    Diff_label.grid(row = 3 , column = 6)
    blur_sharp_diff = tk.Label(blur_sharp_frame)                                                                # img label for difference RGB/HSI with blur/sharp   
    blur_sharp_diff.grid(row = 4 ,column = 6)
    


def feather_new_window():                                                                                       # for extracting the feather trigger by extract feather button
    global img_cv2

    feather_extract = tk.Toplevel(window)                                                                       # new window
    feather_extract.geometry("1300x600")                                                                        # set window size
    feather_extract_frame = tk.Frame(feather_extract)                                                           # generate another root
    feather_extract_frame.pack(side = tk.TOP)

    Orig_StrVar_feather = tk.Label(feather_extract_frame,text="Original image")                                 # for showing "Original image"
    Orig_StrVar_feather.grid(row = 2 , column = 2)
    feather_orig_pic = tk.Label(feather_extract_frame)                                                          # img label for original picture  
    feather_orig_pic.grid(row = 3 ,column = 2)
    Orig_Hue_label = tk.Label(feather_extract_frame , font= ('Helvetica', 30, 'bold') , text = "→")             # for showing the arrow
    Orig_Hue_label.grid(row = 3 , column = 3)
    Show_Hue =tk.Label(feather_extract_frame,text="limit Hue value between 150 to 160")                         # for showing text appear on the left which is like line 308
    Show_Hue.grid(row = 2 , column = 4)
    feather_H = tk.Label(feather_extract_frame)                                                                 # img label for Hue extract                   
    feather_H.grid(row = 3 ,column = 4)
    Show_Saturate = tk.Label(feather_extract_frame,text="limit Saturation value between 128 to 220")            # for showing text appear on the left which is like line 308
    Show_Saturate.grid(row = 5 , column = 4)
    Orig_Sat_label = tk.Label(feather_extract_frame , font= ('Helvetica', 30, 'bold') , text = "↘")             # for showing the arrow
    Orig_Sat_label.grid(row = 6 , column = 3)
    feather_S = tk.Label(feather_extract_frame)                                                                 # img label for Saturation extract                     
    feather_S.grid(row = 6 ,column = 4)
    Hue_combine_label = tk.Label(feather_extract_frame , font= ('Helvetica', 30, 'bold') , text = "→")          # for showing the arrow
    Hue_combine_label.grid(row = 3 , column = 5)
    Sat_combine_label = tk.Label(feather_extract_frame , font= ('Helvetica', 30, 'bold') , text = "↗")          # for showing the arrow
    Sat_combine_label.grid(row = 6 , column = 5)
    Show_combine = tk.Label(feather_extract_frame,text="and operation between Hue and Saturation image")        # for showing text appear on the left which is like line 308
    Show_combine.grid(row = 2 ,column = 6)
    feather_final = tk.Label(feather_extract_frame)                                                             # img label for and product                         
    feather_final.grid(row = 3 ,column = 6)
    combine_color_label = tk.Label(feather_extract_frame , font= ('Helvetica', 30, 'bold') , text = "→")        # for showing the arrow
    combine_color_label.grid(row = 3 , column = 7)
    Show_color_combine =tk.Label(feather_extract_frame,text="add the correspond color")                         # for showing text appear on the left which is like line 308
    Show_color_combine.grid(row = 2 , column = 8)
    feather_final_color = tk.Label(feather_extract_frame)                                                       # img label for final color product
    feather_final_color.grid(row = 3 ,column = 8)

    img_mod_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)                                                   #change the color space
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_mod_HSV_cv2)                      #spilt the three channels 
    img_mod_HSV_cv2_H = cv2.inRange(img_mod_HSV_cv2_H,150,160)                                                  #H from 300 to 320 in range 0~360 into the format of 0~180 is 150 to 160 (acquire from GIMP)
    img_mod_HSV_cv2_S = cv2.inRange(img_mod_HSV_cv2_S,128,220)                                                  #S from 50 to 86 in reange 0~100 into the format of 0~255 is 128 to 220 (acquire from GIMP)
    
    feather_extract = cv2.bitwise_and(img_mod_HSV_cv2_H,img_mod_HSV_cv2_S)                                      #bitwise_and with Hue and Saturation

    img_mod_RGB_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2RGB)                                                   #right now i don't have better method , so i just spilt the RGB and bitwise_and to each of them 
    img_mod_RGB_cv2_R , img_mod_RGB_cv2_G , img_mod_RGB_cv2_B = cv2.split(img_mod_RGB_cv2)
    img_mod_RGB_cv2_R = cv2.bitwise_and(img_mod_RGB_cv2_R,feather_extract)                                      #get R result
    img_mod_RGB_cv2_G = cv2.bitwise_and(img_mod_RGB_cv2_G,feather_extract)                                      #get G result
    img_mod_RGB_cv2_B = cv2.bitwise_and(img_mod_RGB_cv2_B,feather_extract)                                      #get B result
    img_mod_RGB_cv2 = cv2.merge((img_mod_RGB_cv2_B,img_mod_RGB_cv2_G,img_mod_RGB_cv2_R))                        #and Merge

    img_mod_HSV_cv2_H = cv2.cvtColor(img_mod_HSV_cv2_H , cv2.COLOR_GRAY2BGR)                                    #convert to Grayscale to show intensity
    img_mod_HSV_cv2_S = cv2.cvtColor(img_mod_HSV_cv2_S , cv2.COLOR_GRAY2BGR)                                    #

    show_blur_sharp(img_cv2,feather_orig_pic)                                                                   #calling special function to show the image
    show_blur_sharp(img_mod_HSV_cv2_H,feather_H)                                                                #
    show_blur_sharp(img_mod_HSV_cv2_S,feather_S)                                                                #
    show_blur_sharp(feather_extract,feather_final)                                                              #
    show_blur_sharp(img_mod_RGB_cv2,feather_final_color)                                                        #



def print_selection(v):                                                                                         #this will invoke by zoom and rotate
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):                                                            #!!!not able to do this , even the to is = None
    try:                                                                                                        #so the alternative is to use try
        show_proc_img(img_mod_cv2)                                                                              #if the img_mod_cv2 is empty it will invoke AttributeError
        img_mod_ok = 1
    except AttributeError:                                                                                      
        show_proc_img(img_cv2)                                                                                  #so just show the original img

def show_blur_sharp(img_mod_cv2,blur_sharp_orig_pic):                                                           #special function for blur_sharp window to show the image
    img_cv2 = img_mod_cv2.copy()
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    blur_sharp_orig_pic.imgtk = TKimg                                                                           #some trivial transform
    blur_sharp_orig_pic.config(image = TKimg)                                                                   #some trivial transform

def blur_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff

    global Orig_StrVar
    global RGB_Pro_StrVar
    global HSL_Pro_StrVar
    global Diff_StrVar
    global Orig_pro_RGB_StrVar
    global Orig_pro_HSL_StrVar
    global RGB_Pro_Diff_StrVar
    global HSI_Pro_Diff_StrVar

    intensity = 2                                                                                               # mod!! hard written to get kernel size = 5
    img_mod_ok = 1                                                                                              # trigger modify frame to show
    img_mod_cv2 = cv2.blur(img_cv2,(intensity*2+1,intensity*2+1))                                               # RGB blur
    img_mod_RGB_cv2 = img_mod_cv2.copy()
    img_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)                                                       # starting the HSV blur
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_HSV_cv2)                          # spliting HSV
    img_mod_L_af_mod = cv2.blur(img_mod_HSV_cv2_V,(intensity*2+1 , intensity*2+1))                              # only do blur on intensity
    img_mod_HSV_merge = cv2.merge((img_mod_HSV_cv2_H,img_mod_HSV_cv2_S,img_mod_L_af_mod))                       # merge it back
    img_mod_HSV_merge = cv2.cvtColor(img_mod_HSV_merge,cv2.COLOR_HSV2BGR)                                       # convert to RGB color space
    diff = cv2.absdiff(img_mod_cv2,img_mod_HSV_merge)                                                           # get difference between RGB and HSV blur
    show_blur_sharp(img_cv2,blur_sharp_orig_pic)                                                                # calling the special function for showing
    show_blur_sharp(img_mod_cv2,blur_sharp_RGB_p)                                                               #
    show_blur_sharp(img_mod_HSV_merge,blur_sharp_HSL_p)                                                         #
    show_blur_sharp(diff,blur_sharp_diff)                                                                       #
    Orig_StrVar.set("Original image")                                                                           # setting the string to be show
    RGB_Pro_StrVar.set("RGB being Blur")                                                                        #
    HSL_Pro_StrVar.set("HSI being Blur")                                                                        #
    Diff_StrVar.set("Difference between RGB and HSI Blur")                                                      #
    Orig_pro_RGB_StrVar.set("→")                                                                                #
    Orig_pro_HSL_StrVar.set("↘")                                                                                #
    RGB_Pro_Diff_StrVar.set("→")                                                                                #
    HSI_Pro_Diff_StrVar.set("↗")                                                                                #
    show_proc_img(img_mod_cv2,1)                                                                                # calling the main panel to show

def sharpen_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff

    global Orig_StrVar
    global RGB_Pro_StrVar
    global HSL_Pro_StrVar
    global Diff_StrVar
    global Orig_pro_RGB_StrVar
    global Orig_pro_HSL_StrVar
    global RGB_Pro_Diff_StrVar
    global HSI_Pro_Diff_StrVar

    intensity = 2                                                                                               # mod!! hard written to get kernel size = 5
    img_mod_ok = 1                                                                                              # trigger modify frame to show
    '''
    !!!need to be implemented from Laplacian way
    '''
    img_mod_RGB_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2RGB)                                                   # start RGB sharpen by convert to RGB color space
    img_mod_RGB_cv2_R , img_mod_RGB_cv2_G , img_mod_RGB_cv2_B = cv2.split(img_mod_RGB_cv2)                      # split to get processed independently
    img_mod_RGB_cv2_R = cv2.Laplacian(img_mod_RGB_cv2_R,cv2.CV_8U,ksize = intensity*2+1)                        # do Laplacian 
    img_mod_RGB_cv2_G = cv2.Laplacian(img_mod_RGB_cv2_G,cv2.CV_8U,ksize = intensity*2+1)                        #
    img_mod_RGB_cv2_B = cv2.Laplacian(img_mod_RGB_cv2_B,cv2.CV_8U,ksize = intensity*2+1)                        #
    img_mod_RGB_cv2 = cv2.merge((img_mod_RGB_cv2_B,img_mod_RGB_cv2_G,img_mod_RGB_cv2_R))                        # merge it back
    img_mod_cv2 = cv2.subtract(img_cv2,img_mod_RGB_cv2)                                                         # subtract with original image to get sharpen image

    img_mod_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)                                                   # start HSI sharpen by convert to HSV color space
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_mod_HSV_cv2)                      # split to get processed independently
    img_mod_HSV_cv2_V = cv2.Laplacian(img_mod_HSV_cv2_V,cv2.CV_8U,ksize = intensity*2+1)                        # do Laplacian only on V plane
    img_mod_HSV_cv2 = cv2.merge((img_mod_HSV_cv2_H,img_mod_HSV_cv2_S,img_mod_HSV_cv2_V))                        # merge it back
    img_mod_HSV_cv2 = cv2.cvtColor(img_mod_HSV_cv2,cv2.COLOR_HSV2BGR)                                           # convert it back to BGR
    img_mod_HSV_Sub_cv2 = cv2.subtract(img_cv2,img_mod_HSV_cv2)                                                 # subtract to get sharpen image

    diff = cv2.absdiff(img_mod_cv2,img_mod_HSV_Sub_cv2)                                                         # acquire difference between RGB and HSV

    show_blur_sharp(img_cv2,blur_sharp_orig_pic)                                                                # calling the special function for showing
    show_blur_sharp(img_mod_cv2,blur_sharp_RGB_p)                                                               #
    show_blur_sharp(img_mod_HSV_Sub_cv2,blur_sharp_HSL_p)                                                       #
    show_blur_sharp(diff,blur_sharp_diff)                                                                       #

    Orig_StrVar.set("Original image")                                                                           # setting the string to be show
    RGB_Pro_StrVar.set("RGB being Sharpen")                                                                     #
    HSL_Pro_StrVar.set("HSI being Sharpen")                                                                     #
    Diff_StrVar.set("Difference between RGB and HSI Sharpen")                                                   #
    Orig_pro_RGB_StrVar.set("→")                                                                                #
    Orig_pro_HSL_StrVar.set("⬊")                                                                                #
    RGB_Pro_Diff_StrVar.set("→")                                                                                #
    HSI_Pro_Diff_StrVar.set("⬈")                                                                                #

    show_proc_img(img_mod_cv2,1)                                                                                # calling the main panel to show

def save_file():
    try:                                                                                                        #this also has the same issue  , line 368
        img_save_mod_cv2 = img_mod_cv2.copy()                                                                   
    except AttributeError:
        img_save_mod_cv2 = img_cv2.copy()
    save_name = os.getcwd()+'/'+save_entry.get()                                                                #get the saving file name
    max_pix = 250                                                                                               #line158
    dx = img_save_mod_cv2.shape[0]
    dy = img_save_mod_cv2.shape[1]
    scale_ratio = scale_size.get()
    rotate_val = rotate_scale.get()
    img_save_mod_cv2 = rotate_image(img_save_mod_cv2,rotate_val)
    center = (round(dx/2+bias_x),round(dy/2+bias_y))
    if scale_ratio != 0:
        if scale_ratio > 0:
            crop_ratio = dy/dx
            #print(img_save_mod_cv2.shape)
            #print(dx,dy)

            crop_x = round((dx-max_pix)/5 * (scale_ratio))
            crop_y = round(crop_x*crop_ratio)
            
            #print(crop_x,crop_y)
            #print(center[1]-crop_y,center[1]+crop_y,center[0]-crop_x,center[0]+crop_x)
            img_save_mod_cv2 = img_save_mod_cv2[round(center[0]-(dx/2-crop_x)):round(center[0]+(dx/2-crop_x)),round(center[1]-(dy/2-crop_y)):round(center[1]+(dy/2-crop_y))]
            #print(round((dy/2)-(dy/2-crop_y/2)),round((dy/2)+(dy/2-crop_y/2)),round((dx/2)-(dx/2-crop_x/2)),round((dx/2)+(dx/2-crop_x/2)))
            #print(dx/2,dy/2)
            dx = img_save_mod_cv2.shape[0]
            dy = img_save_mod_cv2.shape[1]
        else:
            add_ratio = dx/dy
            add_y = round(250/5*(-scale_ratio))
            add_x = round(add_y*add_ratio)
            #print(add_x,add_y,img_save_mod_cv2.shape)
            img_save_mod_cv2 = cv2.copyMakeBorder(img_save_mod_cv2,add_x,add_x,add_y,add_y,cv2.BORDER_CONSTANT)
            dx = img_save_mod_cv2.shape[0]
            dy = img_save_mod_cv2.shape[1]            
    cv2.imwrite(save_name,img_save_mod_cv2)                                                                     #this is for saving the image

def up():                                                                                                       #when it is in zoom in and shift up
    global bias_x
    global img_mod_cv2
    bias_x += -1                                                                                                #x direction minus 1
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):
    try:                                                                                                        #this also has the same issue  , line 368
        show_proc_img(img_mod_cv2)                                                                              #show pic
        img_mod_ok = 1
    except AttributeError:
        show_proc_img(img_cv2)
def down():                                                                                                     #when it is in zoom in and shift down
    global bias_x
    global img_mod_cv2
    bias_x += 1                                                                                                 #x direction add 1
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):
    try:                                                                                                        #this also has the same issue  , line 368
        show_proc_img(img_mod_cv2)                                                                              #show pic
        img_mod_ok = 1
    except AttributeError:
        show_proc_img(img_cv2)
def right():                                                                                                    #when it is in zoom in and shift right
    global bias_y
    global img_mod_cv2
    bias_y +=1                                                                                                  #y direction add 1
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):
    try:                                                                                                        #this also has the same issue  , line 368
        show_proc_img(img_mod_cv2)                                                                              #show pic
        img_mod_ok = 1
    except AttributeError:
        show_proc_img(img_cv2)
def left():                                                                                                     #when it is in zoom in and shift left
    global bias_y
    global img_mod_cv2
    bias_y +=-1                                                                                                 #y direction minus 1
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):
    try:                                                                                                        #this also has the same issue  , line 368
        show_proc_img(img_mod_cv2)                                                                              #show pic
        img_mod_ok = 1
    except AttributeError:
        show_proc_img(img_cv2)
dirs = tk.Frame(window)                                                                                         #top of the gui , for choose the right directory
dirs.pack(side=tk.TOP)
currentdir_label = tk.Label(dirs,text = 'Current Directory ',justify = 'left' , anchor = 'w')
currentdir_label.pack(side=tk.LEFT)
v = tk.StringVar(dirs,value = os.getcwd())
currentdir_entry = tk.Entry(dirs ,textvariable = v,width = 90)
currentdir_entry.pack(side=tk.LEFT)
calculate_btn = tk.Button(dirs, text='Apply The Dir', command=ls)                                               #calling the ls , line 35
calculate_btn.pack(side=tk.LEFT)

show_files = tk.Frame(window)                                                                                   #for after apply the dir , show the directory files
show_files.pack(side=tk.TOP)
ls_label = tk.Label(show_files,justify = 'left',anchor = 'w')
ls_label.pack(side=tk.TOP)

input_frame = tk.Frame(window)                                                                                  #for picking the image file
input_frame.pack(side=tk.TOP)
input_label = tk.Label(input_frame, text='Input file')
input_label.pack(side=tk.LEFT)
input_entry = tk.Entry(input_frame)
input_entry.pack(side=tk.LEFT)
choose = tk.Button(input_frame, text='choose file',command = choose)                                            #calling the choose , line 49
choose.pack(side=tk.LEFT)

save_Panel = tk.Frame(window)                                                                                   #for saving the file after processes
save_Panel.pack(side = tk.TOP)
save_label = tk.Label(save_Panel, text='Save file')
save_label.pack(side=tk.LEFT)
save_entry = tk.Entry(save_Panel)
save_entry.pack(side=tk.LEFT)
save_but = tk.Button(save_Panel, text='Save',command = save_file)                                               #calling the save_file
save_but.pack(side=tk.LEFT)

IMG = tk.Frame(window)                                                                                          # showing the img part
IMG.pack(side=tk.TOP)
compl = tk.Label(IMG)
compl.grid(row = 2 , column = 2)
showpic = tk.Label(IMG)                                                                                         # the original pic
showpic.grid(row = 2 ,column = 1)
pic_processed = tk.Label(IMG)                                                                                   # the processed pic
pic_processed.grid(row=2 , column = 5)
up_button = tk.Button(IMG,text = '↑' , command = up)                                                            # shift up
up_button.grid(row = 1 , column = 5)
down_button = tk.Button(IMG,text = '↓' , command = down)                                                        # shift down
down_button.grid(row = 3 , column = 5)
left_button = tk.Button(IMG,text = '←' , command = left)                                                        # shift left
left_button.grid(row = 2 , column = 4)
right_button = tk.Button(IMG,text = '→' , command = right)                                                      # shift right
right_button.grid(row = 2 , column = 6)
scale_size = tk.Scale(IMG, label='zoom in/out', from_=-5, to=5, orient=tk.VERTICAL, length=200, showvalue=1,tickinterval=2, resolution=0.01, command=print_selection) # zoom scale
scale_size.set(0)                                                                                               # set zoom scale to 0
scale_size.grid(row = 2 ,column = 3)

rotate_Panel = tk.Frame(window)                                                                                 # for image rotation
rotate_Panel.pack(side = tk.TOP)
rotate_scale = tk.Scale(rotate_Panel , label = 'rotation' , from_ = -180 , to = 180 , orient = tk.HORIZONTAL , length = 400 , tickinterval= 40 , showvalue = 1, resolution = 1 , command = print_selection)
rotate_scale.grid(row = 1 , column =2)

RGB_frame = tk.Frame(window)                                                                                    # HW3 frame
RGB_frame.pack(side = tk.TOP)
R_frame = tk.Label(RGB_frame)                                                                                   # image label for R/H image
R_frame.grid(row = 3 , column = 1)
G_frame = tk.Label(RGB_frame)                                                                                   # image label for G/S image
G_frame.grid(row = 3 , column = 2)
B_frame = tk.Label(RGB_frame)                                                                                   # image label for B/I image
B_frame.grid(row = 3 , column = 3)
R_StrVar = tk.StringVar()                                                                                       
G_StrVar = tk.StringVar()                                                                                       
B_StrVar = tk.StringVar()                                                                                       
R_lab   = tk.Label(RGB_frame,textvariable = R_StrVar)                                                           # for showing "R/H"
R_lab.grid(row = 2 , column = 1)
G_lab   = tk.Label(RGB_frame,textvariable = G_StrVar)                                                           # for showing "G/S"
G_lab.grid(row = 2 , column = 2)
B_lab   = tk.Label(RGB_frame,textvariable = B_StrVar)                                                           # for showing "B/I"
B_lab.grid(row = 2 , column = 3)


RGB_op = tk.Button(RGB_frame , text = 'show RGB',command = RGB_choose)                                          # op button for show RGB
RGB_op.grid(row = 1, column = 0)
HSL_op = tk.Button(RGB_frame , text = 'show HSI',command = HSL_choose)                                          # op button for show HSI
HSL_op.grid(row = 2, column = 0)
blur_sharp_button = tk.Button(RGB_frame , text = 'blur_sharp_button' , command = blur_sharp_new_window)         # op button for blur_sharp new window
blur_sharp_button.grid(row = 5 , column = 0)
feather_button = tk.Button(RGB_frame , text = 'feather_button' , command = feather_new_window)                  # op button for feather extraction new window
feather_button.grid(row = 6 , column = 0)

window.mainloop()