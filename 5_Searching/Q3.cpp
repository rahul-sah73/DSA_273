#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[309][309];
bool ok[309][309][309];

void solve() {
    int R, C, L;
    if (!(cin >> R >> C >> L)) return;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> A[r][c];
        }
    }
    
    for (int r = 0; r < R; r++) {
        for (int c1 = 0; c1 < C; c1++) {
            int min_val = A[r][c1];
            int max_val = A[r][c1];
            ok[r][c1][c1] = true;
            for (int c2 = c1 + 1; c2 < C; c2++) {
                if (A[r][c2] < min_val) min_val = A[r][c2];
                if (A[r][c2] > max_val) max_val = A[r][c2];
                ok[r][c1][c2] = (max_val - min_val <= L);
            }
        }
    }
    
    int max_area = 0;
    for (int c1 = 0; c1 < C; c1++) {
        for (int c2 = c1; c2 < C; c2++) {
            int width = c2 - c1 + 1;
            int current_streak = 0;
            for (int r = 0; r < R; r++) {
                if (ok[r][c1][c2]) {
                    current_streak++;
                    if (current_streak * width > max_area) {
                        max_area = current_streak * width;
                    }
                } else {
                    current_streak = 0;
                }
            }
        }
    }
    cout << max_area << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
