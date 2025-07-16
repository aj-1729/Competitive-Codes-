/**
   author : ashwini_jha 
   date   : 2025-07-15
**/
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define vii vector<vector<int>>
#define mi map<int,int>
#define pii pair<int,int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
#define Guess_Who_Is_This ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define debug(...) 42

void build(int ind , int low , int high , vi& vec , vi& seg)
{
    if(low == high) 
    {
        seg[ind] = vec[low];
        return;
    }
    int mid = (low + high) / 2;

    build(2*ind + 1 , low , mid , vec , seg);
    build(2*ind + 2 , mid + 1 , high , vec , seg);

    seg[ind] = max(seg[2*ind + 1] , seg[2*ind + 2]);
    return;

}

int op(int ind , int low , int high , int l , int r , vi& seg)
{
    if(low >= l && high <= r)
    {
        return seg[ind];
    }
    else if(low > r || high < l) return -1;
    int mid = (low + high)/2;

    int first = op(2*ind + 1 , low , mid , l , r , seg);
    int second = op(2*ind + 2 , mid + 1 , high , l , r , seg);
    
    return max(first , second);
}
int32_t main(){
    Guess_Who_Is_This
    
    int n; cin >> n;
    vi vec(n); for(int i = 0 ; i < n ; i ++) cin >> vec[i];
    vi seg(4*n);
    build(0 , 0 , n - 1 , vec , seg);

    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << op(0 , 0 , n - 1 , l , r , seg) << endl;
    }

    return 0;
}