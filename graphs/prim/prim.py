import heapq
def prim(graph, start=0):
    # Undirected weighted adjacency lists (neighbor, weight); returns None if disconnected.
    n = len(graph)
    if n == 0:
        return (0, [])
    seen, heap, chosen, total = {start}, [], [], 0
    for v, w in graph[start]:
        heapq.heappush(heap, (w, start, v))
    while heap and len(seen) < n:
        w, u, v = heapq.heappop(heap)
        if v in seen:
            continue
        seen.add(v)
        chosen.append((u, v, w))
        total += w
        for x, cost in graph[v]:
            if x not in seen:
                heapq.heappush(heap, (cost, v, x))
    return (total, chosen) if len(seen) == n else None
if __name__ == "__main__":
    print(prim([[(1, 4), (2, 5)], [(0, 4), (2, 2)], [(0, 5), (1, 2)]]))
