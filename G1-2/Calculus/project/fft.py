import math
import numpy as np
import time
pi = math.pi

def fft_T(x):
    # must x size must be 2^N
    x = np.asarray(x, dtype=float)
    n = x.shape[0]

    if n <= 32:
        numberList = np.arange(n)
        i = numberList.reshape((n, 1))   # turn to column
        M = np.exp(-2j * pi * i * numberList / n)
        return np.dot(x, M)

    X_even = fft_T(x[::2])
    X_odd = fft_T(x[1::2])
    twiddleFactor = np.exp(-1j * pi * np.arange(n/2) / (n/2)) # half
    return np.concatenate([X_even + twiddleFactor * X_odd, X_even - twiddleFactor * X_odd])


def fft_F(log2_N, real, imaginary):
    # log2_N is the size
    # real, imaginary are the list
    print("fft start")
    N = 1 << log2_N
    n = 0
    span = N >> 1
    while span > 0:
        root = pi / span
        for submatrix in range( math.floor((N>>1)/span)):
            for node in range( span ):
                nspan = n + span
                temp = real[n] + real[nspan]
                real[nspan] = real[n] - real[nspan]
                real[n] = temp
                temp = imaginary[n] + imaginary[nspan]
                imaginary[nspan] = imaginary[n] - imaginary[nspan]
                imaginary[n] = temp

                theta = root * node
                realTwiddleVector = math.cos(theta)
                imaginaryTwiddleVector = math.sin(theta)
                temp = realTwiddleVector * real[nspan] - imaginaryTwiddleVector * imaginary[nspan]
                imaginary[nspan] = realTwiddleVector * imaginary[nspan] + imaginaryTwiddleVector * real[nspan]
                real[nspan] = temp
                
                n+=1
            n = (n + span) & (N-1) 
        span >>= 1

def testFFT_F():
    num = 15
    l = list(range(1<<num))
    im = [0]*(1<<num)
    fft_F(num, l, im)
    result = [0]*(1<<num)
    for i in range(1<<num):
        result[i] = complex(l[i], im[i])
    print(result)


def testFFT_T():
    num = 15
    l = fft_T(list(range(1<<num)))
    print(l)

def numpyFFT():
    num = 15
    l = np.fft.fft(list(range(1<<num)))

start = time.time()
testFFT_F()
end = time.time()
print(end-start)

start = time.time()
testFFT_T()
end = time.time()
print(end-start)

start = time.time()
numpyFFT()
end = time.time()
print(end-start)
