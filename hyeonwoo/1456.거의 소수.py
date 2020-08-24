"""
    File: 1456.py
    Title: 거의 소수
    URL: https://www.acmicpc.net/problem/1456
    Input #1:
        1 1000
    Output #1:
        25
    Created At: 2020-08-10 20:57:23.094229
"""
import math

a, b = map(int,input().split())
rootB = int(math.sqrt(b))
cnt = 0
fltr = [0] * (rootB + 1)

for i in range(2, rootB + 1):
    if fltr[i] == 1 : 
        continue

    tmp = i * i
    while tmp <= b:
        if tmp >= a and tmp <= b:
            cnt += 1
        
        tmp *= i
    
    tmp = i

    while tmp <= rootB:
        fltr[tmp] = 1
        tmp += i

print(cnt)