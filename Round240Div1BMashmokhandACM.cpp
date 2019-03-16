/**
Algorithm - precompute the board separately for Rows and Columns, and then do range based query for given a range. 
*/
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
void solve() {
	int row, col;
	cin >> row >> col;

	string str[row+10];
	for(int i=0; i<row; i++)
		cin >> str[i];
		
	int dpH[510][510], dpC[510][510];
	for(int i=0; i<row; i++) {
		int count = 0;
		for(int j=1; j<col; j++) {
			if(str[i][j] == str[i][j-1] && str[i][j] == '.')
				count++;
			dpH[i][j] = count;
		}
	}
	
	for(int i=0; i<col; i++) {
		int count = 0;
		for(int j=1; j<row; j++) {
			if(str[j][i] == str[j-1][i] && str[j][i] == '.')
				count++;
			dpC[i][j] = count;
		}
	}
	
	int query; cin >> query;
	while(query--) {
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		
		r1--, c1--, r2--, c2--;
		
		int result = 0;
		
		for(int i=r1; i<=r2; i++)
			result += dpH[i][c2] - dpH[i][c1];
		
		for(int i=c1; i<=c2; i++)
			result += dpC[i][r2] - dpC[i][r1];
		
		cout << result << endl;
	}
}
int main() {
	__fastio;
	solve();
	return 0;
}
