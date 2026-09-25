#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> st;
    bool balanced = true;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                balanced = false;
                break;
            }
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                balanced = false;
                break;
            }
        }
    }
    if (!st.empty()) {
        balanced = false;
    }
    if (balanced)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    cout << endl << "CH.SC.U4CSE25273" << endl;
    return 0;
}