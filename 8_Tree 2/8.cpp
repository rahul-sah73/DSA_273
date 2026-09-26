#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    map<int, int> freq;
    int max_freq = 0;
    int winner_age = -1;
    
    int i = 0;
    for(i = 0;i<n-1;i++) {
        int age;
        cin >> age;
        freq[age]++;
        if (freq[age] > max_freq) {
            max_freq = freq[age];
            winner_age = age;
        } else if (freq[age] == max_freq) {
            if (age > winner_age) {
                winner_age = age;
            }
        }
        cout << winner_age << " " << max_freq << "\n";
    }
    
    // Last day
    if (n > 0) {
        int age;
        cin >> age;
        freq[age]++;
        if (freq[age] > max_freq) {
            max_freq = freq[age];
            winner_age = age;
        } else if (freq[age] == max_freq) {
            if (age > winner_age) {
                winner_age = age;
            }
        }
        cout << winner_age << " " << max_freq << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

