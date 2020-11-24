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
hist_window = 0
freq_window = 0
img_mod_ok = 0
hist_canvas = None
show_Proc_fft = None
Yl_scale = None
Yh_scale = None
c_scale  = None
D0_scale = None
blur_sharp_orig_pic = None
blur_sharp_RGB_p = None
blur_sharp_HSL_p = None
blur_sharp_diff  = None
RGB_HSL_mode = 0 #0 for RGB ,1 for HSL

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

def slicing_method(img_cv2,s_val):
    dx,dy = img_cv2.shape[0] , img_cv2.shape[1]
    and_element = np.ones((dx,dy),dtype = 'uint8')
    and_element = and_element*(2**(s_val-1))
    after_and = cv2.bitwise_and(img_cv2,and_element)
    _,fin = cv2.threshold(after_and,0,255,cv2.THRESH_BINARY)
    return fin

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
    compl.imgtk = TKimg                                                                                       #some trivial transform
    compl.config(image = TKimg)  
def RGB_choose():
    global img_cv2
    show_RGB_frame(img_cv2)

def HSL_choose():
    global img_cv2
    show_HSI_frame(img_cv2)

def show_HSI_frame(img_cv2):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2HSV)
    H_img_PIL = img_PIL.copy()
    S_img_PIL = img_PIL.copy()
    V_img_PIL = img_PIL.copy()
    H_img_PIL[:,:,1] = 0
    H_img_PIL[:,:,2] = 0
    S_img_PIL[:,:,0] = 0
    S_img_PIL[:,:,2] = 0
    V_img_PIL[:,:,0] = 0
    V_img_PIL[:,:,1] = 0
    H_img_PIL = cv2.cvtColor(H_img_PIL,cv2.COLOR_BGR2GRAY)
    S_img_PIL = cv2.cvtColor(S_img_PIL,cv2.COLOR_BGR2GRAY)
    V_img_PIL = cv2.cvtColor(V_img_PIL,cv2.COLOR_BGR2GRAY)
    H_img_PIL = PIL.Image.fromarray(H_img_PIL)
    S_img_PIL = PIL.Image.fromarray(S_img_PIL)
    V_img_PIL = PIL.Image.fromarray(V_img_PIL)
    HTKimg = PIL.ImageTk.PhotoImage(image=H_img_PIL)
    STKimg = PIL.ImageTk.PhotoImage(image=S_img_PIL)
    VTKimg = PIL.ImageTk.PhotoImage(image=V_img_PIL)
    R_frame.imgtk = HTKimg
    G_frame.imgtk = STKimg
    B_frame.imgtk = VTKimg
    R_frame.config (image = HTKimg)
    G_frame.config (image = STKimg)
    B_frame.config (image = VTKimg)
def show_RGB_frame(img_cv2):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = img_cv2.shape[0]                                                                                       #get x axis pixels
    dy = img_cv2.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(img_cv2.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)
    R_img_PIL = img_PIL.copy()
    G_img_PIL = img_PIL.copy()
    B_img_PIL = img_PIL.copy()
    R_img_PIL[:,:,1] = 0
    R_img_PIL[:,:,2] = 0
    G_img_PIL[:,:,0] = 0
    G_img_PIL[:,:,2] = 0
    B_img_PIL[:,:,0] = 0
    B_img_PIL[:,:,1] = 0
    R_img_PIL = PIL.Image.fromarray(R_img_PIL)
    G_img_PIL = PIL.Image.fromarray(G_img_PIL)
    B_img_PIL = PIL.Image.fromarray(B_img_PIL)
    RTKimg = PIL.ImageTk.PhotoImage(image=R_img_PIL)
    GTKimg = PIL.ImageTk.PhotoImage(image=G_img_PIL)
    BTKimg = PIL.ImageTk.PhotoImage(image=B_img_PIL)
    R_frame.imgtk = RTKimg
    G_frame.imgtk = GTKimg
    B_frame.imgtk = BTKimg
    R_frame.config (image = RTKimg)
    G_frame.config (image = GTKimg)
    B_frame.config (image = BTKimg)


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
    img_cv2 = rotate_image(img_cv2,rotate_val)                                                                  #calling the rotate function , on line 190
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
    scale = max_pix / max(img_cv2.shape)                                                                        #see line 69
    dx = int(dx*scale)                                                                                          #
    dy = int(dy*scale)                                                                                          #
    sized_img_cv2 = cv2.resize(img_cv2,(dy,dx) )                                                                #
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #
    pic_processed.imgtk = TKimg                                                                                 #
    pic_processed.config(image = TKimg)                                                                         #
    if(hist_window == 1 and hist == 1):                                                                         #means the img is modified by light or contrast and the histogram window had opened
        hist_new_window()                                                                                       #update histogram


def slicing():
    return LOW_scale.get(),HIGH_scale.get()

def ZERO_fun():                                                                                                 #gray-level slicing discard not selected number
    global img_cv2
    global img_mod_cv2
    LOW_VAL,HIGH_VAL = slicing()                                                                                #retrieve the threshold
    _,low = cv2.threshold(img_cv2,LOW_VAL,255,cv2.THRESH_BINARY)                                                #apply low threshold
    _,high_inv = cv2.threshold(img_cv2,HIGH_VAL,255,cv2.THRESH_BINARY_INV)                                      #get below high threshold
    img_mod_cv2 = cv2.bitwise_and(low,high_inv)                                                                 #and together
    show_proc_img(img_mod_cv2)                                                                                  


def ORIG_fun():                                                                                                 #gray-level slicing preserve not selected number
    global img_cv2
    global img_mod_cv2
    LOW_VAL,HIGH_VAL = slicing()                                                                                #retrieve the threshold
    _,low = cv2.threshold(img_cv2,LOW_VAL,255,cv2.THRESH_BINARY)                                                #apply low threshold
    _,high_inv = cv2.threshold(img_cv2,HIGH_VAL,255,cv2.THRESH_BINARY_INV)                                      #get below high threshold
    img_mod_cv2 = cv2.bitwise_and(low,high_inv)                                                                 #and together
    img_mod_cv2 = cv2.bitwise_or(img_cv2,img_mod_cv2)                                                           #or for save original
    show_proc_img(img_mod_cv2)

def rotate_image(image, angle):                                                                                 #for rotation
    image_center = tuple(np.array(image.shape[1::-1]) / 2)                                                      #get center
    rot_mat = cv2.getRotationMatrix2D(image_center, angle, 1.0)                                                 #get matrix for rotation
    result = cv2.warpAffine(image, rot_mat, image.shape[1::-1], flags=cv2.INTER_LINEAR)                         #applying the matrix on the image
    return result                                                                                               #return the rotated image

window = tk.Tk()                                                                                                #new window , init tk
window.title('DIP HW3')                                                                                         #set title
window.geometry('1200x1000')                                                                                     #set size of window

hist_window_tk = None

def hist_new_window():
    global hist_window
    global img_cv2
    global img_mod_cv2
    global hist_window_tk
    global hist_canvas
    if hist_window == 0:                                                                                        #histogram hasn't been open up
        hist_window_tk = tk.Toplevel(window)                                                                    #create a new one
        hist_window_tk.geometry("500x500")                                                                      #set size
        fig = matplotlib.pyplot.figure(figsize=(5,4), dpi=100)                                                  #acquire figure for plot
        plots=fig.add_subplot()                                                                                 #ask for subplot
        if(img_mod_ok == 1):                                                                                    #we have modified img
            hist_full = cv2.calcHist([img_mod_cv2],[0],None,[256],[0,256])                                      #calculate histogram with modified one
        else:
            hist_full = cv2.calcHist([img_cv2],[0],None,[256],[0,256])                                          #calculate histogram with original one
        plots.plot(hist_full)                                                                                   #plot to subplot
        hist_canvas = FigureCanvasTkAgg(fig, master=hist_window_tk)                                             #some trivial steps
        hist_canvas.draw()
        hist_canvas.get_tk_widget().grid(row = 1 , column = 2)
        hist_window = 1                                                                                         #histogram has opened
    else:
        hist_canvas.get_tk_widget().destroy()                                                                   #just destory the figure , !!!this has a bug of not knowing whether the histogram window is still on or not
        #hist_window_tk = tk.Toplevel(window)
        #hist_window_tk.geometry("500x500")
        fig = matplotlib.pyplot.figure(figsize=(5,4), dpi=100)                                                  #line 211
        plots=fig.add_subplot()
        if(img_mod_ok == 1):
            hist_full = cv2.calcHist([img_mod_cv2],[0],None,[256],[0,256])
        else:
            hist_full = cv2.calcHist([img_cv2],[0],None,[256],[0,256])
        plots.plot(hist_full)
        hist_canvas = FigureCanvasTkAgg(fig, master=hist_window_tk)  # A tk.DrawingArea.
        hist_canvas.draw()
        hist_canvas.get_tk_widget().grid(row = 1 , column = 2)


    

def blur_sharp_new_window():                                                                                          #
    global img_cv2
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff
    blur_sharp = tk.Toplevel(window)
    blur_sharp.geometry("1000x800")
    blur_sharp_frame = tk.Frame(blur_sharp)
    blur_sharp_frame.pack(side = tk.TOP)

    blur_but = tk.Button(blur_sharp_frame,text = 'BLUR' , command = blur_fun)
    blur_but.grid(row =1 , column = 1)
    sharp_but = tk.Button(blur_sharp_frame,text = 'SHARP' ,command = sharpen_fun)
    sharp_but.grid(row = 2 , column = 1)
    blur_sharp_orig_pic = tk.Label(blur_sharp_frame)                                                                                         
    blur_sharp_orig_pic.grid(row = 3 ,column = 2)
    blur_sharp_RGB_p = tk.Label(blur_sharp_frame)                                                                                         
    blur_sharp_RGB_p.grid(row = 3 ,column = 3)
    blur_sharp_HSL_p = tk.Label(blur_sharp_frame)                                                                                         
    blur_sharp_HSL_p.grid(row = 4 ,column = 3)
    blur_sharp_diff = tk.Label(blur_sharp_frame)                                                                                         
    blur_sharp_diff.grid(row = 3 ,column = 4)
    


def feather_new_window():                                                                                          #
    global img_cv2
    feather_extract = tk.Toplevel(window)
    feather_extract.geometry("1000x800")
    feather_extract_frame = tk.Frame(feather_extract)
    feather_extract_frame.pack(side = tk.TOP)

    feather_orig_pic = tk.Label(feather_extract_frame)                                                                                         
    feather_orig_pic.grid(row = 3 ,column = 2)
    feather_H = tk.Label(feather_extract_frame)                                                                                         
    feather_H.grid(row = 3 ,column = 3)
    feather_S = tk.Label(feather_extract_frame)                                                                                         
    feather_S.grid(row = 4 ,column = 3)
    feather_final = tk.Label(feather_extract_frame)                                                                                         
    feather_final.grid(row = 3 ,column = 4)
    feather_final_color = tk.Label(feather_extract_frame)  
    feather_final_color.grid(row = 4 ,column = 4)

    img_mod_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_mod_HSV_cv2)
    img_mod_HSV_cv2_H = cv2.inRange(img_mod_HSV_cv2_H,150,160)                                                  #H from 300 to 320 so into 255 is 
    img_mod_HSV_cv2_S = cv2.inRange(img_mod_HSV_cv2_S,128,220) 
    
    feather_extract = cv2.bitwise_and(img_mod_HSV_cv2_H,img_mod_HSV_cv2_S)

    img_mod_RGB_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2RGB)
    img_mod_RGB_cv2_R , img_mod_RGB_cv2_G , img_mod_RGB_cv2_B = cv2.split(img_mod_RGB_cv2)
    img_mod_RGB_cv2_R = cv2.bitwise_and(img_mod_RGB_cv2_R,feather_extract)
    img_mod_RGB_cv2_G = cv2.bitwise_and(img_mod_RGB_cv2_G,feather_extract)
    img_mod_RGB_cv2_B = cv2.bitwise_and(img_mod_RGB_cv2_B,feather_extract)
    img_mod_RGB_cv2 = cv2.merge((img_mod_RGB_cv2_B,img_mod_RGB_cv2_G,img_mod_RGB_cv2_R))

    img_mod_HSV_cv2_H = cv2.cvtColor(img_mod_HSV_cv2_H , cv2.COLOR_GRAY2BGR)
    img_mod_HSV_cv2_S = cv2.cvtColor(img_mod_HSV_cv2_S , cv2.COLOR_GRAY2BGR)

    show_blur_sharp(img_cv2,feather_orig_pic)
    show_blur_sharp(img_mod_HSV_cv2_H,feather_H)
    show_blur_sharp(img_mod_HSV_cv2_S,feather_S)
    show_blur_sharp(feather_extract,feather_final)
    show_blur_sharp(img_mod_RGB_cv2,feather_final_color)



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

def auto_level_d():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    img_mod_cv2 = cv2.equalizeHist(img_cv2)                                                                     #use opencv function to equalize the histogram
    img_mod_ok = 1
    show_proc_img(img_mod_cv2,1)                                                                                #show
def show_blur_sharp(img_mod_cv2,blur_sharp_orig_pic):
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
    blur_sharp_orig_pic.imgtk = TKimg                                                                                       #some trivial transform
    blur_sharp_orig_pic.config(image = TKimg)                                                                               #some trivial transform

def blur_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff
    intensity = 2   # mod!!
    img_mod_ok = 1
    img_mod_cv2 = cv2.blur(img_cv2,(intensity*2+1,intensity*2+1))
    img_mod_RGB_cv2 = img_mod_cv2.copy()
    img_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_HSV_cv2)
    img_mod_L_af_mod = cv2.blur(img_mod_HSV_cv2_V,(intensity*2+1 , intensity*2+1))
    img_mod_HSV_merge = cv2.merge((img_mod_HSV_cv2_H,img_mod_HSV_cv2_S,img_mod_L_af_mod))
    img_mod_HSV_merge = cv2.cvtColor(img_mod_HSV_merge,cv2.COLOR_HSV2BGR)
    diff = cv2.absdiff(img_mod_cv2,img_mod_HSV_merge)
    show_blur_sharp(img_cv2,blur_sharp_orig_pic)
    show_blur_sharp(img_mod_cv2,blur_sharp_RGB_p)
    show_blur_sharp(img_mod_HSV_merge,blur_sharp_HSL_p)
    show_blur_sharp(diff,blur_sharp_diff)

    show_proc_img(img_mod_cv2,1)

def sharpen_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    global blur_sharp_orig_pic
    global blur_sharp_RGB_p
    global blur_sharp_HSL_p
    global blur_sharp_diff

    intensity = 2   # mod!!
    img_mod_ok = 1
    '''
    !!!need to be implemented from Laplacian way
    '''
    img_mod_RGB_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2RGB)
    img_mod_RGB_cv2_R , img_mod_RGB_cv2_G , img_mod_RGB_cv2_B = cv2.split(img_mod_RGB_cv2)
    img_mod_RGB_cv2_R = cv2.Laplacian(img_mod_RGB_cv2_R,cv2.CV_8U,ksize = intensity*2+1)
    img_mod_RGB_cv2_G = cv2.Laplacian(img_mod_RGB_cv2_G,cv2.CV_8U,ksize = intensity*2+1)
    img_mod_RGB_cv2_B = cv2.Laplacian(img_mod_RGB_cv2_B,cv2.CV_8U,ksize = intensity*2+1)
    img_mod_RGB_cv2 = cv2.merge((img_mod_RGB_cv2_B,img_mod_RGB_cv2_G,img_mod_RGB_cv2_R))
    img_mod_cv2 = cv2.subtract(img_cv2,img_mod_RGB_cv2)

    img_mod_HSV_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2HSV)
    img_mod_HSV_cv2_H , img_mod_HSV_cv2_S , img_mod_HSV_cv2_V = cv2.split(img_mod_HSV_cv2)
    img_mod_HSV_cv2_V = cv2.Laplacian(img_mod_HSV_cv2_V,cv2.CV_8U,ksize = intensity*2+1)
    img_mod_HSV_cv2 = cv2.merge((img_mod_HSV_cv2_H,img_mod_HSV_cv2_S,img_mod_HSV_cv2_V))
    img_mod_HSV_cv2 = cv2.cvtColor(img_mod_HSV_cv2,cv2.COLOR_HSV2BGR)
    img_mod_HSV_Sub_cv2 = cv2.subtract(img_cv2,img_mod_HSV_cv2)

    diff = cv2.absdiff(img_mod_cv2,img_mod_HSV_Sub_cv2)

    show_blur_sharp(img_cv2,blur_sharp_orig_pic)
    show_blur_sharp(img_mod_cv2,blur_sharp_RGB_p)
    show_blur_sharp(img_mod_HSV_Sub_cv2,blur_sharp_HSL_p)
    show_blur_sharp(diff,blur_sharp_diff)
    show_proc_img(img_mod_cv2,1)

def save_file():
    try:                                                                                                        #this also has the same issue  , line 389
        img_save_mod_cv2 = img_mod_cv2.copy()                                                                   
    except AttributeError:
        img_save_mod_cv2 = img_cv2.copy()
    save_name = os.getcwd()+'/'+save_entry.get()                                                                #get the saving file name
    max_pix = 250                                                                                               #line68
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

                                                                                                                #this is for saving so it won't resize again , line54
    cv2.imwrite(save_name,img_save_mod_cv2)

def up():                                                                                                       #when it is in zoom in and shift up
    global bias_x
    global img_mod_cv2
    bias_x += -1                                                                                                  #x direction minus 1
    global img_mod_ok
    #if (img_mod_cv2 != None) and (img_cv2 != None):
    try:                                                                                                        #this also has the same issue  , line 389
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
    try:                                                                                                        #this also has the same issue  , line 389
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
    try:                                                                                                        #this also has the same issue  , line 389
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
    try:                                                                                                        #this also has the same issue  , line 389
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
calculate_btn = tk.Button(dirs, text='Apply The Dir', command=ls)                                               #calling the ls , line 31
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
choose = tk.Button(input_frame, text='choose file',command = choose)                                            #calling the choose , line 45
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
showpic = tk.Label(IMG)                                                                                         # the original pic
showpic.grid(row = 2 ,column = 2)
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

RGB_frame = tk.Frame(window)
RGB_frame.pack(side = tk.TOP)
R_frame = tk.Label(RGB_frame)
R_frame.grid(row = 3 , column = 1)
G_frame = tk.Label(RGB_frame)
G_frame.grid(row = 3 , column = 2)
B_frame = tk.Label(RGB_frame)
B_frame.grid(row = 3 , column = 3)

RGB_op = tk.Button(RGB_frame , text = 'show RGB',command = RGB_choose)
RGB_op.grid(row = 1, column = 0)
HSL_op = tk.Button(RGB_frame , text = 'show HSL',command = HSL_choose)
HSL_op.grid(row = 2, column = 0)
blur_sharp_button = tk.Button(RGB_frame , text = 'blur_sharp_button' , command = blur_sharp_new_window)                         # for show frequency domain
blur_sharp_button.grid(row = 3 , column = 0)
feather_button = tk.Button(RGB_frame , text = 'feather_button' , command = feather_new_window)                         
feather_button.grid(row = 4 , column = 0)

compl_frame = tk.Frame(window)
compl_frame.pack(side = tk.TOP)
compl = tk.Label(compl_frame)
compl.grid(row = 1 , column = 1)





window.mainloop()