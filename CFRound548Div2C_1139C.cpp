#include <bits/stdc++.h>//Non-Standard
using namespace std;
const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;
/**
#define MAX 100009
#define MOD 1000000007
*/
//int size; string str;
//int dp[501][501];
int n,k,god,visited[MAX];
long long result;
vector<int> adjlist[MAX];
//Fast I/O
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
long long power(int x){
	long long tmp=1;
	for(int i=1;i<=k;i++)
		(tmp*=x)%=MOD;
	return tmp;
}
/**
//Somethings wrong
long long power(int a, int b, int m) {
	long long  ans=1;
	while(b) {
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
*/
//create graph(u, v)
void create_graph(int u, int v) {
    //Undirected Graph
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}
//Fast Input
//for Integers ?
/**
inline int read(){
	int n=0;char c;

	while((c=getchar_unlocked())<48);
	n += (c - '0');
	while((c=getchar_unlocked())>=48)
		n = n*10 + (c - '0');

	return n;
}
*/
void dfs(int node) {
    god++;
    visited[node] = 1;
    //Classic
    for(int i=0; i<adjlist[node].size(); i++) {
        if(!visited[adjlist[node][i]])
            dfs(adjlist[node][i]);
    }
    /**
     //Concise way
     for(int i :  adjlist[node])
        if(!vis[i])
            dfs(i);
    */ 
}
//Solve function
void solve() {
    cin >> n >> k;
    //n = read(), k = read();
    for(int i=1; i<n; i++) {
        int u, v, c;
        //u = read(), v = read(), c = read();
        cin >> u >> v >> c; 
        if(c == 0) //only RED
            create_graph(u, v);
    }
    int total = power(n);
    //int total = power(n, k, MOD);
    for(int i=1; i<=n; i++) {
        if(visited[i]) //No need to visit node which is already visited
            continue; 
        god = 0;
        dfs(i);
        //good path = total possible path - worst path(s)
        //total = n^k | bad ones = a^k -- Repeated Permuatation
        //a is number of connected components of red-edge path -- which is count here
        total = (total-power(god)+MOD)%MOD;
        //total = (total - power(god, k, MOD)+MOD)%MOD;
        //answer in modulo 1e9 + 7
    }
    cout << total << endl;
}
//Driver Method
int main() {
    __fastio;//Comment for scanf/printf
    solve();
    return 0;
}
