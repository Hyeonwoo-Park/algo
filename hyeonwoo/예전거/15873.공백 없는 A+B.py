"""
    File: 15873.py
    Title: 공백 없는 A+B
    URL: https://www.acmicpc.net/problem/15873
    Input #1:
        37
    Output #1:
        10
    Input #2:
        102
    Output #2:
        12
    Created At: 2020-07-20 22:36:37.636995
"""
from functools import reduce

print(
    reduce(
        lambda acc, x:
            acc + 9 if x == 10
            else acc + x
        ,
        map(
            lambda x:
                10 if x == 0
                else x
            ,
            map(
                int,
                list(
                    input()
                )
            )
        )
    )
)