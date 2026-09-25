#include <iostream>
#include <queue>
#include <string>
using namespace std;
int longest(queue<char> q) {
    if (q.empty()) {
        return 0;
    }
    char previous = q.front();
    q.pop();
    int count = 1;
    int answer = 1;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        if (current == previous) {
            count++;
        }
        else {
            count = 1;
        }
        if (count > answer) {
            answer = count;
        }
        previous = current;
    }
    return answer;
}
int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        if (s[x] == '0') {
            s[x] = '1';
        }
        else {
            s[x] = '0';
        }
        queue<char> q;
        for (int j = 0; j < s.length(); j++) {
            q.push(s[j]);
        }
        cout << longest(q) << endl;
    }
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}