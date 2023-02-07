import heapq

N, M = [int(x) for x in input().split(' ')]

cashiers = [int(x) for x in input().split(' ')]
clients = [int(x) for x in input().split(' ')]

heap = [[0, i] for i in range(N)]

for client in clients:
    tuple = heapq.heappop(heap)
    prio = client * cashiers[tuple[1]]
    tuple[0] += prio
    heapq.heappush(heap, tuple)

print(max(heap)[0])
