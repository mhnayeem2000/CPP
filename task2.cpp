#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN]; 
bool visited[MAXN]; // visited array to mark visited nodes
int level[MAXN]; // level of each node

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    whil6e (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n; // number of nodes
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; // edge from u to v
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = 1; // root of the tree
    bfs(root); // run BFS from the root node
    for (int i = 1; i <= n; i++) {
        cout << "Level of node " << i << " is " << level[i] << endl;
    }
    return 0;
}
