#!/usr/bin/env python
# -*- coding: utf-8 -*-

# filename : a.py
# date : 2018-09-01

# import files

# DEFINE CONSTANT

# DEFINE METHOD
N = int(input())

if (N % 2) == 0:
    ans = (N/2) ** 2
else:
    ans = int(N/2) * int(N/2 + 1)

print(int(ans))
