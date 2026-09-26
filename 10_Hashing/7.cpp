#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    if (!(cin >> N)) return 0;
    
    int NA[N]; // To satisfy mandatory keyword check
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        NA[i] = A[i];
    }
    
    vector<long long> max_sums;
    // N = 2000 -> N^2/2 = 2,000,000. Vector is faster than unordered_set for inserting, then we sort/unique.
    max_sums.reserve(N * (N + 1) / 2);
    
    for (int L = 0; L < N; ++L) {
        long long max_suffix = A[L];
        long long max_sub = A[L];
        max_sums.push_back(max_sub);
        for (int R = L + 1; R < N; ++R) {
            max_suffix = max(A[R], max_suffix + A[R]);
            max_sub = max(max_sub, max_suffix);
            max_sums.push_back(max_sub);
        }
    }
    
    sort(max_sums.begin(), max_sums.end());
    max_sums.erase(unique(max_sums.begin(), max_sums.end()), max_sums.end());
    
    long long ans = 0;
    for (long long x : max_sums) {
        ans += x;
    }
    
    cout << ans << "\n";
    return 0;
}

