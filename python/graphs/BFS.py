from collections import deque
from typing import Dict, List, Optional

Graph = Dict[str, List[str]]

def shortest_path_bfs(graph: Graph, start: str, goal: str) -> List[str]:
    """
    return the shortest path from start to goal in an unweighted graph
    if no path exists, return []
    """
    # TODO: implement
    if start == goal:
        return [start]
    
    if start not in graph or goal not in graph:
        return []
    visited = set() # this is where the visited nodes are
    queue = deque([start]) # setting up queue that stores the to be visited nodes
    visited.add(start) # setting starting node as visited
    # to hold the distance - figure out how to calculate this, usually found first
    #dist = []
    dist = {start: 0}
    parent = {} # making a dictitonary that stores the parent node of node
    parent[start] = None # the start is the parent
    
    while queue:
        u = queue.popleft() # removing node first in line

        for v in graph[u]: # v is the neighbor
            if v not in dist: # replaced visited with dist because calculating the distance, wont need visited because dicts keys are immutable
                dist[v] = dist[u] + 1 # mark neighbor as visited
                parent[v] = u # mark current node (the neighbor)'s parent (the original removed node)

                if v == goal: # if we found the goal, that means its already the shortest path
                    path = []
                    cur = goal
                    while cur is not None:
                        path.append(cur) 
                        cur = parent[cur] # going up the parent dict to find path
                    path.reverse()
                    print(f"Path: {path} | Distance: {dist[u]+1}")
                    return path
                
                queue.append(v) # add neighbor to queue to visit those edges' node
    
    return []

def _run_tests() -> None:
    graph: Graph = {
        "A": ["B", "C"],
        "B": ["A", "D"],
        "C": ["A", "F"],
        "D": ["B", "E", "F"],
        "E": ["D"],
        "F": ["C", "D"],
        "Z": []
    }

    assert shortest_path_bfs(graph, "A", "F") == ["A", "C", "F"]
    assert shortest_path_bfs(graph, "E", "A") == ["E", "D", "B", "A"]
    assert shortest_path_bfs(graph, "A", "Z") == []
    assert shortest_path_bfs(graph, "A", "A") == ["A"]

    # allow either shortest path for A -> E depending on neighbor order
    path = shortest_path_bfs(graph, "A", "E")
    assert path in (["A", "B", "D", "E"], ["A", "C", "F", "D", "E"])
    # note: second option is longer; if you get it, your bfs is wrong
    assert len(path) == 4, f"expected shortest length 4, got {len(path)}: {path}"

    print("all tests passed!")


if __name__ == "__main__":
    _run_tests()
