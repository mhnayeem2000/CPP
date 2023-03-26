#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int visited[1000];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int u = q.front();
        cout << u << "\t";
        q.pop();

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v] == 0){
                visited[v] = 1;
                q.push(v);
            }
        }
    } 
}

int main(){
    int V, E, a, b;
    scanf("%d %d", &V, &E);

    for(int i = 1; i <= V; i++){
        visited[i] = 0;
    }

    for(int i = 0; i < E; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    return 0;
}
