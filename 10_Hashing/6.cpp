#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int M, Q, N;
    if (!(std::cin >> M >> Q >> N)) return 0;
    
    std::vector<int> A(N);
    std::vector<int> hash(1000005, 0);
    
    for(int i=0; i<N; i++) {
        std::cin >> A[i];
        hash[A[i]]++;
    }
    
    std::vector<int> v_count(1005000, 0);
    int max_rating = 0;
    
    for (int i = 0; i <= 1000000; ++i) {
        if (hash[i] > 0) {
            for (int k = -Q; k <= Q; ++k) {
                int v = i + k * M;
                int idx = v + 2000;
                v_count[idx] += hash[i];
                if (v_count[idx] > max_rating) {
                    max_rating = v_count[idx];
                }
            }
        }
    }
    
    std::cout << max_rating << "\n";
    
    return 0;
}

