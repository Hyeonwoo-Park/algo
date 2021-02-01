"""
    File: 1712.py
    Title: 손익분기점
    URL: https://www.acmicpc.net/problem/1712
    Input #1:
        1000 70 170
    Output #1:
        11
    Created At: 2020-07-13 19:35:36.267664
"""

a, b, c = map(
    int,
    input().split()
)

if b >= c :
    print(-1)
else :
    print(a // (c - b) + 1) 