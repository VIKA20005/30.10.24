#include <iostream>

template<typename T>
class Node 
{
public:
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class Queue 
{
private:
    Node<T>* front;
    Node<T>* rear;
    size_t size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    bool isEmpty() const 
    {
        return size == 0;
    }

    size_t getSize() const 
    {
        return size;
    }

    void enqueue(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else 
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        Node<T>* temp = front;
        front = front->next;
        if (front) 
        {
            front->prev = nullptr;
        }
        else 
        {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    T peek() const 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }
};

int main() 
{
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front element: " << q.peek() << std::endl; 
    std::cout << "Queue size: " << q.getSize() << std::endl; 

    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl; 
    std::cout << "Queue size after dequeue: " << q.getSize() << std::endl;

    return 0;
}