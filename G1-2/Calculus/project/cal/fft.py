import math
import numpy as np
pi = math.pi


def fft_T(x):
    # must x size must be 2^N
    x = np.asarray(x, dtype=np.complex64)
    n = x.shape[0]

    if n < 8:
        numberList = np.arange(n)
        i = numberList.reshape((n, 1))  # turn to column
        M = np.exp(-2j * pi * i * numberList / n)  # every twiddle factor of all time sector
        return np.dot(x, M)  # matrix dot product

    X_even = fft_T(x[::2])
    X_odd = fft_T(x[1::2])
    twiddleFactor = np.exp(-1j * pi * np.arange(n >> 1) / (n >> 1))  # half
    return np.concatenate([X_even + twiddleFactor * X_odd, X_even - twiddleFactor * X_odd])


def fft_F(log2_N, real, imaginary): 
    # log2_N is the size
    # real, imaginary are the list
    N = 1 << log2_N
    n = 0
    span = N >> 1
    while span > 0:
        root = pi / span
        for submatrix in range(math.floor((N >> 1) / span)):
            for node in range(span):
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

                n += 1
            n = (n + span) & (N - 1)
        span >>= 1

def fft_F(a, num=17):
    n = 0
    span = 1 << (num - 1)
    while span > 0 :
        root = pi/span
        for sudmatrix in range(math.floor((1 << (num-1))/span)):
            for node in range(span):
                nspan = n + span

                tmp = a[n] + a[nspan]
                a[nspan] = a[n] - a[nspan]
                a[n] = tmp

                #this T is the remaintime in a frequency table
                theta = root * node
                a[nspan] *= np.exp(1j * theta)

                n+=1
            n = (n+span) & ((1 << num)-1)
        span >>= 1
    return a



def ifft_T(x):
    x = np.array(x, dtype=complex)
    n = len(x)
    #print(n, type(n))
    half = n//2
    a = np.concatenate((x[half:], x[:half]), axis = None) #shifting, still have bugs
    #print(a)
    output = fft_T(x)
    output = list(reversed(output))
    output.insert(0, output[-1])
    del output[-1]
    return [element / n for element in output]
