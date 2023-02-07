
list1 = input().split()
list2 = input().split()
op = input()

if (op == 'nao'):
    print(' '.join(list1 + list2))
else:
    index = list1.index(op)
    print(' '.join(list1[:index] + list2 + list1[index:]))