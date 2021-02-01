"""
    File: 1003.py
    Title: 피보나치 함수
    URL: https://www.acmicpc.net/problem/1003
    Input #1:
        3
        0
        1
        3
    Output #1:
        1 0
        0 1
        1 2
    Created At: 2020-07-22 21:48:48.963102
"""
import sys

zero = [ 1, 0, 1]
one  = [ 0, 1, 1]

for i in range(3, 41):
    zero.append(zero[i - 2] + zero[i - 1])
    one.append(one[i - 2] + one[i - 1])

input()

list(
    map(
        lambda x:
            print("{} {}".format(
                zero[x],
                one[x]
            ))
        ,
        map(
            int,
            sys.stdin.read().split()
        )
    )
)