#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int N, M;

    // Read the stack size and elements
    cin >> N;
    stack<int> s;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        s.push(value);
    }

    // Read the queue size and elements
    cin >> M;
    queue<int> q;
    for (int i = 0; i < M; ++i) {
        int value;
        cin >> value;
        q.push(value);
    }

    // If sizes are different, they can't be the same
    if (N != M) {
        cout << "NO" << endl;
        return 0;
    }

    // Check if the elements are the same in the order of removal
    bool isEqual = true;
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            isEqual = false;
            break;
        }
        s.pop();
        q.pop();
    }

    if (isEqual) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
