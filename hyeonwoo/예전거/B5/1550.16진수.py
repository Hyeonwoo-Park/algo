from functools import reduce

def f1(x) :
    if(x >= 'A' and x <= 'F'): 
        return (ord(x) - 65 + 10)
    return int(x)

def f2(acc, x) :
    acc *= 16
    acc += x

    return acc

n = reduce( f2, list(map(f1, list(input()))), 0)

print(n)