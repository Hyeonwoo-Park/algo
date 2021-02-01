"""
    File: 8370.py
    Title: Plane
    URL: https://www.acmicpc.net/problem/8370
    Input #1:
        2 5 3 20
    Output #1:
        70
    Created At: 2020-07-09 16:02:16.947036
"""

from functools import reduce

inp = list(
        map(
            int,
            input().split()
        )
    )

print(
    inp[0] * inp[1] + inp[2] * inp[3]
)