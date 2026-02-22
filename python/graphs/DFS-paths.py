def path(u, v, parent):
    # determining if there is a path from u to v (if v is reachable from u)
    path = []

    if v not in parent:
        return []
    
    current = v

    while current != u:
        path.append(current)
        current = parent[current]

    path.append(u)
    path.reverse()

    return path
