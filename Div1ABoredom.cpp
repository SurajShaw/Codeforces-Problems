#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
long long freq[MAX];
long long dp[MAX];
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
void solve() {
	int n, input;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> input;
		freq[input]++;
	}
	/**
	 * Base Case is trivial
	 */
	dp[0] = 0;
	dp[1] = freq[1];
	/**
	 *  Either you can choose "i" or you can't, these are the fundamental steps for optimal
	 *  solution.
	 *  IF choosed "i", then you can't choose i-1 and i+1 (According to rule), equation
	 *  is best_solution[i-2] + frequency[i] * i , else if you dont then it would be 
	 *  best_solution[i-1]
	 *	The MAX of them is the optimal answer
	 */
	for(int i=2; i<=MAX; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + freq[i]*i);
	}
	cout << dp[MAX] << endl;
}
int main() {
  __fastio;
  solve();
  return 0;
}
