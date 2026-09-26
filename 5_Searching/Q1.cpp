#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define LEN 50

int main() {
    char var[3][LEN];
    char inp[3][LEN];
    
    cin >> var[0] >> inp[0];
    cin >> var[1] >> inp[1];
    cin >> var[2] >> inp[2];
    
    cout << fixed << setprecision(2);
    if (inp[0][0] == '?') {
        cout << "m " << -atof(inp[1]) * atof(inp[2]) << endl;
    } else if (inp[1][0] == '?') {
        cout << "d " << -atof(inp[0]) / atof(inp[2]) << endl;
    } else if (inp[2][0] == '?') {
        cout << "x " << -atof(inp[0]) / atof(inp[1]) << endl;
    }
    
    return 0;
}
