#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool isPalindrome(const string& str) {
    queue<char> q;

    // Enqueue each character of the string into the queue
    for (char ch : str) {
        q.push(ch);
    }

    // Check if the string is a palindrome
    for (char ch : str) {
        if (ch != q.front()) {
            return false;
        }
        q.pop();
    }

    return true;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
