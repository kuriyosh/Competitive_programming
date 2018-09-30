#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file b.py
@brief
@date 2018-09-29
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

if __name__ == '__main__' :
    A = [111,222,333,444,555,666,777,888,999]
    n = int(input())

    for i,a in enumerate(A):
        if n <= a:
            print(A[i])
            exit()
