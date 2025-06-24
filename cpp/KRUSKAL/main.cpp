#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Edge structure
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight; // sort by ascending weight
    }
};

// Union-Find data structure (Disjoint Set)
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry)
            parent[ry] = rx;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// Kruskal’s algorithm function
vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    vector<Edge> result;

    for (Edge& e : edges) {
        if (!uf.connected(e.u, e.v)) {
            result.push_back(e);
            uf.unite(e.u, e.v);
        }
    }

    return result;
}


int main() {
    int V = 7; // Vertices: A-G = 0–6
    vector<Edge> edges = {
        {0, 1, 7}, {0, 3, 5}, {1, 2, 8}, {1, 3, 9},
        {1, 4, 7}, {2, 4, 5}, {3, 4, 15}, {3, 5, 6},
        {4, 5, 8}, {4, 6, 9}, {5, 6, 11}
    };

    vector<Edge> mst = kruskalMST(V, edges);
    int totalWeight = 0;

    cout << "Minimum Spanning Tree edges:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " (weight " << e.weight << ")\n";
        totalWeight += e.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
}