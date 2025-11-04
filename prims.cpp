#include<bits/stdc++.h>
#define int long long
using namespace std;

int min_span_tree_prims(int V , vector<vector<pair<int,int>>>& adj)
{
    priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int>>> pq;

    vector<int> vis(V , 0);
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(vis[node]) continue;
        vis[node] = 1;
        sum += w;

        for(int i = 0 ; i < adj[node].size(); i ++)
        {
            int nnode = adj[node][i].first;
            int ex = adj[node][i].second;

            if(!vis[nnode]) pq.push({ex , nnode});
        }
    }

    return sum;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<pair<int , int>>> adj(V);

    for(int i = 0 ; i < edges.size() ; i ++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    cout << min_span_tree_prims(5 , adj);
    return 0;
}