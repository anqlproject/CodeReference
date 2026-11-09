def bellman_ford(vertex_count, edges, start):
    # Edges are (source, destination, weight); raises on a reachable negative cycle.
    dist = [float("inf")] * vertex_count
    dist[start] = 0
    for _ in range(vertex_count - 1):
        changed = False
        for u, v, weight in edges:
            if dist[u] != float("inf") and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                changed = True
        if not changed:
            break
    if any(dist[u] != float("inf") and dist[u] + w < dist[v] for u, v, w in edges):
        raise ValueError("reachable negative cycle")
    return dist
if __name__ == "__main__":
    print(bellman_ford(3, [(0, 1, 4), (0, 2, 5), (1, 2, -2)], 0))
