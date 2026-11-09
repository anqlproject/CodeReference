from collections import deque
def breadth_first_search(graph, start):
    # graph[v] lists outgoing neighbors; visits only start's reachable component.
    seen, order, queue = {start}, [], deque([start])
    while queue:
        v = queue.popleft()
        order.append(v)
        for w in graph[v]:
            if w not in seen:
                seen.add(w)
                queue.append(w)
    return order
if __name__ == "__main__":
    print(breadth_first_search([[1, 2], [3], [3], []], 0))
