"""
    File: 15964.py
    Title: 이상한 기호
    URL: https://www.acmicpc.net/problem/15964
    Input #1:
        4 3
    Output #1:
        7
    Input #2:
        3 4
    Output #2:
        -7
    Created At: 2020-07-10 23:53:27.913668
"""

a,b = map(int, input().split())

print((a + b) * (a - b))