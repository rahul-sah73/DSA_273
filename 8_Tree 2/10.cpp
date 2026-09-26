#include <iostream>
#include <vector>

using namespace std;

void heapify(int arr[],int n,int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void solve() {
    int M, N;
    if (!(cin >> M >> N)) return;
    
    vector<int> arr_vec(M);
    for (int i = 0; i < M; ++i) {
        cin >> arr_vec[i];
    }
    
    int* arr = arr_vec.data();
    
    for (int i = M / 2 - 1; i >= 0; i--) {
        heapify(arr, M, i);
    }
    
    long long total_revenue = 0;
    for (int i = 0; i < N; ++i) {
        total_revenue += arr[0];
        arr[0]--;
        heapify(arr, M, 0);
    }
    
    cout << total_revenue << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

