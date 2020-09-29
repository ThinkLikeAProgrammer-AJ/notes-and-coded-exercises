#include <iostream>
using namespace std;

// Code Experiments
void outputEightHashes();
void outputHashes();

// Final Solution
void outputHashesWithSpaces();

int main() {
    outputHashesWithSpaces();
    return 0;
}

// Final Solution: Output hashes with proper spacing
void outputHashesWithSpaces() {
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

//---------------------- output sequentially 8,6,4,2 # on seperate lines -----------------------------
// CE
void outputEightHashes() {
    int numHashes = 8;
    int i = 0;
    while(i < numHashes) {
        cout << "#";
        i++;
    }
    cout << "\n";
}

void outputHashes() {
    int numHashes = 8;
    int hashNum;
    for(int i = 0; i < 4; i++) {
        hashNum = 0;
        while(hashNum < numHashes) {
            cout << "#";
            hashNum++;
        }
        cout << "\n";
        numHashes = numHashes - 2;
    }  
}