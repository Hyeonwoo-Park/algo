"""
    File: 3003.py
    Title: 킹, 퀸, 룩, 비숍, 나이트, 폰
    URL: https://www.acmicpc.net/problem/3003
    Input #1:
        0 1 2 2 2 7
    Output #1:
        1 0 0 0 0 1
    Created At: 2020-07-07 11:32:54.472682
"""

king, queen, rook, bishop, knight, pawn = map(int, input().split())

print("{} {} {} {} {} {}".format(
    1 - king,
    1 - queen,
    2 - rook,
    2 - bishop,
    2 - knight,
    8 - pawn
))