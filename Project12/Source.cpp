#include <iostream>  
#include <stdexcept>  
using namespace std;
// Шаблонный класс для узла двусвязного списка  
template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Шаблонный класс Очередь  
template<typename T>
class Queue {
private:
    Node<T>* front; // Указатель на передний элемент очереди  
    Node<T>* back;  // Указатель на задний элемент очереди  

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Метод для добавления элемента в очередь  
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

    // Метод для удаления элемента из очереди  
    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста! Невозможно выполнить операцию dequeue.");
        }
        Node<T>* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr; // Очередь пуста  
        }
        delete temp;
    }

    // Метод для получения значения переднего элемента очереди  
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста! Невозможно выполнить операцию peek.");
        }
        return front->data;
    }

    // Метод для проверки, является ли очередь пустой  
    bool isEmpty() const {
        return front == nullptr;
    }
};

// Пример использования очереди  
int main() {
    setlocale(LC_ALL, "Russian");
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Передний элемент: " << queue.peek() << endl;

    while (!queue.isEmpty()) {
       cout << "Извлекаем: " << queue.peek() << endl;
        queue.dequeue();
    }

    return 0;
}