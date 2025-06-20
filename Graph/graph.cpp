#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    int numVertices;                    // Number of vertices
    bool isDirected;                    // Directed or Undirected
    bool isWeighted;                    // Weighted or Unweighted
    vector<vector<pair<int, int>>> adj; // Adjacency list: pair<neighbor, weight>

public:
    // Constructor
    Graph(int vertices, bool directed = false, bool weighted = false)
        : numVertices(vertices), isDirected(directed), isWeighted(weighted)
    {
        adj.resize(vertices);
    }

    // Add edge to the graph
    void addEdge(int u, int v, int weight = 1)
    {
        if (isWeighted)
        {
            adj[u].emplace_back(v, weight);
            if (!isDirected)
            {
                adj[v].emplace_back(u, weight);
            }
        }
        else
        {
            adj[u].emplace_back(v, 1);
            if (!isDirected)
            {
                adj[v].emplace_back(u, 1);
            }
        }
    }

    // Display the adjacency list of the graph
    void displayGraph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            cout << "Vertex " << i << ": ";
            for (const auto &neighbor : adj[i])
            {
                cout << "(Dest: " << neighbor.first << ", Weight: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    // Depth First Search (DFS)
    void dfs(int start)
    {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(start);
        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (!visited[node])
            {
                cout << node << " ";
                visited[node] = true;
            }

            for (const auto &neighbor : adj[node])
            {
                if (!visited[neighbor.first])
                {
                    s.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    // Breadth First Search (BFS)
    void bfs(int start)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (const auto &neighbor : adj[node])
            {
                if (!visited[neighbor.first])
                {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    // Example: Create a graph with 6 vertices, directed and weighted
    Graph g(6, true, true);

    // Add edges (u, v, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 5);

    // Display the graph
    cout << "Adjacency List of Graph:" << endl;
    g.displayGraph();

    // Perform DFS and BFS
    cout << endl;
    g.dfs(0); // Start DFS from vertex 0
    g.bfs(0); // Start BFS from vertex 0

    return 0;
}