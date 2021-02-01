"""
    File: 5554.py
    Title: 심부름 가는 길
    URL: https://www.acmicpc.net/problem/5554
    Input #1:
        31
        34
        7
        151
    Output #1:
        3
        43
    Created At: 2020-07-09 15:56:44.086331
"""

import sys
from functools import reduce

total = reduce(
    lambda acc, x: acc + x,
    map(
        int,
        sys.stdin.read().split()
    ),
    0
)
print(total // 60)
print(total % 60)