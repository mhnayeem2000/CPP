#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;

int dist[MAXN][MAXN];

void floyd_warshall(int n) {
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // print the current iteration
        cout << "Iteration #" << k << ":" << endl;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for(int i=1;i<=m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    floyd_warshall(n);

    cout << "The shortest path distances between each pair of nodes are:" << endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}


/*5 9
1 2 5
1 4 2
2 3 2
3 1 3
3 5 7
4 3 4
4 5 1
5 1 1
5 2 3*/