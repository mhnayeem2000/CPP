#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int s , int v, vector<int> adj[] , vector <int> & visited){
    queue<pair<int , int>> q;
    visited[s] = true;
    q.push({s,-1});

    while (!q.empty())
    {
       int node  = q.front().first;
       int par = q.front().second;
       q.pop();

       for(auto it : adj[node]){
        if(!visited[it]){
            visited[it] = true ; 
            q.push({it, node});
        }
        else if(par != it){
            return true;
        }
       }
    }
    return false;
}

bool iscycle(int v , vector<int> adj[]){
    vector<int> vis(v, 0);
    for(int i = 1; i < v ; i++){
        if(!vis[i]){
            if(checkCycle(i , v, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++) {
        int u, v;
        cout << "Enter edges : ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (iscycle(v, adj)) {
        cout << "Has a cycle." << endl;
    } else {
        cout << " does not have cycle." << endl;
    }
    return 0;
}
