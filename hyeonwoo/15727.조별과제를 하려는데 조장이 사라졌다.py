"""
    File: 15727.py
    Title: 조별과제를 하려는데 조장이 사라졌다
    URL: https://www.acmicpc.net/problem/15727
    Input #1:
        12
    Output #1:
        3
    Created At: 2020-07-11 20:13:58.957827
"""

L = int(input())

print(L//5 + (L % 5 > 0))