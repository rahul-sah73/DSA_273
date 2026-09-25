#include <iostream>
#include <stack>
using namespace std;
string postToPre(string post_exp) {
    stack<string> st;
    for (int i = 0; i < post_exp.length(); i++) {

        char ch = post_exp[i];
        // If operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {
            string temp(1, ch);
            st.push(temp);
        }
        // If operator
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string result;
            result = ch + op2 + op1;
            st.push(result);
        }
    }
    return st.top();
}
int main() {
    string exp;
    cin >> exp;
    cout << postToPre(exp);
    cout << endl << "CH.SC.U4CSE25273" << endl;
    return 0;
}