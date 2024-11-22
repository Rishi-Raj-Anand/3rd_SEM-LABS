#include <iostream>
#include <stack>
using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    void dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        cout << stack2.top() << " dequeued from the queue." << endl;
        stack2.pop();
    }

    void display() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (!stack2.empty()) {
            stack<int> temp = stack2;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        }

        stack<int> temp = stack1;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingTwoStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue after enqueue operations: ";
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "Queue after dequeue operations: ";
    q.display();

    return 0;
}
