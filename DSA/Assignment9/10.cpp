#include <iostream>
#include <queue>
using namespace std;

int sumOfQueue(queue<int>& q) {
    int sum = 0;
    queue<int> tempQueue = q;

    while (!tempQueue.empty()) {
        sum += tempQueue.front();
        tempQueue.pop();
    }

    return sum;
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "Sum of elements in the queue: " << sumOfQueue(q) << endl;

    cout << "Queue after sum calculation (unchanged): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
