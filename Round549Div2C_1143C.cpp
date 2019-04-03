#include <bits/stdc++.h>
using namespace std;
int parent[100007], good[100007], cnt[100007];
//vector<int> child[100007];
//Fast I/O function
class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
    }
} __fastio;
//Solve Function
void solve() {
    int input; cin >> input;
    //1-based indexing
    for(int i=1; i<=input; i++) {
        cin >> parent[i] >> good[i];
        if(parent[i] != -1 && good[i] == 0)//not a root and a respectful child
            cnt[parent[i]]++;//then count such good childs
    }
    vector<int> unwanted_childs;
    for(int i=1; i<=input; i++) {
        //When to delete?
        //1.Not a root parent
        //2.Has disrespecting child
        //3.Disrespecting grandchild
        if(parent[i] != -1 && good[i] == 1 && cnt[i] == 0) {
            unwanted_childs.push_back(i);//doomed
        }
    }
    //No unwanted childs
    if(unwanted_childs.empty()) {
        puts("-1");
        exit(0);
    }
    //else print the deleted childs
    for(int i : unwanted_childs) cout << i << " ";
}
//Driver Method
int main() {
  __fastio;//comment it for scanf and printf
  solve();
  return 0;
}
