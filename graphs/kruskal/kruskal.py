def kruskal(vertex_count, edges):
    # Undirected weighted edges (u, v, weight); returns (total weight, edges), or None if disconnected.
    parent = list(range(vertex_count))
    rank = [0] * vertex_count
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    chosen, total = [], 0
    ordered = list(edges)
    for i in range(1, len(ordered)):
        edge, j = ordered[i], i
        while j > 0 and ordered[j - 1][2] > edge[2]:
            ordered[j] = ordered[j - 1]
            j -= 1
        ordered[j] = edge
    for u, v, w in ordered:
        a, b = find(u), find(v)
        if a != b:
            if rank[a] < rank[b]:
                a, b = b, a
            parent[b] = a
            if rank[a] == rank[b]:
                rank[a] += 1
            chosen.append((u, v, w))
            total += w
    return (total, chosen) if len(chosen) == max(0, vertex_count - 1) else None
if __name__ == "__main__":
    print(kruskal(3, [(0, 1, 4), (1, 2, 2), (0, 2, 5)]))
