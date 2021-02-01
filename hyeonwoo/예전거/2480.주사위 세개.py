"""
    File: 2480.py
    Title: 주사위 세개
    URL: https://www.acmicpc.net/problem/2480
    Input #1:
        3 3 6
    Output #1:
        1300
    Created At: 2020-07-15 11:44:04.753759
"""

a, b, c = sorted(
                map(
                    int,
                    input().split()
                )
            )

if a == b:
    if b == c:
        print(
            10000 + a * 1000
        )
    else :
        print(
            1000 + a * 100
        )
elif b == c:
    print(
        1000 + b * 100
    )
else :
    print(
        c * 100
    )