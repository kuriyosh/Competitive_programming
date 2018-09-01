#!/usr/bin/env python
# -*- coding: utf-8 -*-

# filename : b.py
# date : 2018-09-01

# import files

# DEFINE CONSTANT

# DEFINE METHOD
x1,y1,x2,y2 = map(int, input().split())

x3 = y1 - y2 + x2
y3 = -x1 + x2 + y2

x4 = y2 - y3 + x3
y4 = -x2 + x3 + y3

print (x3,y3,x4,y4)
