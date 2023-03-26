#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Adjacency list representation of the graph
vector<pair<int, int>> adjList[100001];

// Dijkstra's algorithm function
void dijkstra(int source, int destination, int n) {
    // Initializing distance array and visited array
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    dist[source] = 0;

    // Priority queue for finding the minimum distance vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Adding the source vertex to the priority queue
    pq.push({0, source});

    // Loop until the destination is reached or the priority queue is empty
    while (!pq.empty()) {
        // Get the vertex with the minimum distance
        int u = pq.top().second;
        pq.pop();

        // If the vertex has already been visited, skip it
        if (visited[u]) continue;

        // Mark the vertex as visited
        visited[u] = true;

        // Print the current iteration
        cout << "Iteration: " << u << endl;

        // Check if the destination has been reached
        if (u == destination) break;

        // Update the distances of the adjacent vertices
        for (auto v : adjList[u]) {
            int vertex = v.first;
            int weight = v.second;

            if (!visited[vertex] && dist[u] + weight < dist[vertex]) {
                dist[vertex] = dist[u] + weight;
                pq.push({dist[vertex], vertex});
            }
        }
    }

    // Print the final distance to the destination
    cout << "Shortest distance to node 6: " << dist[destination] << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Reading the edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // for undirected graph
    }

    dijkstra(1, 6, n);

    return 0;
}


/*

6 8 
1 2 2
1 3 4
2 4 7
2 3 1
3 5 3
4 6 1
5 4 2
5 6 5
1

*/
