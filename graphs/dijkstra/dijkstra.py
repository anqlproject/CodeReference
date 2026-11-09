import heapq
def dijkstra(graph, start):
    # Weighted adjacency lists (neighbor, weight); all weights must be nonnegative.
    dist = [float("inf")] * len(graph)
    dist[start] = 0
    heap = [(0, start)]
    while heap:
        d, v = heapq.heappop(heap)
        if d != dist[v]:
            continue
        for w, weight in graph[v]:
            if weight < 0:
                raise ValueError("Dijkstra requires nonnegative weights")
            nd = d + weight
            if nd < dist[w]:
                dist[w] = nd
                heapq.heappush(heap, (nd, w))
    return dist
if __name__ == "__main__":
    print(dijkstra([[(1, 2), (2, 5)], [(2, 1)], []], 0))
