#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define MAXP 100
#define BUFLEN 105

int main() {
    const char *gems[]={"NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis",0};
    char ponies[MAXP][BUFLEN];
    int n = 0;
    while(cin.getline(ponies[n], BUFLEN)) {
        if(strcmp(ponies[n], "END") == 0) {
            break;
        }
        n++;
    }
    
    for(int a=0; a<n-1; a++) {
        for(int b=a+1; b<n; b++) {
            int pA = 0, pB = 0;
            
            char tempA[BUFLEN];
            strcpy(tempA, ponies[a]);
            char *tokenA = strtok(tempA, " ");
            while(tokenA != NULL) {
                for(int i=1; gems[i] != 0; i++) {
                    if(strcmp(tokenA, gems[i]) == 0 && i > pA) {
                        pA = i;
                    }
                }
                tokenA = strtok(NULL, " ");
            }
            
            char tempB[BUFLEN];
            strcpy(tempB, ponies[b]);
            char *tokenB = strtok(tempB, " ");
            while(tokenB != NULL) {
                for(int i=1; gems[i] != 0; i++) {
                    if(strcmp(tokenB, gems[i]) == 0 && i > pB) {
                        pB = i;
                    }
                }
                tokenB = strtok(NULL, " ");
            }
            
            if(pA < pB) {
                char temp[BUFLEN];
                strcpy(temp, ponies[a]);
                strcpy(ponies[a], ponies[b]);
                strcpy(ponies[b], temp);
            } else if(pA == pB) {
                if(strcmp(ponies[a],ponies[b])>0) {
                    char temp[BUFLEN];
                    strcpy(temp, ponies[a]);
                    strcpy(ponies[a], ponies[b]);
                    strcpy(ponies[b], temp);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << ponies[i] << endl;
    }
    
    return 0;
}
