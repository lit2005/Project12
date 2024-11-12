#include <iostream>  
#include <stdexcept>  
using namespace std;
// ��������� ����� ��� ���� ����������� ������  
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// ��������� ����� �������  
template<typename T>
class Queue {
private:
    Node<T>* front; // ��������� �� �������� ������� �������  
    Node<T>* back;  // ��������� �� ������ ������� �������  

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // ����� ��� ���������� �������� � �������  
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
    }

    // ����� ��� �������� �������� �� �������  
    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("������� �����! ���������� ��������� �������� dequeue.");
        }
        Node<T>* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr; // ������� �����  
        }
        delete temp;
    }

    // ����� ��� ��������� �������� ��������� �������� �������  
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("������� �����! ���������� ��������� �������� peek.");
        }
        return front->data;
    }

    // ����� ��� ��������, �������� �� ������� ������  
    bool isEmpty() const {
        return front == nullptr;
    }
};

// ������ ������������� �������  
int main() {
    setlocale(LC_ALL, "Russian");
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "�������� �������: " << queue.peek() << endl;

    while (!queue.isEmpty()) {
       cout << "���������: " << queue.peek() << endl;
        queue.dequeue();
    }

    return 0;
}