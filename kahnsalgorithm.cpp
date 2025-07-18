// jha
// 31-05-2025
//Kahn's Algorithm //topo sort using bfs
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define f(n) for(int i = 0 ; i < n ; i++)
#define f1(n) for(int i = 1 ; i <= n ; i++)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define vii vector<vector<int>>
#define vs vector<string>
#define mi map<int,int>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
using namespace std;
#define debug(...) 42
// for dfs method
// void dfs(int node , vi& vis , stack<int>& s , vii& adj)
// {
//     vis[node] = 1 ; 

//     for(int i = 0 ; i < adj[node].size() ; i ++)
//     {
//         int e = adj[node][e] ; 
//         if(vis[e] == 0) dfs(e , vis , s , adj) ; 
//     }
//     s.push(node) ;  
// }

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //given input
    int V ;
    vii edges ; 
    //
    vi vis(V , 0) ; 

    vi adj[V] ; 

    f(V)
    {
        int u = edges[i][0] ; 
        int v = edges[i][1] ; 

        adj[u].pb(v) ; 
    }

    vi indegree(V , 0) ;
    f(V) 
    {
        for(int j = 0 ; j < adj[i].size() ; j ++) indegree[adj[i][j]] ++ ; 
    }

    queue<int> q ; 
    vector<int> ans ; 

    for(int i = 0 ; i < V ; i ++)
    {
        if(indegree[i] == 0) q.push(i) ; 
    }

    while(! q.empty())
    {
        int node = q.front() ; 
        q.pop() ; 
        ans.pb(node) ; 

        for(int i = 0 ; i < adj[node].size() ; i ++)
        {
            indegree[adj[node][i]] -- ;
            if(indegree[adj[node][i]] == 0) q.push(adj[node][i]) ; 
        }
    }

    // ans vector is the final answer 
    // for dfs
    // stack<int> s ; 
    // for(int i = 0 ; i < V  ; i ++)
    // {
    //     if(vis[i] == 0) dfs(i , vis , s , edges) ; 
    // }

    // while(!s.empty())
    // {
    //     int e = s.top() ; 
    //     ans.pb(e) ; 
    //     s.pop() ; 
    // }
    //
    
    return 0;
}