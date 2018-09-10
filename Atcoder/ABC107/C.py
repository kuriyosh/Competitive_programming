#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file C.py
@brief 
@date 2018-09-06
'''
import sys

if __name__ == '__main__' :
    
    N,K = map(int, input().split())
    x = list(map(int, input().split()))

    min_dis = sys.maxsize
    for i in range(0,N-K+1):
        l = i
        r = i + K - 1 
        # 左に行った後に右に行くパターン
        dis_l = abs(x[l]) + abs(x[r]-x[l])
        # 右に行った後に左に行くパターン
        dis_r = abs(x[r]) + abs(x[r]-x[l])
        min_dis = min(min_dis,dis_l,dis_r)
    print(min_dis)
