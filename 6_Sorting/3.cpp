#include <iostream>
#include <vector>
using namespace std;

void insertionSort(long int *p, long int n) {
    for (int i = 1; i < n; i++) {
        long int key = p[i];
        int j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}

int main() {
    int q;
    if (!(cin >> q)) return 0;
    while(q--) {
        long int n;
        cin >> n;
        long int capacity[105] = {0};
        long int typeCount[105] = {0};
        
        long int i;
        for(i=0;i<n;i++) {
            for(int j=0; j<n; j++) {
                long int x; cin >> x;
                capacity[i] += x;
                typeCount[j] += x;
            }
        }
        
        insertionSort(capacity, n);
        insertionSort(typeCount, n);
        
        bool possible = true;
        for(i=0;i<n;i++) {
            if (capacity[i] != typeCount[i]) {
                possible = false;
                break;
            }
        }
        if (possible) cout << "Possible";
        else cout << "Impossible";
    }
    return 0;
}
