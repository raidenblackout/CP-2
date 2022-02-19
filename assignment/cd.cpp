#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
};
const int INF = 0x7f7f7f7f;
int dist[107];

bool relax(int u, int v, int w)
{
    if(dist[v]>dist[u]+w)
    {
        dist[v] = dist[u] + w;
        return true;
    }
    else
        return false;
}
void BellmanFord(int source, int V, vector< edge > adjacentList)
{
    for(int i=0;i<V;i++)
        dist[i] = INF;
    dist[source] = 0;
    for(int i=1;i<=V-1;i++)
    {
        for(edge e : adjacentList)
        {
            relax(e.u, e.v, e.w);
        }
    }

    for(edge e : adjacentList)
    {
        if(relax(e.u, e.v, e.w))
        {
            cout << "Negative Cycle Detected!!\n";
            return;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int vertices, edges; cin >> vertices >> edges;
    vector< edge > adjacentList;
    for(int i=0;i<edges;i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        adjacentList.push_back(e);
    }
    BellmanFord(0, vertices, adjacentList);
    for(int i=0;i<vertices;i++)
    {
        cout << " 0 - " << i << " : " << dist[i] << "\n";
    }
    return 0;
}
