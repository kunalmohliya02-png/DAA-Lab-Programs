// Program 1: Bellman-Ford Algorithm for Single Source Shortest Path 
// and Negative-Weight Cycle Detection

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 2: Check for negative-weight cycles (Extension)
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Result: Graph contains a NEGATIVE-WEIGHT CYCLE!\n";
            return;
        }
    }

    // Step 3: Print shortest distances if no negative cycle exists
    cout << "Vertex \t Distance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

int main() {
    cout << "=== Case 1: Graph WITHOUT Negative-Weight Cycle ===\n";
    int V1 = 5, E1 = 8;
    vector<Edge> edges1 = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    bellmanFord(V1, E1, edges1, 0);

    cout << "\n=== Case 2: Graph WITH Negative-Weight Cycle ===\n";
    int V2 = 3, E2 = 3;
    vector<Edge> edges2 = {
        {0, 1, 1}, {1, 2, -1}, {2, 0, -1} // Cycle weight: 1 - 1 - 1 = -1
    };
    bellmanFord(V2, E2, edges2, 0);

    return 0;
}

/* --- OUTPUT ---
=== Case 1: Graph WITHOUT Negative-Weight Cycle ===
Vertex   Distance from Source (0)
0                0
1                -1
2                2
3                -2
4                1

=== Case 2: Graph WITH Negative-Weight Cycle ===
Result: Graph contains a NEGATIVE-WEIGHT CYCLE!
*/
