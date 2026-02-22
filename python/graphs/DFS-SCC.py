def strongly_connected_components(graph):
    """
    kosaraju's algorithm
    graph: dict[node, list[node]] directed adjacency list
    returns: list of components, each component is a list of nodes
    """

    # ensure all nodes appear as keys (including nodes with only incoming edges)
    nodes = set(graph.keys())
    for u in graph:
        for v in graph[u]:
            nodes.add(v)

    for n in nodes:
        if n not in graph:
            graph[n] = []

    # 1) first pass: compute finishing order with iterative dfs
    visited = set()
    finish_order = []

    for start in graph:
        if start in visited:
            continue

        stack = [(start, 0)]  # (node, next neighbor index)
        visited.add(start)

        while stack:
            u, i = stack[-1]

            if i < len(graph[u]):
                v = graph[u][i]
                stack[-1] = (u, i + 1)
                if v not in visited:
                    visited.add(v)
                    stack.append((v, 0))
            else:
                # all neighbors processed -> finished
                stack.pop()
                finish_order.append(u)

    # 2) reverse graph
    rev = {u: [] for u in graph}
    for u in graph:
        for v in graph[u]:
            rev[v].append(u)

    # 3) second pass: dfs in reverse finishing order on reversed graph
    visited.clear()
    sccs = []

    for start in reversed(finish_order):
        if start in visited:
            continue

        comp = []
        stack = [start]
        visited.add(start)

        while stack:
            u = stack.pop()
            comp.append(u)
            for v in rev[u]:
                if v not in visited:
                    visited.add(v)
                    stack.append(v)

        sccs.append(comp)

    return sccs


def _normalize_sccs(sccs):
    # helper for testing: sort nodes within each component, then sort components
    return sorted([sorted(c) for c in sccs])


def _run_tests():
    # example 1:
    # 0 -> 1 -> 2 -> 0 forms an scc
    # 3 <-> 4 forms an scc
    # 5 alone
    g1 = {
        0: [1],
        1: [2],
        2: [0, 3],
        3: [4],
        4: [3],
        5: []
    }
    sccs1 = _normalize_sccs(strongly_connected_components(g1))
    assert sccs1 == [[0,1,2], [3,4], [5]]

    # example 2:
    # two sccs: {A,B,C} and {D,E}
    g2 = {
        "A": ["B"],
        "B": ["C"],
        "C": ["A", "D"],
        "D": ["E"],
        "E": ["D"]
    }
    sccs2 = _normalize_sccs(strongly_connected_components(g2))
    assert sccs2 == [["A","B","C"], ["D","E"]]

    # example 3: all separate
    g3 = {
        1: [2],
        2: [3],
        3: []
    }
    sccs3 = _normalize_sccs(strongly_connected_components(g3))
    assert sccs3 == [[1], [2], [3]]

    print("all tests passed!")


if __name__ == "__main__":
    _run_tests()
