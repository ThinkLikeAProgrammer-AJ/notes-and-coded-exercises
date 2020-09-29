#include <iostream>
using namespace std;

void outputFirstHalfOfHashes();
void outputSecondHalfOfHashes();

int main() {
    outputFirstHalfOfHashes();
    outputSecondHalfOfHashes();
    return 0;
}

//--------------------------------------------------- output sequentially 2,4,6,8 # on seperate lines ---------------------------------------
void outputFirstHalfOfHashes() {
    int numHashes = 2;
    int hashNum;
    for(int i = 0; i < 4; i++) {
        hashNum = 0;
        for(int space = 3; space > i; space--) {
            cout << " ";
        }
        while(hashNum < numHashes) {
            cout << "#";
            hashNum++;
        }
        cout << "\n";
        numHashes = numHashes + 2;
    }  
}

//---------------------- output sequentially 8,6,4,2 # on seperate lines -----------------------------
void outputSecondHalfOfHashes() {
    int numHashes = 8;
    int hashNum;
    for(int i = 0; i < 4; i++) {
        hashNum = 0;
        for(int space = 0; space < i; space++) {
            cout << " ";
        }
        while(hashNum < numHashes) {
            cout << "#";
            hashNum++;
        }
        cout << "\n";
        numHashes = numHashes - 2;
    }  
}