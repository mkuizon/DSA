// Dependencies 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <functional>

using namespace std;

// Class Objects 

struct TreeNode 
{
    // Pointers to children 
    TreeNode* left;
    TreeNode* right;

    // Member values 
    int val;

    TreeNode(): left(nullptr), right(nullptr), val(0){}
    TreeNode(int v): left(nullptr), right(nullptr), val(v){}
    TreeNode(TreeNode* l, TreeNode* r, int v): left(l), right(r), val(v){}
};


class Solution {
    private:
        // Member variables 
        int diameter = 0;

        int DFS(TreeNode* node)
        {
            if (!node) return;

            int left = DFS(node->left);
            int right = DFS(node->right);

            diameter = max(diameter, left + right);

            return max(left, right) + 1;
        }
    
    public:
        int diameterOfBinaryTree(TreeNode* root)
        {
            // Base cases 
            if (!root) return 0;
            if (!root->left && !root->right) return 0;

            // Reset count 
            diameter = 0;
            // Call Recursive DFS
            DFS(root);
            
            return diameter;
        }
    };


// 617. Merge two binary trees 
class Solution {
    public:
        void merge(TreeNode* parent1, TreeNode* parent2)
        {
            if (parent1->left && parent2->left)
            {
                parent1->left->val += parent2->left->val;
                merge(parent1->left, parent2->left);
            }

            if (parent1->right && parent2->right)
            {
                parent1->right->val += parent2->right->val;
                merge(parent1->right, parent2->right);
            }

            if (!parent1->left && parent2->left)
            {
                parent1->left = parent2->left;
            }

            if (!parent1->right && parent2->right)
            {
                parent1->right = parent2->right;
            }
        }
    
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
        {
            if (!root1 && !root2) return root1;

            if (!root1 && root2) return root2;

            if (root1 && !root2) return root1;
            
            if (root1 && root2)
            {
                root1->val += root2->val;
            }

            merge(root1, root2);
    
            return root1;
        }
    };

// 785. Is Graph Bipartite
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor 
    UnionFind(int n)
    {
        // Size vectors 
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;    
        }
    }

    int find(int x)
    // Function finds x's parent via path compression 
    {
        if (parent[x] != x)
        // Current vertex is not its own parent 
        {
            // Update current path to root parent 
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unionSet(int x, int y)
    {
        // Find the root parents of x & y
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return; // Already are in the same set 

        if (rank[root_x] < rank[root_y])
        {
            parent[root_x] = root_y; 
        }
        else if (rank[root_x] > rank[root_y])
        {
            parent[root_y] = root_x;
        }
        else
        {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        // Init Union Find 
        int n = graph.size();

        /*
            We multiply by 2 to create our 2 disjoint sets 

            To detect cycles we only need n
        */
        UnionFind uf(n * 2);

        for (int v = 0; v < n; v++) {
            for (int u: graph[v])
            {
                /*
                    For cycle detection without an adjacency list {v, u} pairs 
                    we need to insert a visited set to keep track of visited pairs 

                    int min_i = min(v, u);
                    int max_i = max(v, u);

                    pair<int, int> edge = {min_i, max_i};

                    if (visited.count(edge)) continue;
                */

                // Cycle detected 
                if (uf.connected(u, v)) return false;
                
                // Add to union set 
                uf.unionSet(u + n, v);
                uf.unionSet(u, v + n);

                /*
                    If we only want to detect cycles we will use 
                    uf.unionSet(u, v); 
                    ONLY

                    When dealing with Bipartite sets we check both disjoint sets 
                */
            }
        }
        // No cycle detected 
        return true;
    }
};


// 785. Is Graph Bipartite, Approach 2 using BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> colors(n, -1); // -1: uncolored, 0 = first color, 1 = second color 

        for (int v = 0; v < n; v++)
        {
            if (colors[v] != -1) continue; // Prosses only uncolored connections 

            // Init a queue for processing 
            queue<int> q;

            colors[v] = 0; // Init the first color 
            q.push(v);

            while (!q.empty())
            {
                // Get first vertex in line 
                int v = q.front(); q.pop();

                for (int e: graph[v])
                // Iterate over v's edges 
                {
                    if (colors[e] == -1)
                    // We have an uncolored edge 
                    {
                        colors[e] = 1 - colors[v]; // Assing edge e as the oppossite color to neighbor v 

                        // Advance with edge 
                        q.push(e);
                    }
                    else if (colors[e] == colors[v])
                    // Neighbors e, v share the same color, thus not bipartite 
                    {
                        return false;
                    }
                }
            }
        }

        // We have traversed all paths, without matching neighbors 
        return true;
    }
};

// 102. Binary Tree Level Order Traversal

/*
    For level order traversal we use BFS 

    per level we have that there are i * 2 more nodes in the level 
    
    root -> 1 -> i 
    1 -> i * 2 = 2 -> i 
    2 -> i * 2 = 4 -> i 
    ... 

    2^n for [0, n-1]

    BUT!!!!

    This is only for a perfect binary tree 

    Thus we must keep track of each level's size through x = q.size()
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // Define our return variable 
        vector<vector<int>> solution_set = {};

        // No tree no solution_set, empty set returned 
        if (!root) return solution_set;

        // Define a queue for our nodes 
        queue<TreeNode*> q; 
        // Tree's do not have cycles, thus no visited set needed 

        // Init the queue 
        q.push(root);
        
        while (!q.empty())
        // Iterate until queue is sufficied 
        {
            // Allocate memory for a vector that holds the level's element 
            vector<int> current_level = {};

            // Define the current level's size
            int level_lenght = q.size();
            
            for (int j = 0; j < level_lenght; j++)
            // Push out each floor
            {
                // Get first in line 
                TreeNode* current = q.front(); q.pop();

                if (current->left)
                {
                    q.push(current->left);
                }

                if (current->right)
                {
                    q.push(current->right);
                }

                // Put root's value into the current level set 
                current_level.push_back(current->val);
            }

            // Add level to the solution_set 
            solution_set.push_back(current_level);
        }

        return solution_set;
    }
};