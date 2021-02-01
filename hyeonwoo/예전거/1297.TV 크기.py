"""
    File: 1297.py
    Title: TV 크기
    URL: https://www.acmicpc.net/problem/1297
    Input #1:
        52 9 16
    Output #1:
        25 45
    Created At: 2020-07-15 10:48:36.618570
"""

a, b, c = map(
    int, input().split()
)

print( "{} {}".format(
        int( ( a * a * b * b / (b * b + c * c) ) ** 0.5),
        int( ( a * a * c * c / (b * b + c * c) ) ** 0.5)
    )
)