import matplotlib.pyplot as plt
import time
%matplotlib inline
def testFFT_F():
    l = list(range(1<<num))
    im = [0]*(1<<num)
    fft_F(num, l, im)
    result = []
    for i in range(1<<num):
        result.append(complex(l[i], im[i]))
    result = np.array(result)
    print(*result)


def testFFT_T():
    l = fft_T(list(range(1<<num)))
    print(*l,sep='\n')
    print(len(l))

def numpyFFT():
    l = np.fft.fft(list(range(1<<num)))
    print(*l,sep='\n')
    print(len(l))

def speedTest():
    start = time.time()
    testFFT_F()
    end = time.time()
    print(end-start)
    print()

    start = time.time()
    testFFT_T()
    end = time.time()
    print(end-start)
    print()

    start = time.time()
    numpyFFT()
    end = time.time()
    print(end-start)


def testChangeToFreqGraph():
    l = list(range(1<<num))
    im = [0]*(1<<num)
    fft_F(num, l, im)
    radius = []
    for i in range (len(l)):
        radius.append(math.sqrt((l[i]**2) + (im[i]**2)))
    #print(radius)

def fullGraph(raw_FFT):
    freq = [0]*((1<<num)+1)
    for i in raw_FFT:
        m = np.angle(i) 
        if(m<0):
            m += 2*pi
        freq[int(round(m*(1<<num)/2/pi,0))] += int(np.abs(i))
    
    plt.plot(freq)
    plt.show()
    #print(freq)
