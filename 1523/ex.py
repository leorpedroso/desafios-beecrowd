from collections import deque

while(True):
    N, K = [int(x) for x in input().split()]

    if N == 0 and K == 0:
        break

    stack = deque()
    can_fit = True

    for i in range(N):
        C, S = [int(x) for x in input().split()]
        
        if len(stack) == 0:
            stack.append(S)
        
        else:
            while(len(stack) > 0 and stack[-1] <= C):
                stack.pop()

            if len(stack) == 0 or stack[-1] > S:
                stack.append(S)
            else:
                can_fit = False

            if len(stack) > K:
                can_fit = False

    if can_fit:
        print('Sim')
    else:
        print('Nao')