"""
    File: 1212.py
    Title: 8진수 2진수
    URL: https://www.acmicpc.net/problem/1212
    Input #1:
        314
    Output #1:
        11001100
    Created At: 2020-07-10 20:41:23.674544
"""

from functools import reduce
import sys

list(
    map(
        lambda x: 
            sys.stdout.write(
                str(
                    int(
                        ( x[1] & 4 > 0)
                    )
                )
                +
                str(
                    int(
                        ( x[1] & 2 > 0)
                    )
                )
                +
                str(
                    int(
                        ( x[1] & 1 > 0)
                    )
                ),
            ) if x[0] > 0
            else
                sys.stdout.write(
                    bin(x[1])[2:]
                )
            ,
        enumerate(
            map(
                int,
                list(
                    input()
                )
            )
        )
    )
)