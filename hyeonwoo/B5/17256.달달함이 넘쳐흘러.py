"""
    File: 17256.py
    Title: 달달함이 넘쳐흘러
    URL: https://www.acmicpc.net/problem/17256
    Input #1:
        15 16 17
        19 32 90
    Output #1:
        2 2 75
    Input #2:
        15 8 15
        22 8 22
    Output #2:
        7 1 7
    Created At: 2020-07-14 01:09:23.581633
"""
import sys
from functools import reduce

print(
    reduce(
        lambda acc, x:
            "{} {} {}".format(x[0] - acc[0], x[1] // acc[1], x[2] - acc[2]),
        map(
            lambda x:
                x[1] if x[0] == 1
                else list(reversed(x[1]))
            ,
            filter(
                lambda x:
                    x[0] < 2,
                enumerate(
                    map(
                        lambda x:
                            list(
                                map(
                                    int,
                                    x.split()
                                )
                            )
                        ,
                        sys.stdin.read().split('\n')
                    )
                )
            )
            
        )
    )
)