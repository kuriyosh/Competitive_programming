#!/usr/bin/env python
# -*- coding: utf-8 -*-

# filename : c.py
# date : 2018-09-01

# import files

# DEFINE CONSTANT

# DEFINE METHOD
N,K = map(int, input().split())

ans = int(N/K) ** 3
if K%2 == 0:
    ans += int(N/int(K/2) - int(N/K)) ** 3
    
print(ans)
