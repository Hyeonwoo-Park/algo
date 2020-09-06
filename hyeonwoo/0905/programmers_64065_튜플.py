import re
from functools import reduce


def solution(s):
    return reduce(
        lambda acc, x:
            acc+[
                next(
                    filter(
                        lambda y:
                        y not in acc,
                        x
                    )
                )],
        sorted(
            map(
                lambda x:
                    list(
                        map(
                            int,
                            x.split(',')
                        )
                    ),
                map(
                    lambda x:
                        x.strip("{}"),
                    re.findall(r'{[0-9,]*}', s[1:-1])
                    )
            ), key=len
        ),
        []
    )
