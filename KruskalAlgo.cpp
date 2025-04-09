#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Edge
{
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int parent[], int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int parent[], int rank[], int x, int y)
{
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void printMST(int parent[], int graph[MAX][MAX], int V)
{
    int minCost = 0;
    for (int i = 1; i < V; i++)
    {
        minCost += graph[parent[i]][i];
    }
    cout << "\nMinimum cost path = " << minCost << endl;
    for (int i = 1; i < V; i++)
        cout << "Edge " << parent[i] + 1 << "-" << i + 1 << " -> " << graph[parent[i]][i] << endl;
}

void primMST(int graph[MAX][MAX], int V)
{
    int parent[MAX], key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int v = 0; v < V; v++)
        {
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

void kruskalMST(int graph[MAX][MAX], int V)
{
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount++] = {i, j, graph[i][j]};
            }
        }
    }

    sort(edges, edges + edgeCount, compareEdges);
    int parent[MAX], rank[MAX];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge mstEdges[MAX];
    int mstCount = 0, minCost = 0;

    for (int i = 0; i < edgeCount && mstCount < V - 1; i++)
    {
        if (findParent(parent, edges[i].u) != findParent(parent, edges[i].v))
        {
            unionSets(parent, rank, edges[i].u, edges[i].v);
            mstEdges[mstCount++] = edges[i];
            minCost += edges[i].weight;
        }
    }

    cout << "\nMinimum cost path = " << minCost << endl;
    for (int i = 0; i < mstCount; i++)
        cout << "Edge " << mstEdges[i].u + 1 << "-" << mstEdges[i].v + 1 << " -> " << mstEdges[i].weight << endl;
}

int main()
{
    int v;
    cout << "\nEnter the number of vertices: ";
    cin >> v;
    int graph[MAX][MAX];

    cout << "\nEnter adjacency matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> graph[i][j];
        }
    }

    int choice;
    cout << "\nChoose Algorithm:" << endl;
    cout << "1) Prim's Algorithm" << endl;
    cout << "2) Kruskal's Algorithm" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        primMST(graph, v);
    else if (choice == 2)
        kruskalMST(graph, v);
    else
        cout << "\nInvalid choice !!! Please try again...";

    return 0;
}