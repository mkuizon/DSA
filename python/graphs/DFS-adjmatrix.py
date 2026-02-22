from typing import List

def count_components_matrix(adj: List[List[int]]) -> int:
    """
    return the number of connected components in an undirected graph
    represented as an adjacency matrix
    """

    if not adj:
        return 0

    n = len(adj)
    visited = [False] * n
    components = 0

    def dfs(u: int):
        visited[u] = True

        for v in range(n):
            if adj[u][v] == 1 and not visited[v]:
                dfs(v)

    for i in range(n):
        if not visited[i]:
            components += 1
            dfs(i)

    return components


def _run_tests():
    # Graph 1:
    # 0 — 1     2 — 3     4
    adj1 = [
        [0,1,0,0,0],
        [1,0,0,0,0],
        [0,0,0,1,0],
        [0,0,1,0,0],
        [0,0,0,0,0]
    ]
    assert count_components_matrix(adj1) == 3

    # Graph 2:
    # 0 — 1 — 2     3
    adj2 = [
        [0,1,0,0],
        [1,0,1,0],
        [0,1,0,0],
        [0,0,0,0]
    ]
    assert count_components_matrix(adj2) == 2

    # Graph 3: Fully connected
    adj3 = [
        [0,1,1],
        [1,0,1],
        [1,1,0]
    ]
    assert count_components_matrix(adj3) == 1

    # Graph 4: Empty graph
    adj4 = []
    assert count_components_matrix(adj4) == 0

    # Graph 5: No edges (all isolated nodes)
    adj5 = [
        [0,0,0],
        [0,0,0],
        [0,0,0]
    ]
    assert count_components_matrix(adj5) == 3

    print("all tests passed!")


if __name__ == "__main__":
    _run_tests()
