#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file b.py
@brief 
@date 2018-09-08
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

if __name__ == '__main__' :
    N = int(input())
    ws = []
    for i in range(0,N):
        ws.append(input())

    if len(ws) != len(set(ws)):
        print('No')
        exit()
        
    before = ws[0][0]
    for w in ws:
        if before != w[0]:
            print('No')
            exit()
        else:
            before = w[len(w)-1]
                  
    print('Yes')
