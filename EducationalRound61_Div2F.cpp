/**
Minimum steps to delete a string by deleting substring comprising of same characters
link - https://www.geeksforgeeks.org/minimum-steps-to-delete-a-string-after-repeated-deletion-of-palindrome-substrings/

Codeforces Comment by Crazy_gamer

1.let str[i][j] (i<=j) be the string formed by characters between ith and jth characters (inclusive). 2.define dp[i][j] to be the 
minimum number of steps to remove all the characters of str[i][j]. 3.This removal can be done in two ways. i.remove the jth character 
on its own, in this case dp[i][j]=1+dp[i][j-1] ii. dont remove the jth character on its own. rather remove it another character same as 
the jth. there may be many such characters . let nth character be same as jth and of course i<=n<j .So u must delete all the characters 
between nth and jth to bring jth and nth character side by side . And u have to do it in minimum step possible . there can be many such 
n's between i and j . u have to choose the one that makes ur steps minimum . so here dp relation is dp[i][j]= dp[n+1][j-1]+dp[i][n] . 
u have iterate through all the n's between i and j such that nth letter is same as jth letter and choose the minimum one

*/
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
