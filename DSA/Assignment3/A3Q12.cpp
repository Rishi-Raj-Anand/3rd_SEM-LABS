#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int totalChars = 0;
 for (int i = 1; i < argc; i++) {
        char* ptr = argv[i];
        while (*ptr != '\0') {
            totalChars++;
            ptr++;
        }
    }
    cout << "Total number of characters: " << totalChars << endl;
    return 0;
}