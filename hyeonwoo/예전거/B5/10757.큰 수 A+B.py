"""
    File: 10757.py
    Title: 큰 수 A+B
    URL: https://www.acmicpc.net/problem/10757
    Input #1:
        9223372036854775807 9223372036854775808
    Output #1:
        18446744073709551615
    Created At: 2020-07-09 16:08:18.428174
"""

from functools import reduce

print(
    reduce(
        lambda acc, x: acc + x,
        map(
            int,
            input().split()
        ),
        0
    )
)