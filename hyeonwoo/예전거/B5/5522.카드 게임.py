"""
    File: 5522.py
    Title: 카드 게임
    URL: https://www.acmicpc.net/problem/5522
    Input #1:
        1
        2
        3
        4
        5
    Output #1:
        15
    Input #2:
        0
        100
        0
        10
        100
    Output #2:
        210
    Created At: 2020-07-08 14:30:10.083379
"""
import sys
from functools import reduce

print(
    reduce(
        lambda acc, x: acc + x,
        map(
            int,
            sys.stdin.read().split()
        ),
        0
    )
)