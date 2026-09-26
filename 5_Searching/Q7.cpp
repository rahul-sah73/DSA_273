#include <iostream>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        double width, height;
        cin >> width >> height;
        if(width/height>=1.6 && width/height<=1.7) {
            count++;
        }
        else if(height/width >=1.6 && height/width<=1.7) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
