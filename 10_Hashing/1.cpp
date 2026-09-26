#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> distinct_after(n + 1, 0);
    unordered_set<int> seen_right;
    for (int i = n - 1; i >= 0; --i) {
        seen_right.insert(arr[i]);
        distinct_after[i] = seen_right.size();
    }
    
    unordered_set<int> seen_left;
    long long total_pairs = 0;
    for (int i = 0; i < n; ++i) {
        if (seen_left.find(arr[i]) == seen_left.end()) {
            seen_left.insert(arr[i]);
            total_pairs += distinct_after[i + 1];
        }
    }
    cout << total_pairs << "\n";
    return 0;
}

