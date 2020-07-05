from functools import reduce

print(
    reduce(lambda acc, x: (acc + x) % 10,
        map(lambda x: x * x, 
            map(int ,input().split())
        )
    )
)