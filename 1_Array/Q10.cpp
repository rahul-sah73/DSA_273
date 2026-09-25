#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100

int s[MAXN];

void sol(int n) {
    sort(s, s + n);

    int treats = 0;
    int rank = 1;

    for (int i = 0; i < n; ) {
        int j = i;

        while (j < n && s[j] == s[i]) {
            j++;
        }

        int count = j - i;

        treats += count * rank;
        rank++;

        i = j;
    }

    cout << treats << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        sol(n);
    }

    cout << "CH.SC.U4CSE25273" << endl;

    return 0;
}