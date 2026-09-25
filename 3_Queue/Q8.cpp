#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, frames;
    cin >> n >> frames;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int page;
        cin >> page;
        bool found = false;
        queue<int> temp;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == page) {
                found = true;
            }
            else {
                temp.push(x);
            }
        }
        q = temp;
        if (found) {
            q.push(page);
        }
        else {
            if ((int)q.size() == frames) {
                q.pop();
            }
            q.push(page);
        }
    }
    while (!q.empty()) {
        int x = q.back();
        queue<int> temp;
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        cout << x << " ";
        q = temp;
    }
    cout << endl;
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}