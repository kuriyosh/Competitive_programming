#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file a.py
@brief
@date 2018-09-08
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

if __name__ == '__main__' :
    A = input
    B = ""
    for i in range(0,len(A)):
        if A[i] == '1':
            B += '9'
        elif A[i] == '9':
            B += '1'
        else:
            B += A[i]
    print(B)
