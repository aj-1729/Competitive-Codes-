// jha
// 02-06-2025
//Djisktra's Algorithm
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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //given 
    int V ; int E ; int src ; 
    vector<pair<int,int>> adj[V] ; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vi dis(V , 1e9) ; 

    dis[src] = 0 ;

    pq.push({0 , src}) ; 

    while(!(pq.empty()))
    {
        int node = pq.top().second ; 
        int d = pq.top().first ; 

        for(int i = 0 ; i < adj[node].size() ; i ++)
        {
            int e = adj[node][i].first ; 
            int wt = adj[node][i].second ; 

            if((d + wt) < dis[e]) 
            {
                dis[e] = d + wt ; 
                pq.push({dis[e] , e}) ; 
            }
        }
        
    }

    // ans is stored in dis vector // shortest path 


    return 0;
}