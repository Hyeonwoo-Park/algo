"""
    File: 8437.py
    Title: Julka
    URL: https://www.acmicpc.net/problem/8437
    Input #1:
        10
        2
    Output #1:
        6
        4
    Created At: 2020-07-14 00:59:22.177224
"""

import sys

a, b = map(
    int,
    sys.stdin.read().split()
)

print((a - b) // 2 + b)
print((a - b) // 2)