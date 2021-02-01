from functools import reduce

area = reduce(lambda acc,x : acc * x, 
                list(map(int, input().split())),
                1)

diffs = list(
            map(
                lambda x: int(x) - area, 
                input().split()
            )
        )

for diff in diffs:
    print(diff, end=" ")