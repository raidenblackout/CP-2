#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
};

vector<int> representative;
void MAKE_SET(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        representative[i] = i;
    }
}
int find_set(int x)
{
    if (representative[x] == x)
        return x;
    else
        return representative[x] = find_set(representative[x]);
}
bool Union(int u, int v)
{
    int r_u = find_set(u);
    int r_v = find_set(v);
    if (r_u != r_v)
    {
        representative[r_v] = r_u;
        return true;
    }
    return false;
}

int main()
{
    int sum = 0;
    int vertices, edges;
    cin >> vertices >> edges;
    vector<edge> adjacentList(edges);
    int maximum=0;
    for (int i = 0; i < edges; i++)
    {
        cin >> adjacentList[i].u >> adjacentList[i].v >> adjacentList[i].w;
        maximum+=adjacentList[i].w;
    }
    sort(adjacentList.begin(), adjacentList.end(), [&](edge &a, edge &b)
         { return a.w < b.w; });
    representative.resize(vertices);
    MAKE_SET(vertices);
    int mst = 0;
    vector<edge> edges_in_mst;
    for (int i = 0; i < adjacentList.size(); i++)
    {
        int u = adjacentList[i].u;
        int v = adjacentList[i].v;
        int w = adjacentList[i].w;
        sum = sum + w;

        if (Union(u, v))
        {
            mst += w;
            edges_in_mst.push_back(adjacentList[i]);
        }
    }
    cout << maximum-mst << "\n";
    cout << mst << "\n";

    for (edge e : edges_in_mst)
    {
        cout << e.u << " " << e.v << "\n";
    }
    cout << "\n";
}