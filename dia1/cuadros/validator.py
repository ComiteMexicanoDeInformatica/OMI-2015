#!/usr/bin/python
# -*- coding: utf-8 -*-
 
# Los mundos se tienen que llamar N.in
# Es decir, para un mundo de 3x3, el caso debe llamarse 3.in
 
import libkarel
import sys
import math
import traceback

percent = [50, 35, 31, 31]
 
ans = { 1:  0,
        2:  1,
        3:  2,
        4:  4,
        5:  6,
        6:  9,
        7:  12,
        8:  17,
        9:  21,
        10:  27,
        11:  32,
        12:  40,
        13:  46,
        14:  54,
        15:  62,
        16:  72,
        17:  81,
        18:  92,
        19:  102,
        20:  116,
        21:  127,
        22:  140,
        23:  152,
        24:  167,
        25:  183,
        26:  197,
        27:  212,
        28:  228,
        29:  247,
        30:  263,
        31:  286,
        32:  301,
        33:  323,
        34:  340,
        35:  366,
        36:  383,
        37:  413,
        38:  429,
        39:  458,
        40:  476,
        41:  509,
        42:  527,
        43:  564,
        44:  581,
        45:  617,
        46:  636,
        47:  676,
        48:  695,
        49:  739,
        50:  757,
        51:  800,
        52:  818,
        53:  850,
        54:  885,
        55:  921,
        56:  955,
        57:  990,
        58:  1024,
        59:  1048,
        60:  1099,
        61:  1127,
        62:  1177,
        63:  1204,
        64:  1254,
        65:  1270,
        66:  1337,
        67:  1357,
        68:  1423,
        69:  1442,
        70:  1508,
        71:  1516,
        72:  1599,
        73:  1611,
        74:  1693,
        75:  1704,
        76:  1786,
        77:  1786,
        78:  1885,
        79:  1889,
        80:  1987,
        81:  1990,
        82:  2088,
        83:  2080,
        84:  2195,
        85:  2191,
        86:  2305,
        87:  2300,
        88:  2414,
        89:  2398,
        90:  2529,
        91:  2517,
        92:  2647,
        93:  2634,
        94:  2764,
        95:  2740,
        96:  2887,
        97:  2867,
        98:  3013,
        99:  2992,
        100: 3071
}
 
def valid(N, beeper_dict):
    beepers = [[True for i in range(N)] for i in range(N)]
    left = [[0 for i in range(N)] for i in range(N)]
    down = [[0 for i in range(N)] for i in range(N)]
 
    for (r,c) in beeper_dict.keys():
        beepers[r-1][c-1] = False
 
    for i in range(N):
        for j in range(N):
            if beepers[i][j]:
                left[i][j] = 1 + (left[i][j-1] if j > 0 else 0)
                down[i][j] = 1 + (down[i-1][j] if i > 0 else 0)
 
    for i in range(N):
        for j in range(N):
            if beepers[i][j]:
                for k in range(1,N):
                    if i-k < 0 or j-k < 0 or not beepers[i-k][j] or not beepers[i][j-k]:
                        break
                    elif down[i][j-k] > k and left[i-k][j] > k:
                         raise Exception('no hay cuadro en {},{} {}'.format(i,j,k))
 
    return True
 
score = 0
 
try:
    k_in, k_out, test_case = libkarel.load()
 
    if k_out.resultado != 'FIN PROGRAMA':
        raise Exception('EXECUTION FAILURE')
 
    try:
        Ts, _, Ns = test_case.partition('.')
        T = int(Ts)
        N = int(Ns)
    except Exception as e:
        T = len(percent)-1
        N = int(test_case)

    count = len(k_out._zumbadores)

    if not valid(N, k_out._zumbadores):
        raise Exception('INVALID')

    if T < len(percent)-1:
        score = 1 if 100 * count <= percent[T] * N * N else 0
    else:
        lim = percent[T] / 100.0 * N * N
        score = 1 - float(count - ans[N]) / (lim - ans[N])

    score = max(min(score, 1.0), 0.0)

    sys.stderr.write("res {}\tmin {}\tscore {} ".format(count, ans[N], score))
except Exception as e:
    sys.stderr.write(traceback.format_exc())
finally:
    print score
