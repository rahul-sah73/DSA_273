#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int T;
    if (!(cin >> T)) return;
    int k;
    for(k=1;k<=T;++k) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<int> b(N+1);
        for(int i = 0; i < N; ++i) {
            b[i] = s[i] - '0';
        }
        
        int len = (N + 1) / 2;
        int max_sum = 0;
        int current_sum = 0;
        for (int i = 0; i < len; ++i) {
            current_sum += b[i];
        }
        max_sum = current_sum;
        for (int i = len; i < N; ++i) {
            current_sum += b[i] - b[i - len];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        cout << max_sum << "\n";
    }
}

int main() {
    solve();
    return 0;
}
