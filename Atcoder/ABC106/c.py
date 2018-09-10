#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file c.py
@brief 
@date 2018-09-10
'''
import sys


if __name__ == '__main__' :
    
    S = input()
    K = int(input())

    # Sが1で始まりかつKの長さがまで1が続くようであれば1
    for i in range(0,K):
        if S[i] == '1' and i < K:
            continue
        elif S[i] != '1':
            print(S[i])
            exit()
    print('1')
            
