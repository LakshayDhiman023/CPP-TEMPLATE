// used in case of 2d queries. to find out the total increment if the query is executed 


/***************

Author : Lakshay Dhiman

********************/
#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_pi tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 

#define char unsigned char
#define sz(a) ((int)(a.size()))
#define input(arr) for(auto &x: arr) cin >> x;
#define output(arr, ...) for(auto &x: arr) cout << x << __VA_ARGS__;
#define all(x) (x).begin(), (x).end()
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpi;
typedef vector<vector<pll>> vvpl;

const int MOD = 1e9 + 7;
const int eps = 1e-9;

void Lakshay(){
    int n;
    cin>>n;
    vi v(n);
    input(v);
    int m;
    cin>>m;
    vpi query(m);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        query[i] = make_pair(a, b);
    }

    vi sweep_line(n);
    for(int i = 0; i < m; i++){
        sweep_line[query[i].first]++;
        if(query[i].second + 1 < n) sweep_line[query[i].second + 1]--;
    }
    for(int i = 1; i < n;i++) sweep_line[i] += sweep_line[i - 1];
    

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // int c = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << c++ << ": ";
        Lakshay();
        // cout << '\n';
    }
    return 0;
}