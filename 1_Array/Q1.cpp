#include <iostream>
using namespace std;

int main() {
    int n;

    int value[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    string symbol[] = {
        "R", "GR", "G", "BG",
        "B", "ZB", "P", "ZP",
        "Z", "BZ", "W", "BW", "B"
    };
    
    int i = 5;

    while (i--) {
        cin >> n;
        string result = "";

        for (int i = 0; i < 13; i++) {
            while (n >= value[i]) {
                result += symbol[i];
                n -= value[i];
            }
        }

        cout << result << endl;
    }

    cout << "CH.SC.U4CSE25273" << endl;

    return 0;
}