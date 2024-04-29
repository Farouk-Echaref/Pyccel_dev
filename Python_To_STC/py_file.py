def declare_list():
    a: list[int]
    b: list[float]

    a.append(1)
    b.append(2)

    for i in range(5):
        a.append(i)
