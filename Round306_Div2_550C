/**
Find all the multiples of 8 less than - which is 125 (Including 0)
if the numbers are subsequence of the input then it is divisible by 8, because any number whose last three terms are
divisible 8 then that number is also divisible by eight.

Hence finding the subsequence is exactly breaking that number into multiple of 8 less than 1000
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
static int ar[130];
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
int calculate() {
    int k=0;
    while(k < 126) {
        ar[k] = k*8;
        k++;
    }
}
bool divisible(string str1, string str2, int m, int n) {
    if(m == 0) return true;
    if(n == 0) return false;
    if(str1[m-1] == str2[n-1]) return divisible(str1, str2, m-1, n-1);
    else return divisible(str1, str2, m, n-1);
}
void solve() {
    string number;
    cin >> number;
    calculate();
    for(int i=0; i<=124; i++) {
        string a = to_string(ar[i]);
        //string b = to_string(number);
        string b = number;
        //for(int i : ar)
            //cout << i << ",";
        //cout << "---" << b << endl;
        if(divisible(a, b, a.length(), b.length())) {
            cout << "YES" << endl;
            cout << a << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;
}
int main() {
  __fastio;
  solve();
  return 0;
}
