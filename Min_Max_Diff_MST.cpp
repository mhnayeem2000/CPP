#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskal(Edge edges[], int V, int E) {
    sort(edges, edges + E, compare);
   
    vector<Edge> minST; // minimum spanning tree
    vector<Edge> maxST; // maximum spanning tree
   
    int parent[V];
    fill_n(parent, V, -1);
   
    int i = 0;
    while (minST.size() < V - 1 && i < E) {
        Edge edge = edges[i];
        int u = edge.u;
        int v = edge.v;
        int set_u = find(parent, u);
        int set_v = find(parent, v);
       
        if (set_u != set_v) {
            minST.push_back(edge);
            Union(parent, set_u, set_v);
        }
        i++;
    }
   
    fill_n(parent, V, -1);
   
    i = E - 1;
    while (maxST.size() < V - 1 && i >= 0) {
        Edge edge = edges[i];
        int u = edge.u;
        int v = edge.v;
        int set_u = find(parent, u);
        int set_v = find(parent, v);
       
        if (set_u != set_v) {
            maxST.push_back(edge);
            Union(parent, set_u, set_v);
        }
        i--;
    }
   
    int minCost = 0;
    for (auto edge : minST) {
        minCost += edge.weight;
    }
   
    int maxCost = 0;
    for (auto edge : maxST) {
        maxCost += edge.weight;
    }
   
    cout << "Minimum Spanning Tree: ";
    
        cout  << minCost ;
    
    cout << "\nMaximum Spanning Tree: ";
   
        cout << maxCost;
    
   
    cout << "\nDifference between Maximum and Minimum Spanning Trees: " << maxCost - minCost << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
   
    Edge edges[E];
    cout << "Enter the edges and their weights: " << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
   
    kruskal(edges, V, E);
   
    return 0;
}
