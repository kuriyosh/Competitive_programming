#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file a.py
@brief 
@date 2018-09-08
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

if __name__ == '__main__' :
    A,B = list(map(int, input().split()))
    if A%2 == 0 or B%2 == 0:
        print('No')
    else:
        print('Yes')
