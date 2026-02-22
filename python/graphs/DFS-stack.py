from collections import deque

def topo_sort_dfs(graph):
    """
    graph: directed adjacency list
    returns: list representing topological order
    """

    visited = set()
    stack = []

    def dfs(u):
        visited.add(u)

        for v in graph[u]:
            if v not in visited:
                dfs(v)

        # push AFTER exploring children
        stack.append(u)

    for node in graph:
        if node not in visited:
            dfs(node)

    stack.reverse()

    print(stack)
    return stack

def topo_sort_kahn(graph):
    indegree = {u: 0 for u in graph}

    for u in graph:
        for v in graph[u]:
            indegree[v] += 1

    queue = deque([u for u in graph if indegree[u] == 0])
    order = []

    while queue:
        u = queue.popleft()
        order.append(u)

        for v in graph[u]:
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)

    if len(order) != len(graph):
        raise ValueError("Graph has a cycle")

    print(f"kahn's algo: {order}")
    return order


def _run_tests():
    g1 = {
        "A": ["B","C"],
        "B": ["D","E"],
        "C": ["D"],
        "D": ["E","H"],
        "E": ["H", "F"],
        "F": ["G"],
        "G": [],
        "H": []
    }

    order = topo_sort_dfs(g1)
    topo_sort_kahn(g1)

    # basic validity check:
    pos = {node: i for i, node in enumerate(order)}
    for u in g1:
        for v in g1[u]:
            assert pos[u] < pos[v]

    print("DFS topo sort test passed!")


if __name__ == "__main__":
    _run_tests()
