
class Solution {
private:
    // BFS helper function: explores one entire island and marks it as visited
    void bfs(int sr, int sc, std::vector<std::vector<char>> &grid) {
        // 4 possible moves: up, right, down, left
        static const int drow[4] = {-1, 0, 1, 0};
        static const int dcol[4] = { 0, 1, 0,-1};

        int n = (int)grid.size();
        int m = (int)grid[0].size();

        std::queue<std::pair<int,int>> q;
        grid[sr][sc] = '0';   // mark starting land as visited
        q.emplace(sr, sc);    // push starting cell

        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nr = r + drow[k], nc = c + dcol[k];
                if ((unsigned)nr < (unsigned)n && (unsigned)nc < (unsigned)m &&
                    grid[nr][nc] == '1') {
                    grid[nr][nc] = '0'; // mark as visited
                    q.emplace(nr, nc);
                }
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = (int)grid.size(), m = (int)grid[0].size();

        int count = 0;
        // Traverse every cell in the grid
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == '1') { // found unvisited land
                    ++count;             // new island
                    bfs(r, c, grid);     // explore and mark entire island
                }
            }
        }
        return count;
    }
};