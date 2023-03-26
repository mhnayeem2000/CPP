#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    // Take input from the user
    int n, m, source;
    cin >> n >> m >> source;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // Initialize the distance vector
    vector<int> dist(n + 1, inf);
    dist[source] = 0;

    // Run the algorithm
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : graph[u]) {
                if (dist[u] != inf && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative cycles
    bool has_negative_cycle = false;
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : graph[u]) {
            if (dist[u] != inf && dist[v] > dist[u] + w) {
                has_negative_cycle = true;
                break;
            }
        }
        if (has_negative_cycle) break;
    }

    // Output the results
    if (has_negative_cycle) {
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "Shortest distances from node " << source << ": ";
        for (int i = 1; i <= n; i++) {
            if (dist[i] != inf) {
                cout << dist[i] << " ";
            } else {
                cout << "INF ";
            }
        }
        cout << endl;
    }

    return 0;
}
