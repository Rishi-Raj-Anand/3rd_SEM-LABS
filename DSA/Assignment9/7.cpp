#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int findMin(queue<int>& q) {
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return INT_MAX;
    }

    int minElement = INT_MAX;
    queue<int> tempQueue = q;

    while (!tempQueue.empty()) {
        minElement = min(minElement, tempQueue.front());
        tempQueue.pop();
    }

    return minElement;
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(5);
    q.push(30);
    q.push(15);

    cout << "Minimum element in the queue: " << findMin(q) << endl;

    cout << "Queue after finding minimum: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
