#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char numbers[13][20] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR",
        "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
        "TEN", "ELEVEN", "TWELVE"
    };

    int input[100];
    int size = 0;
    int maxCount[26] = {0};

    int n;
    while (true) {
        cin >> n;
        if (n == 999) {
            break;
        }

        input[size++] = n;

        char word[20];
        for (int i = 0; numbers[n][i] != '\0'; i++) {
            word[i] = numbers[n][i];
        }
        word[strlen(word)] = '\0';

        int tempCount[26] = {0};
        for (int i = 0; word[i] != '\0'; i++) {
            int index = word[i] - 'A';
            tempCount[index]++;
        }

        for (int i = 0; i < 26; i++) {
            if (tempCount[i] > maxCount[i]) {
                maxCount[i] = tempCount[i];
            }
        }
    }

    cout << "Numbers entered: ";
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    cout << "999\n";

    cout << "Letters with maximum usage: ";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < maxCount[i]; j++) {
            cout << char('A' + i) << " ";
        }
    }
    cout << endl;

    return 0;
}
