from collections import deque

N = int(input())


for _ in range(N):
    line = input()
    stack = deque()
    diamonds = 0

    for c in line:
        if c == '<':
            stack.append(c)
        elif c == '>' and len(stack) > 0:
            diamonds += 1
            stack.pop()

    print(diamonds)  