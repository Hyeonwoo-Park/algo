"""
    File: 10768.py
    Title: 특별한 날
    URL: https://www.acmicpc.net/problem/10768
    Input #1:
        1
        7
    Output #1:
        Before
    Input #2:
        8
        31
    Output #2:
        After
    Input #3:
        2
        18
    Output #3:
        Special
    Created At: 2020-07-18 23:39:14.642711
"""

import sys 
from functools import reduce

def f(month, day):
    if month < 2:
        return "Before"
    elif month == 2:
        if day < 18:
            return "Before"
        elif day == 18:
            return "Special"
        else:
            return "After"
    else:
        return "After"


print(
    reduce(
        f,
        map(
            int,
            sys.stdin.read().split()
        )
    )
)