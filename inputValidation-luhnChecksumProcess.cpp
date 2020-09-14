#include <iostream>
using namespace std;

/**
LUHN CHECKSUM VALIDATION

The Luhn formula is a widely used system for validating identification numbers. 

Using the original number, double the value of every other digit. 

Then add the values of the individual digits together (if a doubled value now has two digits, add the digits indi-
vidually). 

The identification number is valid if the sum is divisible by 10.

Write a program that takes an identification number of arbitrary length and
determines whether the number is valid under the Luhn formula. The program must
process each character before reading the next one.
 **/

/**
 Issues:
 - Double every digit starting from the right end of the ID#
 - Treating doubled #s >= 10 as individual digits
 - Process user input (length = arbitrary) 1 char at a time
 - Know when end of the # is reached
 **/

// Code Experiments:
// void confirmRange();
// void confirmCharToInt()
// void confirmLuhnFixedlength();
// void discoverEndCharacter();
// void confirmLuhnEvenArbitraryLength();
// void determinePosOrNeg();

int sumOfDoubledDigitValue(int digit);
void luhnChecksumAlgorithm();

int main() {
    luhnChecksumAlgorithm();
    return 0;
}

//--------------------------------- Treating doubled #s >= 10 as individual digits --------------------------------------
// Code Experiment: Confirm range of double digit #s is 10-18
// void confirmRange() {
//     int digit;
//     cout << "Enter a single digit number 0-9";
//     cin >> digit;
//     /**
//      * "isolating this calculation
//      * to a short program of its own makes experimentation easy. Even if we don’t
//      * get the correct formula at first, we’re sure to find it quickly.""
//      **/    
//     int doubleDigit = digit * 2;
//     int sum;
//     if(doubleDigit >= 10) {
//         sum = 1 + (doubleDigit % 10);
//     } else {
//         sum = doubleDigit;
//     }
//     cout << "Sum of digits in doubles num = " << sum << "\n";
// }

int sumOfDoubledDigitValue(int digit) {
    int doubleDigit = digit * 2;
    int sum;
    if(doubleDigit >= 10) {
        sum = 1 + (doubleDigit % 10);
    } else {
        sum = doubleDigit;
    }
    return sum;
}

//--------------------------------- Process user input (length = arbitrary) 1 char at a time --------------------------------------
/**
"we could tackle a different issue next if we wanted, but I think
this issue is a good choice because it will allow us to type the identification
number naturally when testing the other parts of the problem."
**/
/**
Issues:
- Read a char from user representing a digit 0-9
- Convert character to the eq integer
- Output integer to demonstrate results
**/
// Code Experiment
// void confirmCharToInt() {
//     char digitChar;
//     cout << "Enter a digit 0-9";
//     cin >> digitChar;
//     int digitInt = digitChar - '0';
//     cout << digitInt;
// } 

//--------------------------------- Double every digit starting from the right end of the ID# --------------------------------------
/**
 * PROBLEM REDUCTION : To make approaching this problem/issue easier.
 * REDUCTION 1: Change input to a fixed lenght instead of an arbitrary length. lets say 6 chars
 * ISSUES 1: 
 * - Recieve 6 digit ID# including check digit
 * - Determine if # is valid under luhn
 * - Process input char by char
 * REDUCTION 2: Remove doubling of digits from luhn
 * ISSUES 1:
 * - Recieve 6 digit ID# including check digit
 * - Determine if the value of the digits added is divisible by 10
 * - Process input char by char
 * 
 * From here we can work additively starting with ISSUES 2 then 1
**/

// Code Experiment
// void confirmLuhnFixedlength() {
//     char digitChar;
//     int checksum;
//     cout << "Enter a six digit number: ";
//     for (int position = 1; position <= 6; position++) {
//         cin >> digitChar;
//         if (position % 2 == 0) {
//             checksum += digitChar - '0';
//         } else {
//             checksum += sumOfDoubledDigitValue(digitChar - '0');
//         }
//     }
//     cout << "checksum is " << checksum << ". \n";
//     if (checksum % 10 == 0) {
//         cout << "checksum is divisible by 10. valid. \n";
//     } else {
//         cout << "checksum is not divisble by 10. invalid. \n";
//     }
// }

/**
 * Now we can work towards validating numbers of any lenght
 * DIVIDE AND CONQUER :
 * - even and odd lenghthed #s are handled differently when doubling so start with one.
 * - we already implemented a fixed even so lets to arbitrary even first.
 * 
 * ISSUES :
 * - Determine when we are at the end of the number
**/

//--------------------------------- Know when end of the # is reached --------------------------------------
// Code Experiment
// void discoverEndCharacter() {
//     cout << "Enter a number: ";
//     char digit;
//     while(true) {
//         digit = cin.get();
//         cout << int(digit) << " ";
//     }
// }

// Code Experiment
// void confirmLuhnEvenArbitraryLength() {
//     char digitChar;
//     int checksum = 0;
//     int position = 1;
//     cout << "Enter a number with an even amount of digits: ";
//     // finish coding page 59
//     digitChar = cin.get();
//     while (digitChar != 10) {
//         // for odd numbers we just reverse the logic.
//         if (position % 2 == 0) {
//             checksum += digitChar - '0';
//         } else {
//             checksum += 2 * (digitChar - '0');
//         }
//         digitChar = cin.get();
//         position++;
//     }

//     cout << "checksum is " << checksum << ". \n";
//     if (checksum % 10 == 0) {
//         cout << "checksum is divisible by 10. valid. \n";
//     } else {
//         cout << "checksum is not divisble by 10. invalid. \n";
//     }
// }

/** 
 * At this point we need to determine when to use logic for even and odd length numbers by knowing if the number is even or odd
 * SOLVE BY ANOLOGY :
 * Write a program that reads 10 integers from the user. After all the numbers have
 * been entered, the user may ask to display the count of positive numbers or the count of negative numbers.
 * 
 * This shows the method we need to use for the Luhn checksum problem:
 * Keep track of the running checksum both ways, as if the identification number is an odd length and again as if it is an even length. When we get to the
 * end of the number and discover the true length, we’ll have the correct checksum in one variable or the other.
 * 
**/
// Code Anology
// void determinePosOrNeg() {
//     int number;
//     int positiveCount = 0;
//     int negativeCount = 0;
//     for (int i = 0; i <= 10; i++) {
//         cin >> number;
//         if (number > 0) positiveCount++;
//         if (number < 0) negativeCount++;
//     }

//     char response;
//     cout << "Do you want the positive or negative count? ";
//     cin >> response;
//     if (response == 'p') cout << "positive count is " << positiveCount << "\n";
//     if (response == 'p') cout << "negative count is " << negativeCount << "\n";
// }

/**
 * At this point we have solved/completed our original list of sub-problems/issues
 * 
 * Issues:
 x Double every digit starting from the right end of the ID#
 x Treating doubled #s >= 10 as individual digits
 x Process user input (length = arbitrary) 1 char at a time
 x Know when end of the # is reached
**/

//--------------------------------- Putting it all together --------------------------------------
// Each part of this program can be found in isolation above
void luhnChecksumAlgorithm() {
    char digitChar;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;

    cout << "Enter a number: ";
    digitChar = cin.get();
    while (digitChar != 10) {
        if (position % 2 == 0) {
            oddLengthChecksum += sumOfDoubledDigitValue(digitChar - '0');
            evenLengthChecksum +=  digitChar - '0';
        } else {
            evenLengthChecksum += sumOfDoubledDigitValue(digitChar - '0');
            oddLengthChecksum +=  digitChar - '0';
        }
        digitChar = cin.get();
        position++;
    }

    int checksum;
    if ((position - 1) % 2 == 0) {
        checksum = evenLengthChecksum;
    } else {
        checksum = oddLengthChecksum;
    }

    cout << "checksum is " << checksum << ". \n";
    if (checksum % 10 == 0) {
        cout << "checksum is divisible by 10. valid. \n";
    } else {
        cout << "checksum is not divisble by 10. invalid. \n";
    }
}