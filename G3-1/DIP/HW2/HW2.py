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
        img_cv2 = cv2.cvtColor(img_cv2,cv2.COLOR_BGR2GRAY)                                                      #prevent color img
        show_orig_img(img_cv2)                                                                                  #call to show img

def slicing_method(img_cv2,s_val):
    dx,dy = img_cv2.shape[0] , img_cv2.shape[1]
    and_element = np.ones((dx,dy),dtype = 'uint8')
    and_element = and_element*(2**(s_val-1))
    after_and = cv2.bitwise_and(img_cv2,and_element)
    _,fin = cv2.threshold(after_and,0,255,cv2.THRESH_BINARY)
    return fin
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
    slicing_val = slicing_scale.get()
    if (slicing_val):
        img_cv2 = slicing_method(img_cv2,slicing_val)
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
'''
def show_fft(log,amp,phase):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = log.shape[0]                                                                                       #get x axis pixels
    dy = log.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(log.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale)
    sized_img_cv2 = cv2.resize(PIL.Image.fromarray(log.astype(np.uint8)),(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    log_pic.imgtk = TKimg                                                                                       #some trivial transform
    log_pic.config(image = TKimg)

    sized_img_cv2 = cv2.resize(amp,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    amp_pic.imgtk = TKimg                                                                                       #some trivial transform
    amp_pic.config(image = TKimg)

    sized_img_cv2 = cv2.resize(phase,(dy,dx) )                                                                #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    img_PIL = PIL.Image.fromarray(img_PIL)                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    phase_pic.imgtk = TKimg                                                                                       #some trivial transform
    phase_pic.config(image = TKimg)
'''

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
window.title('DIP HW2')                                                                                         #set title
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
def homo_show(label,pic):
    max_pix = 250                                                                                               #i limited the maximum size to show
    dx = pic.shape[0]                                                                                       #get x axis pixels
    dy = pic.shape[1]                                                                                       #get y axis pixels
    scale = max_pix / max(pic.shape)                                                                        #the most longest part should fix the max size so choose max
    dx = int(dx*scale)                                                                                          #using the ratio to find the final product size
    dy = int(dy*scale) 
    sized_img_cv2 = cv2.resize(pic,(dy,dx) )                                                             #use opencv resize to limit the img size
    img_PIL = cv2.cvtColor(sized_img_cv2,cv2.COLOR_BGR2RGB)                                                     #for showing we need to transfer into RGB type( if further use is for color image)
    #print(img_PIL)
    img_PIL *= 255
    img_PIL = PIL.Image.fromarray(img_PIL.astype(np.uint8))                                                                      #some transfer steps
    TKimg = PIL.ImageTk.PhotoImage(image=img_PIL)                                                               #tk interface for photos
    label.imgtk = TKimg                                                                                       #some trivial transform
    label.config(image = TKimg)

def homo_process(dummy):
    global img_cv2
    global show_Proc_fft
    global Yl_scale
    global Yh_scale
    global c_scale 
    global D0_scale 

    img_gray_cv2 = img_cv2.copy()                                                                               #copy for safe
    fft_pre = np.log1p(np.array(img_gray_cv2,dtype = np.float64))                                               #step 1 ln
    fft_img = np.fft.fft2(fft_pre)                                                                              #step 2 fft

    Yl = Yl_scale.get()                                                                                         #get scale value
    Yh = Yh_scale.get()
    c = c_scale.get()
    D0 = D0_scale.get()

    du = np.zeros(fft_img.shape, dtype = np.float32)                                                            #create empty matrix
    dft_M = fft_img.shape[0]
    dft_N = fft_img.shape[1]
    
    for u in range(dft_M):                                                                                      #produce the matrix to be multiply
        for v in range(dft_N):
            du[u,v] = math.sqrt((u - dft_M/2.0)*(u - dft_M/2.0) + (v - dft_N/2.0)*(v - dft_N/2.0))              #formula for D
    du2 = cv2.multiply(du,du) / (D0*D0)                                                                         #do mul
    re = np.exp(- c * du2)                                                                                      #
    H = (Yh - Yl) * (1 - re) + Yl                                                                               #final for H
    H = np.fft.fftshift(H)                                                                                      #shift for multiply
    
    filtered = H*fft_img                                                                                        #mul #step 3

    filtered = np.fft.ifft2(filtered)                                                                           #reverse fft # step 4

    filtered = np.exp(np.real(filtered))-1                                                                      #step 5
    #print(filtered)
    #filtered *= 255.0/filtered.max()
    filtered = np.uint8(filtered)                                                                               #back to uint8

    homo_show(show_Proc_fft,filtered)                                                                           #show

def homo_new_window():                                                                                          #for new window of homo
    global show_Proc_fft
    global Yl_scale
    global Yh_scale
    global c_scale 
    global D0_scale 
    new_homo_window_tk = tk.Toplevel(window)    
    new_homo_window_tk.geometry("1000x800")
    homo_frame = tk.Frame(new_homo_window_tk)
    homo_frame.pack(side = tk.TOP)
    
    

    #nN_fft_img = (Yh - Yl)* (1-np.e**(((-c)*fft_img**2)/D0**2))+Yl
    

    #normalization to be representable 
    #filtered = cv2.magnitude(filtered[:, :, 0], filtered[:, :, 1])
    #cv2.normalize(filtered, filtered, 0, 1, cv2.NORM_MINMAX)
    #g(x, y) = exp(s(x, y))
    #filtered = np.exp(filtered)
    #cv2.normalize(filtered, filtered,0, 1, cv2.NORM_MINMAX)

    show_Proc_fft = tk.Label(homo_frame)
    show_Proc_fft.grid(row = 1 ,column = 1)
    Yl_scale = tk.Scale(homo_frame, label='Yl', from_=-30, to=30, orient=tk.HORIZONTAL, length=500, showvalue=1,tickinterval=10, resolution=0.01, command=homo_process)
    Yh_scale = tk.Scale(homo_frame, label='Yh', from_=-30, to=30, orient=tk.HORIZONTAL, length=500, showvalue=1,tickinterval=10, resolution=0.01, command=homo_process)
    c_scale  = tk.Scale(homo_frame, label='c',  from_=-30, to=30, orient=tk.HORIZONTAL, length=500, showvalue=1,tickinterval=10, resolution=0.01, command=homo_process)
    D0_scale = tk.Scale(homo_frame, label='D0', from_=-30, to=30, orient=tk.HORIZONTAL, length=500, showvalue=1,tickinterval=10, resolution=0.01, command=homo_process)
    Yl_scale.grid(row = 2,column = 1)
    Yh_scale.grid(row = 3,column = 1)
    c_scale.grid(row = 4,column = 1)
    D0_scale.grid(row = 5,column = 1)
    Yl_scale.set(0.4)
    Yh_scale.set(16.15)
    c_scale.set(5)
    D0_scale.set(20)
    homo_process(0)


def freq_new_window():                                                                                          #for show log|f| ,amp ,phase
    global freq_window
    global img_cv2
    new_freq_window_tk = tk.Toplevel(window)
    new_freq_window_tk.geometry("1000x800")
    freq_frame = tk.Frame(new_freq_window_tk)
    #freq_frame.pack(side = tk.TOP)

    '''
    freq_frame.pack(side = tk.TOP)

    log_pic = tk.Label(freq_frame)
    log_pic.grid(rows= 1 , column = 1)

    amp_pic = tk.Label(freq_frame)
    amp_pic.grid(rows= 2 , column = 1)

    phase_pic = tk.Label(freq_frame)
    phase_pic.grid(rows= 2 , column = 2)
    '''

    fft_img = np.fft.fft2(img_cv2)                                                                              #do fft
    shift_fft = np.fft.fftshift(fft_img)                                                                        #shift dc to center
    log = np.log(np.abs(shift_fft))                                                                             #do log
    rshift = np.fft.ifftshift(shift_fft)                                                                        #shift it back
    mag = np.abs(rshift)                                                                                        #mag is intensity
    phase = rshift / mag                                                                                        #phase is mag with value 1
    phase_ifft = np.fft.ifft2(phase)                                                                            #reverse it back
    phase_ifft = np.asarray(phase_ifft,dtype = np.float32)                                  
    amp = np.abs(rshift)                                                                                        #amp only
    amp_ifft = np.fft.ifft2(amp)                                                                                #reverse it back
    amp_ifft = np.asarray(amp_ifft,dtype = np.uint8)
    '''
    show_fft(log,amp,phase)
    '''

    fig = matplotlib.pyplot.figure(figsize=(10,8), dpi=100)   
    plots1 = fig.add_subplot(131)
    plots2 = fig.add_subplot(132)
    plots3 = fig.add_subplot(133)
    plots1.set_title('log|F(u,v)|')
    plots2.set_title('AMP only')
    plots3.set_title('Phase only')
    plots1.imshow(log, cmap = 'gray')
    plots2.imshow(amp_ifft, cmap = 'gray')
    plots3.imshow(phase_ifft, cmap = 'gray')

    canvas = FigureCanvasTkAgg(fig,master = new_freq_window_tk)
    canvas.draw()
    canvas.get_tk_widget().grid(row = 1 ,column = 1)


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
def blur_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    intensity = blur_sharp_scale.get()
    img_mod_ok = 1
    img_mod_cv2 = cv2.blur(img_cv2,(intensity*2+1,intensity*2+1))
    show_proc_img(img_mod_cv2,1)

def sharpen_fun():
    global img_cv2
    global img_mod_cv2
    global img_mod_ok
    intensity = blur_sharp_scale.get()
    img_mod_ok = 1
    blur_fun()
    g_mask = img_cv2 - img_mod_cv2
    img_mod_cv2 = cv2.addWeighted(img_cv2,1,g_mask,intensity/10,0)
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



gray_slicing = tk.Frame(window)
gray_slicing.pack(side= tk.TOP)
sep = ttk.Separator(gray_slicing)                                                                                                                       #new for me , the seperator
sep.grid(row = 1 ,column = 1,columnspan = 6,ipadx=400)
LOW_value = tk.Label(gray_slicing,text = 'LOW value',bg = 'Yellow')
LOW_value.grid(row = 5 ,column = 2)
LOW_scale = tk.Scale(gray_slicing,label = '',from_=0 , to = 255 , orient=tk.HORIZONTAL,length = 400,tickinterval=30 , showvalue = 1,resolution = 1)     #gray-level has two scale :low ,high ,this is low
LOW_scale.set(0)
LOW_scale.grid(row = 6 ,column = 2)
HIGH_value = tk.Label(gray_slicing,text = 'HIGH value',bg = 'Yellow')
HIGH_value.grid(row = 7 ,column = 2)
HIGH_scale = tk.Scale(gray_slicing,label = '',from_=0 , to = 255 , orient=tk.HORIZONTAL,length = 400,tickinterval=30 , showvalue = 1,resolution = 1)    #this is high
HIGH_scale.set(255)
HIGH_scale.grid(row = 8 ,column = 2)
ORIG_slicing = tk.Button(gray_slicing,text = "Preserve original Value"      ,command = ORIG_fun)                                                        #two options : not preserve , to preserve
ORIG_slicing.grid(row = 6 ,column = 1)
ZERO_slicing = tk.Button(gray_slicing,text = "NO preserve original Value"   ,command = ZERO_fun)
ZERO_slicing.grid(row = 8 ,column = 1)


Bit_Plane = tk.Frame(window)
Bit_Plane.pack(side = tk.TOP)
sep_slicing = ttk.Separator(Bit_Plane)                                                                                                                  #line 567
sep_slicing.grid(row = 1 , column = 1 , columnspan = 6 , ipadx = 400)
slicing_scale = tk.Scale(Bit_Plane,label = '',from_=8 , to = 0 , orient=tk.HORIZONTAL,length = 400,tickinterval=1 , showvalue = 1,resolution = 1 , command = print_selection)   #for bit-plane , only one scale indicating which plane to use
slicing_scale.set(0)
slicing_scale.grid(row = 4, column = 4)
Bit_Plane = tk.Label(Bit_Plane,text = 'Bit-Plane images',bg = 'Yellow')
Bit_Plane.grid(row = 3 ,column = 4)

blur_sharp = tk.Frame(window)
blur_sharp.pack(side = tk.TOP)
sep_blur = ttk.Separator(blur_sharp)
sep_blur.grid(row = 1 , column = 1 , columnspan = 6 , ipadx = 400)
blur_sharp_scale = tk.Scale(blur_sharp,label = 'Intensity',from_=8 , to = 0 , orient=tk.HORIZONTAL,length = 400,tickinterval=1 , showvalue = 1,resolution = 1)  #for bit-plane , only one scale indicating what is the intensity (0 for nothing)
blur_sharp_scale.set(0)
blur_sharp_scale.grid(row = 2, column = 2)
blur_but = tk.Button(blur_sharp,text = 'BLUR' , command = blur_fun)
blur_but.grid(row =2 , column = 1)
sharp_but = tk.Button(blur_sharp,text = 'SHARP' ,command = sharpen_fun)
sharp_but.grid(row = 3 , column = 1)

'''
contrast_light = tk.Frame(window)                                                                               # for contrast , light change
contrast_light.pack(side=tk.TOP)
linear_light = tk.Button(contrast_light,text='linearly adjust',width = 20 ,command = linear_button)
linear_light.grid(row = 1 , column = 1)
exp_light = tk.Button(contrast_light,text='exponentially adjust',width = 20 , command = exp_button)
exp_light.grid(row = 2 , column = 1)
ln_light = tk.Button(contrast_light,text='logarithmically adjust',width = 20 , command = ln_button)
ln_light.grid(row = 3 , column = 1)
auto_level = tk.Button(contrast_light,text = 'auto-level',width = 20 , command = auto_level_d)
auto_level.grid(row = 4 ,column = 1)
Label_sc_A = tk.Label(contrast_light,text = 'A value',bg = 'Yellow')
Label_sc_A.grid(row = 1 ,column = 2)
scale_A = tk.Scale(contrast_light,label = '',from_=-2 , to = 2 , orient=tk.HORIZONTAL,length = 400,tickinterval=2 , showvalue = 1,resolution = 0.001)
scale_A.set(1)
scale_A.grid(row = 2 ,column = 2)
Label_sc_B = tk.Label(contrast_light,text = 'B value',bg = 'Yellow')
Label_sc_B.grid(row = 3 ,column = 2)
scale_B = tk.Scale(contrast_light,label = '',from_=-20 , to = 20 , orient=tk.HORIZONTAL,length = 400,tickinterval=10 , showvalue = 1,resolution = 0.001)
scale_B.grid(row = 4 ,column = 2)
'''

hist_Panel = tk.Frame(window)                                                                                   # for show histogram
hist_Panel.pack(side = tk.TOP)
show_hist = tk.Button(hist_Panel , text = 'show Hist' ,command = hist_new_window)
show_hist.grid(row = 2 , column = 2)

freq_Panel = tk.Frame(window)
freq_Panel.pack(side = tk.TOP)
show_freq = tk.Button(freq_Panel , text = 'show Frequency' , command = freq_new_window)                         # for show frequency domain
show_freq.grid(row = 0 , column = 0)

homo_Panel = tk.Frame(window)
homo_Panel.pack(side = tk.TOP)
show_freq = tk.Button(homo_Panel , text = 'Homo adjust' , command = homo_new_window)                            # for show homomorphic filter
show_freq.grid(row = 0 , column = 0)
window.mainloop()