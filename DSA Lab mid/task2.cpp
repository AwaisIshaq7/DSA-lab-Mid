#include <iostream>
#include <stack>
#include <cctype>
#include<string>

using namespace std;

int main() {
    stack<char> charStack;
    string input;

    cout << "Enter a string ending with a full stop to complete it: ";
    getline(cin, input, '.');

    if (input.length() > 80) {
        cout << "\nThe Input exceeds the maximum length of 80 characters.\n";
        return 1;
    }
   
    for (char ch : input) {
        if (ch != ' ') {
            charStack.push(toupper(ch));
        }
    }
    bool isPalindrome = true;
    for (char ch : input) {
        if (ch != ' ') {
            if (toupper(ch) != charStack.top()) {
                isPalindrome = false;
                break;
            }
            charStack.pop();
        }
    }

                                     // Output 
    cout << "\n--- Result ---\n";
    if (isPalindrome) {
        cout << "The string you entered is : "<<input<<"\nYes, It is a palindrome.\n";
    }
    else {
        cout << "The string you entered is: "<<input <<"\nNo, It is not a palindrome.\n";
    }

    return 0;
}
