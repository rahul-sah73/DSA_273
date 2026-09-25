#include <iostream>
using namespace std;

int main() {
    int dollar, items;
    cin >> dollar >> items;

    char name[100][50];
    int price[100];

    for (int i = 0; i < items; i++) {
        cin >> name[i] >> price[i];
    }

    // Sort by price so the cheapest items are checked first.
    for (int i = 0; i < items; i++) {
        for (int j = i + 1; j < items; j++) {
            if (price[i] > price[j]) {
                swap(price[i], price[j]);

                char temp[50];
                for (int k = 0; k < 50; k++) {
                    temp[k] = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = temp[k];
                }
            }
        }
    }

    int count = 0;

    for (int i = 0; i < items; i++) {
        if (price[i] <= dollar) {
            cout << "I can afford " << name[i] << endl;
            dollar -= price[i];
            count++;
        } else {
            cout << "I can't afford " << name[i] << endl;
        }
    }

    if (count == 0) {
        cout << "I need more Dollar!" << endl;
    }

    cout << "Remaining money: " << dollar << endl;
    return 0;
}