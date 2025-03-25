#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;

    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        weight = w;
    }
};

class MST
{
public:
    int V, E;
    vector<Edge> edges;

    void bubbleSortEdges()
    {
        int n = edges.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (edges[j].weight > edges[j + 1].weight)
                {
                    swap(edges[j], edges[j + 1]);
                }
            }
        }
    }

    int findParent(vector<int> &parent, int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = findParent(parent, parent[i]);
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);
        if (rank[xRoot] < rank[yRoot])
        {
            parent[xRoot] = yRoot;
        }
        else if (rank[xRoot] > rank[yRoot])
        {
            parent[yRoot] = xRoot;
        }
        else
        {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    MST(int v, int e)
    {
        V = v;
        E = e;
    }

    void addEdge(int src, int dest, int weight)
    {
        Edge edge(src, dest, weight);
        edges.push_back(edge);
    }

    void kruskalMST()
    {
        bubbleSortEdges();
        vector<int> parent(V, -1);
        vector<int> rank(V, 0);
        vector<Edge> mst;

        for (Edge &edge : edges)
        {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);
            if (x != y)
            {
                mst.push_back(edge);
                unionSets(parent, rank, x, y);
            }
        }

        cout << "\nKruskal's MST:\n";
        for (Edge &e : mst)
        {
            cout << e.src << " - " << e.dest << " : " << e.weight << "\n";
        }
    }

    void primMST(vector<vector<int>> &graph)
    {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = -1;
            for (int v = 0; v < V; v++)
            {
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                {
                    u = v;
                }
            }
            inMST[u] = true;
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
                {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
        }
    }
};

int main()
{
    int V, E, choice;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    MST mst(V, E);
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        mst.addEdge(src, dest, weight);
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    do
    {
        cout << "\nChoose an option:";
        cout << "\n1. Kruskal's Algorithm";
        cout << "\n2. Prim's Algorithm";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            mst.kruskalMST();
            break;
        case 2:
            mst.primMST(adjMatrix);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}