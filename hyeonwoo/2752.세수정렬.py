"""
    File: 2752.py
    Title: 세수정렬
    URL: https://www.acmicpc.net/problem/2752
    Input #1:
        3 1 2
    Output #1:
        1 2 3
    Created At: 2020-07-17 17:00:33.470522
"""
from functools import reduce

print(
    reduce(
        lambda acc, x:
            str(acc) + " " + str(x),
        sorted(
            map(
                int,
                input().split()
            )
        )   
    )
)