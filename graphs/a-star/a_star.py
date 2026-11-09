import heapq
def a_star(graph, start, goal, heuristic):
    # Weighted adjacency lists (neighbor, weight), nonnegative weights; an admissible heuristic(node) estimates remaining cost.
    best = {start: 0}
    heap = [(heuristic(start), 0, start)]
    while heap:
        _, cost, v = heapq.heappop(heap)
        if cost != best[v]:
            continue
        if v == goal:
            return cost
        for w, weight in graph[v]:
            if weight < 0:
                raise ValueError("A* requires nonnegative weights")
            candidate = cost + weight
            if candidate < best.get(w, float("inf")):
                best[w] = candidate
                heapq.heappush(heap, (candidate + heuristic(w), candidate, w))
    return None
if __name__ == "__main__":
    print(a_star([[(1, 2), (2, 5)], [(2, 1)], []], 0, 2, lambda _: 0))
