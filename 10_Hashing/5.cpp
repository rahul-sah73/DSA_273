#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    if (getline(cin, s)) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        char best_char = 0;
        int max_freq = -1;
        
        for (auto p : freq) {
            if (p.second > max_freq) {
                max_freq = p.second;
                best_char = p.first;
            } else if (p.second == max_freq) {
                if (p.first < best_char) {
                    best_char = p.first;
                }
            }
        }
        
        if (max_freq != -1) {
            cout << best_char << " " << max_freq << "\n";
        }
    }
    return 0;
}

