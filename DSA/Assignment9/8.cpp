#include <iostream>
#include <queue>
using namespace std;

queue<int> mergeQueues(queue<int>& q1, queue<int>& q2) {
    queue<int> mergedQueue;

    while (!q1.empty()) {
        mergedQueue.push(q1.front());
        q1.pop();
    }

    while (!q2.empty()) {
        mergedQueue.push(q2.front());
        q2.pop();
    }

    return mergedQueue;
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q1, q2;

    q1.push(10);
    q1.push(20);
    q1.push(30);

    q2.push(40);
    q2.push(50);
    q2.push(60);

    queue<int> q1Copy = q1;  // Create a copy of q1 to display
    queue<int> q2Copy = q2;  // Create a copy of q2 to display

    cout << "Queue 1: ";
    displayQueue(q1Copy);

    cout << "Queue 2: ";
    displayQueue(q2Copy);

    queue<int> mergedQueue = mergeQueues(q1, q2);

    cout << "Merged Queue: ";
    displayQueue(mergedQueue);

    return 0;
}
