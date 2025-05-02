import heapq
import numpy as np

def load_matrix(file_path):
    """
    Reads an n x n matrix from a file.
    Each line in the file contains comma-separated integers.
    
    :param file_path: Path to the file containing the matrix.
    :return: A 2D NumPy array representing the matrix.
    """
    with open(file_path, "r") as file:
        matrix = [list(map(int, line.strip().split(","))) for line in file]
    return np.array(matrix)

def min_path_sum(matrix):
    """
    Computes the minimum path sum from the top-left to the bottom-right of an n × n matrix.
    Allowed movements: left, right, up, or down.
    
    :param matrix: 2D list or NumPy array (n × n) of integers.
    :return: Minimum path sum from (0,0) to (n-1,n-1).
    """
    n = len(matrix)
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Right, Down, Left, Up
    dist = np.full((n, n), float('inf'))  # Distance table
    dist[0, 0] = matrix[0, 0]

    # Priority queue for Dijkstra (min-heap)
    pq = [(matrix[0, 0], 0, 0)]  # (path sum, row, col)
    
    while pq:
        current_sum, r, c = heapq.heappop(pq)

        # Stop if we reach the bottom-right corner
        if (r, c) == (n-1, n-1):
            return current_sum

        # Explore all 4 directions
        for dr, dc in directions:
            nr, nc = r + dr, c + dc

            if 0 <= nr < n and 0 <= nc < n:
                new_sum = current_sum + matrix[nr][nc]

                if new_sum < dist[nr, nc]:
                    dist[nr, nc] = new_sum
                    heapq.heappush(pq, (new_sum, nr, nc))

    return -1  # Should never reach here if a path exists

# Example: Read matrix from file and compute minimum path sum
if __name__ == "__main__":
    file_path = "bonus/matrix.txt"  # Ensure the correct file path
    try:
        matrix = load_matrix(file_path)
        result = min_path_sum(matrix)
        print("Minimum Path Sum:", result)
    except FileNotFoundError:
        print("Error: File not found. Please ensure 'matrix.txt' is in the same directory.")
