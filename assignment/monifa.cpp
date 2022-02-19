#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> visited_order;
struct nodes{
    int u;
    int end_time;
};
bool checkCycle(int visiting_node, int visited[], vector<int> parent, vector<int> adjacentList[])
{
    visited[visiting_node] = 1;
    visited_order.push_back(visiting_node);
    for (int i = 0; i < adjacentList[visiting_node].size(); i++)
    {
        int current_node = adjacentList[visiting_node][i];
        if (visited[current_node] == 0)
        {
            parent.push_back(visiting_node);
            if (checkCycle(current_node, visited, parent, adjacentList))
            {
                return true;
            }
        }
        else
        {
            for (int j = 0; j < parent.size(); j++)
            {
                if (parent[j] == current_node)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int end_time=0;
void topoSort(vector<int> adjList[], int u, vector<int> &visited,vector<nodes> &end_times){
    if(visited[u]){
        return;
    }
    visited[u]=1;
    end_time++;
    for(int &x: adjList[u]){
        topoSort(adjList,x,visited,end_times);
    }
    end_time++;
    end_times[u]={u,end_time};
}

int main()
{
    //freopen("newdata.txt", "r", stdin);

    int vertices, edges;
    bool result;
    cin >> vertices >> edges;
    vector<int> adjacentList[vertices];
    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cin >> source >> destination;
        adjacentList[source].push_back(destination);
    }
    int starting_node;
    cin >> starting_node;

    int visited[vertices] = {0};
    for(int i=0;i<vertices;i++) visited[i]=0;
    vector<int> parent;
    vector<nodes> end_times(vertices);
    result = checkCycle(starting_node, visited, parent, adjacentList);

    if (result == true)
    {
        cout << "Graph has at least one cycle, topological order cannot be shown!\n";
    }
    else if (result == false)
    {
        vector<int> visited2(vertices, 0);
        for(int i=0;i<vertices;i++){
            topoSort(adjacentList, i, visited2, end_times);
        }
        sort(end_times.begin(), end_times.end(), [](nodes a, nodes b) { return a.end_time > b.end_time; });
        for (int i = 0; i < vertices; i++)
        {
            cout << end_times[i].u << (i==(vertices-1)?"":"->");
        }
    }
}