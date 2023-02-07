l = input()
arr = [int(a) for a in l.split(' ')]

if len(set(arr)) != len(arr):
    print('S')

else:
    if (arr[0] + arr[1] == arr[2]) or \
        (arr[2] + arr[1] == arr[0]) or \
        (arr[0] + arr[2] == arr[1]):
        print('S')
    else:
        print('N')