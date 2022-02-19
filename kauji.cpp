/****
 * Prims Algorithm
*/

#include<bits/stdc++.h>

using namespace std;

void mstPrims(vector<vector<pair<int, int>>>& graph, int V, int start) {
    
    vector<bool> taken(V, false);
    priority_queue<pair<int, int>> pq; // {node, weight}
    vector<pair<int, int>> mst;

    pq.push(make_pair(0, start));
    mst.push_back(make_pair(start, 0));
    taken[start] = true;

    int sum, nodesTaken;
    sum  = nodesTaken = 0;

    while(!pq.empty()) {
        int v = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if(taken[v]) {
            continue;
        }

        sum += weight;
        taken[v] = true;
        nodesTaken++;
        if(nodesTaken == V) {
            break;
        }

        for(pair<int, int> u : graph[v]) {
            int neighbourV = u.first;
            int w = u.second;

            if(!taken[neighbourV]) {
                pq.push(make_pair(neighbourV, w));
                mst.push_back(make_pair(neighbourV, w));
            }
        }

    }

    for(pair<int, int> i : mst) {
        cout << i.first << " " << i.second << "\n";
    }

    cout << "Sum: " << sum << "\n";
    
}

int main(){

    int V, E; cin >> V >> E;
    // {node, weight}
    vector<vector<pair<int, int>>> graph(V);

    for(int i = 0; i < E; ++i) {
        int src, dest, w; cin >> src >> dest >> w;
        graph[src].push_back(make_pair(dest, w));
        graph[dest].push_back(make_pair(src, w));
    }
    int start; cin >> start;

    for(int i = 0 ; i < V; ++i) {
        cout << "For " << i << ": ";
        for(pair<int, int> j : graph[i]) {
            cout << "{" << j.first << "," << j.second << "}";
        }
        cout << "\n";
    }

    mstPrims(graph, V, start);

    return 0;
}