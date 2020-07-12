"""
    File: 5596.py
    Title: 시험 점수
    URL: https://www.acmicpc.net/problem/5596
    Input #1:
        100 80 70 60
        80 70 80 90
    Output #1:
        320
    Created At: 2020-07-12 23:40:36.800980
"""
import sys
from functools import reduce

S = reduce(
    lambda acc, x:
        max(acc, x),
    map(
        lambda x:
            reduce(
                lambda acc, x : acc + x,
                x,
                0
            ),
        map(
            lambda x:
                list(
                    map(
                        int,
                        x
                    )
                ),
            map(
                lambda x : x.split(),
                map(
                    lambda x : x,
                    sys.stdin.read().split('\n')
                ),
            )
        )
    ),
    0
)

print(S)
