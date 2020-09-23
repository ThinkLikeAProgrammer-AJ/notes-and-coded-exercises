#include <iostream>
using namespace std;
/**
PROBLEM: DECODE A MESSAGE

A message has been encoded as a text stream that is to be read character by charac-
ter. The stream contains a series of comma-delimited integers, each a positive number

capable of being represented by a C++ int. However, the character represented by
a particular integer depends on the current decoding mode. There are three modes:
uppercase, lowercase, and punctuation.
In uppercase mode, each integer represents an uppercase letter: The integer
modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an input
value of 143 in uppercase mode would yield the letter H because 143 modulo 27 is
8 and H is the eighth letter in the alphabet.
The lowercase mode works the same but with lowercase letters; the remainder of
dividing the integer by 27 represents the lowercase letter (1 = a and so on). So an
input value of 56 in lowercase mode would yield the letter b because 57 modulo 27
is 2 and b is the second letter in the alphabet.

In punctuation mode, the integer is instead considered modulo 9, with the inter-
pretation given by Table 2-3 below. So 19 would yield an exclamation point because

19 modulo 9 is 1.
At the beginning of each message, the decoding mode is uppercase letters. Each

time the modulo operation (by 27 or 9, depending on mode) results in 0, the decod-
ing mode switches. If the current mode is uppercase, the mode switches to lowercase

letters. If the current mode is lowercase, the mode switches to punctuation, and if it is
punctuation, it switches back to uppercase.

- See notes for the process used to solve this problem.
**/
// CE = Code Experiment
void twoDigitConversionCEone();
void twoDigitConversionCEtwo();
void threeOrFourDigitConversionCEone();
void threeOrFourDigitConversionCEtwo();
void convertCharToIntOfAnyLengthCE();

void convertCharInputToInteger();

int main() {
    convertCharInputToInteger();
    return 0;
}

//----------------------------- Convert a series of comma seperated characters representing numbers to integers ----------------------------------------
// Code Experiment: convert a two digit char to int
void twoDigitConversionCEone() {
    cout << "Enter a two-digit number: ";
    // cin.get returns value of 1 stream buffer entry so if input = "12" the cin.get returns '1'
    char digitChar1 = cin.get();
    char digitChar2 = cin.get();
    int digit1 = digitChar1 - '0';
    int digit2 = digitChar2 - '0';
    int overallNumber = digit1 * 10 + digit2;
    cout << "That number as an integer: " << overallNumber << endl;
}

// Code Experiment: convert a two digit char to int using 1 char var and 1 int var
void twoDigitConversionCEtwo() {
    cout << "Enter a two-digit number: ";
    // cin.get returns value of 1 stream buffer entry so if input = "12" the cin.get returns '1'
    char digitChar1 = cin.get();
    int digit1 = digitChar1 - '0';
    int overallNumber = digit1 * 10;
    digitChar1 = cin.get();
    digit1 = digitChar1 - '0';
    overallNumber += digit1;
    cout << "That number as an integer: " << overallNumber << endl;
}

// Code Experiment: convert a three to four digit char string to an integer using 2 int vars.
void threeOrFourDigitConversionCEone() {
    cout << "enter a three or four digit number: ";
    char digitChar = cin.get();
    int threeDigitNumber = (digitChar - '0') * 100;
    int fourDigitNumber = (digitChar - '0') * 1000;
    digitChar = cin.get();
    threeDigitNumber += (digitChar - '0') * 10;
    fourDigitNumber += (digitChar - '0') * 100;
    digitChar = cin.get();
    threeDigitNumber += (digitChar - '0');
    fourDigitNumber += (digitChar - '0') * 10;
    digitChar = cin.get();
    if(digitChar == 10) {
        cout << "Number entered: " << threeDigitNumber << endl;
    } else {
        fourDigitNumber += (digitChar - '0');
        cout << "Number entered: " << fourDigitNumber << endl;
    }
}

// Code Experiment: convert a three to four digit char string to an integer using 1 int var.
void threeOrFourDigitConversionCEtwo() {
    cout << "enter a three or four digit number: ";
    char digitChar = cin.get();
    int number = (digitChar - '0') * 100;
    digitChar = cin.get();
    number += (digitChar - '0') * 10;
    digitChar = cin.get();
    number += (digitChar - '0');
    digitChar = cin.get();
    if(digitChar == 10) {
        cout << "Number entered: " << number << endl;
    } else {
        number = (number*10) + (digitChar - '0');
        cout << "Number entered: " << number << endl;
    }
}

// Code Experiment (General Solution): Converting char string of digits of any length to an integer
void convertCharToIntOfAnyLengthCE() {
    cout << "Enter a number: ";
    char digitChar = cin.get();
    int number = (digitChar - '0');
    digitChar = cin.get();
    while (digitChar != 10) {
        number = (number * 10) + (digitChar - '0');
        digitChar = cin.get();
    }
    cout << "Number entered: " << number << endl;
}

// Solution
void convertCharInputToInteger() {
    char digitChar;
    cout << "Enter a list ofcomma seperted numbers: ";
    do {
        digitChar = cin.get();
        int number = (digitChar - '0');
        digitChar = cin.get();
        while ((digitChar != 10) && (digitChar != ',')) {
            number = (number * 10) + (digitChar - '0');
            digitChar = cin.get();
        }
        cout << "Number entered: " << number << endl;
    } while(digitChar != 10);
}