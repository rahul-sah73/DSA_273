#include <iostream>
#include <vector>

using namespace std;

int preIndex = 0;

void printPostOrder(const vector<int>& in, const vector<int>& pre, int inStrt, int inEnd, const vector<int>& hash) {
    if (inStrt > inEnd) {
        return;
    }
    
    int rootNode = pre[preIndex++];
    int inIndex = hash[rootNode];
    
    printPostOrder(in, pre, inStrt, inIndex - 1, hash);
    printPostOrder(in, pre, inIndex + 1, inEnd, hash);
    
    cout << rootNode << " ";
}

int main() {
    int n, i;
    if (!(cin >> n)) return 0;
    
    vector<int> pre(n);
    vector<int> in(n);
    vector<int> hash(100005, 0); 
    
    for (i = 0; i < n; i++) {
        cin >> pre[i];
    }
    
    for(i=1;i<=n;i++) {
        cin >> in[i-1];
        hash[in[i-1]] = i - 1;
    }
    
    printPostOrder(in, pre, 0, n - 1, hash);
    cout << endl;
    
    return 0;
}
