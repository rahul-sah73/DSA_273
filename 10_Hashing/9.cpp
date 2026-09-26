#include <iostream>
#include <vector>

using namespace std;

int divisors[1000005];

void precompute() {
    for (int i = 1; i <= 1000000; ++i) {
        for (int j = i; j <= 1000000; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int N;
    if (!(cin >> N)) return 0;
    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> freq(1000005, 0);
    
    int x;
    cin >> x;
    freq[divisors[x]]++;
    
    while (--N) {
        cin >> x;
        freq[divisors[x]]++;
    }
    
    long long total_pairs = 0;
    for (int count : freq) {
        if (count >= 2) {
            total_pairs += (long long)count * (count - 1) / 2;
        }
    }
    
    cout << total_pairs << "\n";
    
    return 0;
}

