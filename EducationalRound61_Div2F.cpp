#include <bits/stdc++.h>//Non-Standard
using namespace std;
int size; string str;
int dp[501][501];
//Fast I/O
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
/**
//Fast Input
inline int read(){
	int n=0;char c;

	while((c=getchar_unlocked())<48);
	n += (c - '0');
	while((c=getchar_unlocked())>=48)
		n = n*10 + (c - '0');

	return n;
}
*/
//calculate minimum moves
int f(int l, int r) {
    //Null solution
    if(l > r)  return 0;
    //If l = r, then only one possible deleting
    if(l == r) return 1;
    
    //Memoization Call, to reduce time-complexity
    if(dp[l][r] != -1) return dp[l][r];
    
    /**
    Either you can delete letters individually or when characters of same type are matched
    If same type matched we calculate the possible way to delete the character in between the
    range and the leftover part
    The Minimum of these is the answer
    */
    //dp[start][end] for Memoization
    //when deleting characters individually
    int ans = 1 + f(l+1, r);
    
    for(int i=l+1; i<=r; i++) {
        //when str[x] equal to str[y], we count the possible solution between
        //range(x,y) and leftover
        if(str[l] == str[i])
            ans = min(ans,f(l+1, i-1) + f(i, r));
    }
    return dp[l][r] = ans;
}
//Solve function
void solve() {
    cin >> size >> str;
    /**
    *Causing unspecified C++ error
    cin >> str;
    getline(cin, str);
    */
    memset(dp, -1, sizeof(dp));
    cout << f(0, size-1) << endl;
}
//Driver Method
int main() {
    __fastio;//Comment for scanf/printf
    solve();
    return 0;
}
