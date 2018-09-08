#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file c.py
@brief 
@date 2018-09-08
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

import numpy as np

def gcd(x, y):
    r = modlog(x, y)
    while r != 0:
        x = y
        y = r
        r = modlog(x, y)
    return y

def modlog(x, y):
    r = x % y
    return r

if __name__ == '__main__' :
    N,X = map(int, input().split())
    x = list(map(int, input().split()))

    dist_list = [abs(d-X) for d in x]

    if len(dist_list) == 1:
        print (dist_list[0])
        exit()
        
    alpha = gcd(dist_list[0],dist_list[1])
    for d in dist_list:
        alpha = gcd(alpha,d)

    print(alpha)        
