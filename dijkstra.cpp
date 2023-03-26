#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    dist[source] = 0;

    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < inf)
            cout << dist[i] << "\t";
        else
            cout << -1 << "\t";
    }
    cout << "\n";

        // {wt, vertex}
        s.insert({0, source});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto i : graph[x.second])
        {
            if (dist[i.first] > dist[x.second] + i.second)
            {
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < inf)
                cout << dist[i] << "\t";
            else
                cout << -1 << "\t";
        }
        cout << "\n";
    }
    cout << "final output: \t";
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < inf)
            cout << dist[i] << "\t";
        else
            cout << -1 << "\t";
    }
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
