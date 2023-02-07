# https://www.interviewcake.com/concept/python3/topological-sort 

def topological_sort(digraph):
    # digraph is a dictionary:
    #   key: a node
    # value: a set of adjacent neighboring nodes

    # construct a dictionary mapping nodes to their
    # indegrees
    outdegrees = {node : 0 for node in digraph}
    for node in digraph:
        for neighbor in digraph[node]:
            outdegrees[neighbor] += 1

    # track nodes with no incoming edges
    nodes_with_no_outgoing_edges = []
    for node in digraph:
        if outdegrees[node] == 0:
            nodes_with_no_outgoing_edges.append(node)

    # initially, no nodes in our ordering
    topological_ordering = [] 

    time = {node : 1 for node in digraph}

    # as long as there are nodes with no incoming edges
    # that can be added to the ordering 
    while len(nodes_with_no_outgoing_edges) > 0:

        # add one of those nodes to the ordering
        node = nodes_with_no_outgoing_edges.pop()
        topological_ordering.append(node)

        # decrement the indegree of that node's neighbors
        for neighbor in digraph[node]:
            outdegrees[neighbor] -= 1
            if outdegrees[neighbor] == 0:
                nodes_with_no_outgoing_edges.append(neighbor)
                time[neighbor] = max(time[neighbor], time[node] + 1)

    # we've run out of nodes with no incoming edges
    # did we add all the nodes or find a cycle?
    if len(topological_ordering) == len(digraph):
        return max(time.values())  # got them all
    else:
        return -1


while(True):
    try:
        N = int(input())
        digraph = {node : [] for node in range(1, N+1)}
        
        for i in range(1, N+1):
            inp = [int(x) for x in input().split()]

            for j in inp[1:]:
                digraph[j].append(i)

        res = topological_sort(digraph)
        print(res)

    except Exception as err:
        break

