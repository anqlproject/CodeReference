def depth_first_search(graph, start):
    # graph[v] lists outgoing neighbors; visits only start's reachable component.
    seen, order, stack = set(), [], [start]
    while stack:
        v = stack.pop()
        if v in seen:
            continue
        seen.add(v)
        order.append(v)
        stack.extend(reversed(graph[v]))
    return order
if __name__ == "__main__":
    print(depth_first_search([[1, 2], [3], [3], []], 0))
