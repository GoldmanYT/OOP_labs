#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

#define TASK 8

#if TASK == 1
template <typename T>
class List {
    struct Node {
        Node* next;
        T value;
    };
    Node* head;
    Node* tail;

public:
    List()
        : head(nullptr)
        , tail(nullptr)
    {
    }
    ~List()
    {
    }

    void push(const T newValue)
    {
        Node* nextNode = new Node { nullptr, newValue };
        if (tail != nullptr) {
            tail->next = nextNode;
        } else {
            head = nextNode;
        }
        tail = nextNode;
    }
    void remove(const T removeValue)
    {
        Node* currentNode = head;
        Node* previousNode = nullptr;
        while (currentNode != nullptr) {
            if (currentNode->value == removeValue) {
                if (previousNode != nullptr) {
                    previousNode->next = currentNode->next;
                    if (currentNode->next == nullptr) {
                        tail = previousNode;
                    }
                } else {
                    head = currentNode->next;
                }
                delete currentNode;
                break;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    bool find(const T findValue)
    {
        List::Node* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->value == findValue) {
                cout << findValue << " is in List\n";
                return true;
            }
            currentNode = currentNode->next;
        }
        cout << findValue << " is not in List\n";
        return false;
    }

    friend ostream& operator<<(ostream& out, const List<T>& self)
    {
        List::Node* currentNode = self.head;
        out << "[";
        while (currentNode != nullptr) {
            out << currentNode->value;
            if (currentNode->next != nullptr) {
                out << ", ";
            }
            currentNode = currentNode->next;
        }
        return out << "]\n";
    }
};
#endif

#if TASK == 9
template <typename T>
class Greater {
public:
    bool operator()(T& first, T& second)
    {
        return abs(first) < abs(second);
    }
};
#endif

int main()
{
    setlocale(0, "RUS");
#if TASK == 1
    List<int> lst;

    lst.push(1);
    lst.push(2);
    lst.push(3);
    cout << lst;
    lst.find(2);

    lst.remove(2);
    cout << lst;
    lst.find(2);

    lst.remove(5);
    lst.remove(1);
    lst.remove(3);
    cout << lst;
#endif

#if TASK == 5
    list<int> lst;
    deque<int> dq;

    for (int i = 0; i < 10; i++) {
        lst.push_back(i * 2);
        dq.push_back(i * 2);
    }

    for (int x = 5; x < 7; x++) {
        if (find(lst.begin(), lst.end(), x) != lst.end()) {
            cout << x << " найдено в списке\n";
        } else {
            cout << x << " не найдено в списке\n";
        }
        if (find(dq.begin(), dq.end(), x) != dq.end()) {
            cout << x << " найдено в деке\n";
        } else {
            cout << x << " не найдено в деке\n";
        }
    }
#endif

#if TASK == 6
    list<int> lst = { 1, 2, 3, 1, 2 };
    cout << "count of 1: " << count(lst.begin(), lst.end(), 1);
#endif

#if TASK == 8
    list<int> lst1 = { 1, 2, 3 },
              lst2 = { 4, 5 },
              lst3(5, 0);
    merge(lst1.begin(), lst1.end(), lst2.begin(), lst2.end(), lst3.begin());
    cout << "lst1: ";
    for (auto& elem : lst1) {
        cout << elem << " ";
    }
    cout << "\nlst2: ";
    for (auto& elem : lst2) {
        cout << elem << " ";
    }
    cout << "\nlst3: ";
    for (auto& elem : lst3) {
        cout << elem << " ";
    }
#endif

#if TASK == 9
    vector<int> vec = { 10, 23, 5, 58, -23, 12, -80 };
    sort(vec.begin(), vec.end(), Greater<int>());
    for (auto& elem : vec) {
        cout << elem << " ";
    }
#endif

#if TASK == 12
    list<int> lst = { 11, 22, 33, 44, 55 };

    for (list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
#endif

    return 0;
}