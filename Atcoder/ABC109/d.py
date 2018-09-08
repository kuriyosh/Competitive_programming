#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
@file d.py
@brief 
@date 2018-09-08
@author Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp
'''

a = []
# 近隣に奇数がいるか調査
def check_neghbar(i,j):
    # 下
    if i != H-1:
        if j > 0 and a[i][j-1] % 2 == 1:
            return True
        elif j != W-1 and a[i][j+1] % 2 == 1:
            return True
        elif i != H-1 and a[i+1][j] % 2 == 1:
            return True
    # 右
    elif j != W-1:
        if j+1 != W-1 and a[i][j+1] % 2 == 1:
            return True
        elif i != H-1 and a[i+1][j] % 2 == 1:
            return True
    return False

if __name__ == '__main__' :
    H,W = list(map(int, input().split()))
    
    for i in range(0,H):
        a.append(list(map(int, input().split())))

    sousa = []
    for i in range(0,H):
        for j in range(0,W):
            if a[i][j] == 0:
                continue
            if a[i][j] % 2 == 1:
                # 隣接する奇数に移動
                if i > 0 and a[i-1][j] % 2 == 1:
                    a[i-1][j] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i-1,j])
                    continue
                elif j > 0 and a[i][j-1] % 2 == 1:
                    a[i][j-1] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i,j-1])
                    continue
                elif i < H-1 and a[i+1][j] % 2 == 1:
                    a[i+1][j] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i+1,j])
                    continue
                elif j < W-1 and a[i][j+1] % 2 == 1:
                    a[i][j+1] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i,j+1])
                    continue
                # これからルックアップが行われる(奇数と隣接する偶数に移動)
                elif i < H-1 and check_neghbar(i+1,j):
                    a[i+1][j] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i,j+1])
                    continue
                elif j < W-1 and check_neghbar(i,j+1):
                    a[i][j+1] += 1
                    a[i][j] -= 1
                    sousa.append([i,j,i,j+1])
                    continue
                
    for tate in sousa:
        res = map(lambda x: x+1, tate)
        print(' '.join(map(str, res)))
