def count_families():
    count = 0

    for k, v in persons.items():
        if k in visited:
            continue

        count += 1
        for val in v:
            set_visited(val)

    return count

def set_visited(name):
    visited[name] = True
    for n in persons[name]:
        if n not in visited:
            set_visited(n)

M, N = [int(x) for x in input().split()]
persons = {}
visited = {}

for i in range(N):
    person1, _, person2 = input().split()

    if person1 not in persons:
        persons[person1] = [person2]
    else:
        persons[person1].append(person2)

    if person2 not in persons:
        persons[person2] = [person1]
    else:
        persons[person2].append(person1)

print(count_families())
