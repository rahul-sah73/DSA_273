#include <iostream>
using namespace std;
class twoStacks {
    int arr[100];
    int top1 , top2;
public:
    twoStacks() {
        top1 = -1;
        top2 = 100;
    }
    void push1(int x) {
        if (top1 + 1 < top2) {
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x) {
       if (top1 + 1 < top2) {
            top2--;
            arr[top2] = x;
        }
    }
    int pop1() {
        if (top1 == -1)
            return -1;

        return arr[top1--];
    }
    int pop2() {
        if (top2 == 100)
            return -1;

        return arr[top2++];
    }
};
int main() {
    twoStacks s;
    int x;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        if (i % 2 == 0)
            s.push1(x);
        else
            s.push2(x);
    }
    cout << "Popped element from stack1 is:" << s.pop1() << endl;
    cout << "Popped element from stack2 is:" << s.pop2() << endl;
    cout << endl << "CH.SC.U4CSE25273" << endl;
    return 0;
}