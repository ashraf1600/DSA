#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int s = 0;

    void push(int val) {
        s++;
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        s--;
        Node* del = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete del;
    }

    int Front() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->data;
    }

    int size() {
        return s;
    }

    bool is_empty() {
        return s == 0;
    }
};

int main() {
    myQueue q;
    while (true) {
        cout << "OPTION 1: Push " << endl;
        cout << "OPTION 2: Pop " << endl;
        cout << "OPTION 3: Print front " << endl;
        cout << "OPTION 4: Print queue " << endl;
        cout << "OPTION 5: Exit" << endl;

        int x;
        cin >> x;
        if (x == 1) {
            int val;
            cin >> val;
            q.push(val);
        } else if (x == 2) {
            q.pop();
        } else if (x == 3)
        {
            int f = q.Front();
            if (f != -1) {
                cout << "Front: " << f << endl;
            }
        } else if (x == 4)
        {
            if (q.is_empty())
			{
                cout << "Queue is empty" << endl;
            }
            else
            {
                myQueue tempQueue; // To preserve original queue
                while (!q.is_empty())
                {
                    int front = q.Front();
                    cout << front << " ";
                    tempQueue.push(front);
                    q.pop();
                }
                cout << endl;

                // Restore original queue
                while (!tempQueue.is_empty())
				{
                    q.push(tempQueue.Front());
                    tempQueue.pop();
                }
            }
        }
         else
        {
            break;
        }
    }
    return 0;
}
