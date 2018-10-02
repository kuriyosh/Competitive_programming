#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file c.py
@brief
@date 2018-09-29
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''
if __name__ == '__main__' :
    n = int(input())
    x = list(input().split())
    a = {}
    b = {}
    ai = 0
    bi = 0
    for i,t in enumerate(x):
        if i % 2 == 0:
            ai += 1
            if t in a:
                a[t] += 1
            else:
                a[t] = 1
        else:
            bi += 1
            if t in b:
                b[t] += 1
            else:
                b[t] = 1

    a_kv = max(a.items(), key=lambda x: x[1])
    b_kv = max(b.items(), key=lambda x: x[1])

    if a_kv[0] == b_kv[0]:
        if a_kv[1] > b_kv[1]:
            if bi - b_kv[1] == 0:
                print(bi)
            else:
                b.pop(b_kv[0])
                b_kv = max(b.items(), key=lambda x: x[1])
                print(ai-a_kv[1]+bi-b_kv[1])
        else:
            if ai - a_kv[1] == 0:
                print(ai)
            else:
                a.pop(a_kv[0])
                a_kv = max(a.items(), key=lambda x: x[1])
                print(ai-a_kv[1]+bi-b_kv[1])
    else:
        print(ai-a_kv[1]+bi-b_kv[1])

