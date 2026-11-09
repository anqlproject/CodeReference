from collections import deque
def topological_sort(graph):
    # Directed adjacency lists; returns None if a cycle exists.
    indegree = [0] * len(graph)
    for row in graph:
        for v in row:
            indegree[v] += 1
    queue = deque(i for i, d in enumerate(indegree) if d == 0)
    order = []
    while queue:
        u = queue.popleft()
        order.append(u)
        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)
    return order if len(order) == len(graph) else None
if __name__ == "__main__":
    print(topological_sort([[1, 2], [3], [3], []]))
