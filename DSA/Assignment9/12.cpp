#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstKElements(queue<int>& q, int k) {
    if (q.empty() || k <= 0) return;

    stack<int> s;

    // Step 1: Push the first k elements into the stack
    for (int i = 0; i < k && !q.empty(); ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop elements from the stack and enqueue them back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements (after first k) to the back of the queue
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(queue<int>& q) {
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, k;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "Original Queue: ";
    displayQueue(q);

    reverseFirstKElements(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    displayQueue(q);

    return 0;
}
