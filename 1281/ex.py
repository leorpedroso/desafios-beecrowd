test_cases = int(input())

for i in range(test_cases):
    total_items = int(input())

    items = {}
    for i in range(total_items):
        a = input()
        a = a.split(' ')
        items[a[0]] = float(a[1])

    items_to_buy = int(input())

    total = 0
    for i in range(items_to_buy):
        a = input()
    
        a = a.split(' ')
        total += items[a[0]] * int(a[1])

    print(f'R$ {total:.2f}')