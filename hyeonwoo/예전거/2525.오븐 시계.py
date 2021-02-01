"""
    File: 2525.py
    Title: 오븐 시계
    URL: https://www.acmicpc.net/problem/2525
    Input #1:
        14 30
        20
    Output #1:
        14 50
    Created At: 2020-07-15 12:41:08.545159
"""

h, m = map(
    int,
    input().split()
)

t = int(
    input()
)

h = ( (m + t) // 60 + h) % 24
m = (m + t) % 60

print("{} {}".format(h, m))