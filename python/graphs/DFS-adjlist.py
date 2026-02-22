from typing import Dict, List, Set

Graph = Dict[str, List[str]]

def count_components(graph: Graph) -> int:
    """
    return the number of connected components in an undirected graph
    """
    # TODO: implement
    visited = set()
    components = 0

    def dfs(s):

        visited.add(s)
        for v in graph[s]:
            if v not in visited:
                dfs(v)
                

    for u in graph:
        if u not in visited:
            components += 1
            dfs(u)

    return components


def _run_tests():
    graph1 = {
        "A": ["B"],
        "B": ["A"],
        "C": ["D"],
        "D": ["C"],
        "E": []
    }
    assert count_components(graph1) == 3

    graph2 = {
        "A": ["B", "C"],
        "B": ["A"],
        "C": ["A"],
        "D": []
    }
    assert count_components(graph2) == 2

    graph3 = {}
    assert count_components(graph3) == 0

    print("all tests passed!")

if __name__ == "__main__":
    _run_tests()
