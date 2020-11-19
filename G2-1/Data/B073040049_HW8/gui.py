import tkinter as tk
from tkinter import messagebox
import subprocess
import shlex
import math
import os
from sys import platform as _platform
current_os = ""
if _platform == "linux" or _platform == "linux2":
    current_os = "linux"
elif _platform == "win32":
    current_os = "windows"
elif _platform == "win64":
    current_os = "windows"


window = tk.Tk()
window.title('Compress GUI')
window.geometry('800x800')
window.configure(background='white')

now_dir = "./"

def ls():
    global now_dir
    now_dir = currentdir_entry.get()
    os.chdir(now_dir)
    T_lword = "All the files or directory\n"
    HUFF_entry.delete(0,'end')
    currentdir_entry.delete(0,'end')
    for f in os.listdir(now_dir):
        if os.path.isfile(os.path.join(now_dir, f)):
            T_lword += "file:\t"+str(f)+"\n"
            if (((f.find("huffman") == 0 )and(current_os == "linux" )and(f.find("exe") ==-1))or((f.find("huffman") == 0 )and(current_os == "windows" )and(f.find("exe") !=-1))):
                HUFF_entry.delete(0,'end')
                HUFF_entry.insert(0,f)
        else:
            T_lword += "dir:\t"+str(f)+"\n"
    ls_label.configure(text = T_lword,justify = 'left',anchor = 'w')
    currentdir_label.configure(text = "current at: "+os.getcwd(),justify = 'left',anchor = 'w')
    currentdir_entry.insert(0,now_dir)
def compress():
    command = ""
    command += "./"+HUFF_entry.get()+" "
    command += "-c "
    command += "-i "+input_entry.get()
    command += " -o "+output_entry.get()
    print(command)
    subprocess.call(shlex.split(command))
    messagebox.showinfo( "Hello Python", "DONE")
def uncompress():
    command = ""
    command += "./"+HUFF_entry.get()+" "
    command += "-u "
    command += "-i "+input_entry.get()
    command += " -o "+output_entry.get()
    print(command)
    subprocess.call(shlex.split(command))
    messagebox.showinfo( "Hello Python", "DONE")
    
    
dirs = tk.Frame(window)
dirs.pack(side=tk.TOP)
currentdir_label = tk.Label(dirs,justify = 'left' , anchor = 'w')
currentdir_label.pack()
v = tk.StringVar(dirs,value = os.getcwd())
currentdir_entry = tk.Entry(dirs ,textvariable = v,width = 500)
currentdir_entry.pack()
calculate_btn = tk.Button(dirs, text='Change Dir', command=ls)
calculate_btn.pack()

ls_label = tk.Label(dirs,justify = 'left',anchor = 'w')
ls_label.pack()

HUFF_frame = tk.Frame(window)
HUFF_frame.pack(side=tk.TOP)
HUFF_label = tk.Label(HUFF_frame, text='HUFF executable')
HUFF_label.pack(side=tk.LEFT)
HUFF_entry = tk.Entry(HUFF_frame)
HUFF_entry.pack(side=tk.LEFT)

input_frame = tk.Frame(window)
input_frame.pack(side=tk.TOP)
input_label = tk.Label(input_frame, text='Input file')
input_label.pack(side=tk.LEFT)
input_entry = tk.Entry(input_frame)
input_entry.pack(side=tk.LEFT)

output_frame = tk.Frame(window)
output_frame.pack(side=tk.TOP)
output_label = tk.Label(output_frame, text='Output file')
output_label.pack(side=tk.LEFT)
output_entry = tk.Entry(output_frame)
output_entry.pack(side=tk.LEFT)

compress_frame = tk.Frame(window)
compress_frame.pack(side=tk.TOP)
compress_but = tk.Button(compress_frame, text='compress file',command = compress)
compress_but.pack(side=tk.LEFT)
uncompress_but = tk.Button(compress_frame, text='uncompress file',command = uncompress)
uncompress_but.pack(side=tk.LEFT)


window.mainloop()
