#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long find_val(long long x, const vector<long long>& P) {
    int l = 1;
    int ans1 = P.size() - 1;
    while(l<ans1) {
        int mid = l + (ans1 - l) / 2;
        if (P[mid] >= x) {
            ans1 = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    vector<long long> P;
    P.push_back(0);
    long long i = 1;
    while (true) {
        long long f = i * (long long)floor(sqrt(i)) + (i + 1) / 2;
        long long next_P = P.back() + f;
        P.push_back(next_P);
        if (next_P >= 100000000000000LL) { // 10^14 just in case
            break;
        }
        i++;
    }
    
    int Q;
    if (!(cin >> Q)) return 0;
    while (Q--) {
        long long L, R;
        cin >> L >> R;
        if (L > R) swap(L, R);
        
        long long valL = find_val(L, P);
        long long valR = find_val(R, P);
        
        cout << (valR - valL + 1) << "\n";
    }
    return 0;
}
