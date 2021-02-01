"""
    File: 1016.py
    Title: 제곱 ㄴㄴ 수
    URL: https://www.acmicpc.net/problem/1016
    Input #1:
        1 10
    Output #1:
        7
    Created At: 2020-08-28 01:56:41.411554
"""
import math

st, ed = map(int, input().split())

count = 0
visit = [0] * (ed - st + 1)

for i in range(2, int(math.sqrt(ed)) + 1):
    num = i * i

    for j in range((st // num) * num, ed + 1, num):
        if j < st or visit[j - st] == 1:
            continue

        visit[j - st] = 1

for i in range(st, ed + 1):
    if visit[i - st] == 0:
        count += 1


print(count)
