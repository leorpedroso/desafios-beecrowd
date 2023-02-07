# https://bradfieldcs.com/algos/graphs/dijkstras-algorithm/

import heapq

def dijkstra(graph, start, num_nodes, service_costs):

    dist = {v : float('inf') for v in graph}
    dist[start] = 0

    heap = [(0, start)]
    while heap:
        (cost, v) = heapq.heappop(heap)

        if cost > dist[v]:
            continue

        for neighbor, weight in graph[v].items():
            # if neighbor in service_path
        
            if neighbor >= len(service_costs):
                distance = cost + weight
                if distance < dist[neighbor]:
                    dist[neighbor] = distance
                    heapq.heappush(heap, (distance, neighbor))
            else:
                distance = cost + weight + service_costs[neighbor]
                if distance < dist[len(service_costs)-1]:
                    dist[len(service_costs)-1] = distance

    return dist


while(True):
    try:
        N,M,C,K = [int(x) for x in input().split()]
        # N,M,C,K = 6,7,2,5
        if (N == 0 and M==0 and C==0 and K==0):
            break

        service_costs = [0] * C # maps starting vertex to cost to reach destination
        graph = {}
        for i in range(N):
            graph[i] = {}


        for i in range(M):
            city1, city2, cost = [int(x) for x in input().split()]
            if (((city1 == city2 +1) or (city1+1 == city2)) and max(city1, city2) < C):
                service_costs[min(city1, city2)] = cost

            # define graph edge weigths after service_costs
            graph[city1][city2] = cost
            graph[city2][city1] = cost


        for i in range(C-2, -1, -1): # start from penultimate node, go backwards
            service_costs[i] += service_costs[i+1]

        # for c1 in graph: # gives key
        #     for c2 in graph[c1]:
        #         if(c1 >= C and c2 < C-1):
        #             graph[c1][c2] += service_costs[c2]
        #             graph[c2][c1] += service_costs[c2]

        # graph = {0: {1: 1, 3: 2}, 1: {2: 10, 0: 1}, 2: {5: 1, 1: 10}, 3: {0: 2, 4: 2, 5: 3}, 4: {3: 2, 5: 2}, 5: {2: 1, 3: 3, 4: 2}}
        # service_costs = [1, 0]
        # print(graph)
        # print(service_costs)
        res = dijkstra(graph, K, N, service_costs)
        # print(res)
        print(res[C-1])
        # print(dijkstra(graph, K, N, service_costs))
        # break
    except Exception as e:
        # print(e)
        break