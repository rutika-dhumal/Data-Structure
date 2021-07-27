#include <iostream>
using namespace std;
#include <vector>
#define V 5

int selectMinVertex(vector<int> &value, vector<bool> &setMST)
{
    int minimum = INT_MAX;
    int vertex;

    for (int i = 0; i < V; i++)
    {
        if (setMST[i] == false && value[i] < minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex; // it will return vertext which is not included in mst and whose weight is minimum
}
void findMST(int graph[V][V])
{
    int parent[V];
    vector<bool> setMST(V, false); // to check whether the vertex is included into MST or not
    vector<int> value(V, INT_MAX); // to get weight of edges

    parent[0] = -1; // start node has no parent
    value[0] = 0;   // start node has 0 value so it will get picked first

    // form MST with v-1 edges

    for (int i = 0; i < V - 1; i++)
    {
        // to select minimum vertex
        int u = selectMinVertex(value, setMST);
        setMST[u] = true; // as we included new vertext in setMST

        // relax adjacent vertices which are not included in setMST

        for (int j = 0; j < V; j++)
        {
            // it has 3 rules -
            //     1. edge should be connected that is from u to j
            //     2. j should not included in MST
            //     3. edge weight is smaller than the current edge weight

            if (graph[u][j] != 0 && setMST[j] == false && graph[u][j] < value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u; // updating parent
            }
        }
    }

    // print MST

    for (int i = 1; i < V; i++)
    {
        cout << "u->v : " << parent[i] << "->" << i << "  wt= " << graph[parent[i]][i] << "\n";
    }
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    findMST(graph);
    return 0;
}