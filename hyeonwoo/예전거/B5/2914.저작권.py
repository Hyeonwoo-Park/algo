"""
    File: 2914.py
    Title: 저작권
    URL: https://www.acmicpc.net/problem/2914
    Input #1:
        38 24
    Output #1:
        875
    Created At: 2020-07-07 11:22:15.262672
"""

A, l = map(int, input().split())

print(A * (l - 1) + 1)