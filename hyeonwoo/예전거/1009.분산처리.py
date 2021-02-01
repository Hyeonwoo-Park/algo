"""
    File: 1009.py
    Title: 분산처리
    URL: https://www.acmicpc.net/problem/1009
    Input #1:
        5
        1 6
        3 7
        6 2
        7 100
        9 635
    Output #1:
        1
        7
        6
        1
        9
    Created At: 2020-07-17 17:17:27.801993
"""
import sys
from functools import reduce

input()

list(
    map(
        lambda x:
            print(x % 10) if x % 10
            else print(10)
        ,
        map(
            lambda x:
                reduce(
                    lambda acc, x:
                        reduce(
                            lambda acc2, x:
                                acc2 * acc % 10
                            ,
                            [None] * (x-1)
                            ,
                            acc
                        )
                    ,
                    map(
                        int,
                        x.split()
                    )
                )
            ,
            filter(
                lambda x:
                    x != "",
                sys.stdin.read().split('\n')
            )
        )
    )
)