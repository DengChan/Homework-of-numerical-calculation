import math
import time

def func1(x):
    return x * math.exp(x)


def func2(x):
    return math.exp(x)


def func3(x):
    assert x <= 1
    x = math.exp(x) * math.sqrt(1 - math.pow(x, 2))
    return x

def func4(x):
    return math.pi / 4 * math.sin(math.pi / 4 + math.pi / 4 * x)


def gauss_ch1(func, n: int):
    result = 0.0
    for k in range(1, n + 1):
        new_x = math.cos(((2 * k - 1) / (2 * n)) * math.pi)
        result += func(new_x)
    result = result * math.pi / n
    return result


def gauss_ch2(func, n: int):
    result = 0.0
    for k in range(1, n + 1):
        new_x = math.cos((k * math.pi) / (n + 1))
        result += func(new_x) * math.pow(math.sin((k * math.pi) / (n + 1)), 2)
    result = result * math.pi / (n + 1)
    return result


def Tn(func, a: float, b: float, n=1):
    assert b >= a
    assert n == 1 or n % 2 == 0
    Ts = []
    h_n = (b - a) / 1
    s = func(a + 1 * h_n)
    # 计算T1
    T_n = h_n / 2 * (func(a) + func(b) + 2 * s)
    Ts.append(T_n)
    if n == 1:
        return Ts

    j = 1
    while j != n:
        s2 = 0.0
        for k in range(0, j):
            x_k = a + k * h_n
            x_k_pulus_1 = a + (k + 1) * h_n
            x_k_half = (x_k + x_k_pulus_1) / 2
            s2 += func(x_k_half)
        T_2n = T_n / 2 + h_n / 2 * s2

        # 更新数据
        T_n = T_2n
        h_n = h_n / 2
        j = j * 2
        Ts.append(T_n)
    return Ts


def com_trep(func, a: float, b: float):
    error = 5e-8
    assert b >= a
    n = 1
    h_n = (b - a) / n
    s = 0
    for k in range(1, n):
        x_k = a + k * h_n
        s += func(x_k)
    T_n = h_n / 2 * (func(a) + func(b) + 2 * s)

    flag = True
    while flag:
        s2 = 0.0
        for k in range(0, n):
            x_k = a + k * h_n
            x_k_pulus_1 = a + (k + 1) * h_n
            x_k_half = (x_k + x_k_pulus_1) / 2
            s2 += func(x_k_half)
        T_2n = T_n / 2 + h_n / 2 * s2
        if abs(T_2n - T_n) < 3 * error:
            flag = False

        T_n = T_2n
        h_n = h_n / 2
        n = n * 2
    return T_n


def romberg(func, a: float, b: float):
    n = 2**16
    Ts = Tn(func, a, b, n)
    Ss = []
    for k in range(len(Ts) - 1):
        Ss.append(4 / 3 * Ts[k + 1] - 1 / 3 * Ts[k])
    Cs = []
    for k in range(len(Ss) - 1):
        Cs.append(16 / 15 * Ss[k + 1] - 1 / 15 * Ss[k])
    Rs = []
    for k in range(len(Cs) - 1):
        Rs.append(16 / 15 * Cs[k + 1] - 1 / 15 * Cs[k])
    return Rs[-1]


def gauss_leg_9(func):
    xk_coff = [(0.9681602395, 0.0812743884), (0.8360311073, 0.1806481607),
               (0.6133714327, 0.2606106964), (0.3242534234, 0.3123470770),
               (0, 0.3302393550)]
    result = 0.0
    for k in range(len(xk_coff)):
        xk = xk_coff[k][0]
        Ak = xk_coff[k][1]
        if xk != 0:
            result += Ak * (func(xk) + func(-xk))
        else:
            result += Ak * (func(xk))
    
    return result


if __name__ == '__main__':
    begin_time = time.time()*1000
    r = gauss_ch1(func1, 15)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))
    
    begin_time = time.time()*1000
    r = gauss_ch2(func2, 15)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))

    begin_time = time.time()*1000
    r = com_trep(func3, -1, 1)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))

    begin_time = time.time()*1000
    r = romberg(func3, -1, 1)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))
    
    begin_time = time.time()*1000
    r = gauss_leg_9(func3)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))

    print("======================================================")
    begin_time = time.time()*1000
    r = com_trep(math.sin, 0, math.pi/2)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))

    begin_time = time.time()*1000
    r = romberg(math.sin, 0, math.pi/2)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))
    
    begin_time = time.time()*1000
    r = gauss_leg_9(func4)
    end_time = time.time()*1000
    t = end_time - begin_time
    print(str(r)+'\t'+str(t))
    

