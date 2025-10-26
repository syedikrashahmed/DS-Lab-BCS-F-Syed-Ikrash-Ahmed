/*Task 3 – Simple Queue Implementation
Implement a linear queue using arrays with the following operations:
1. Enqueue
2. Dequeue
3. Display queue contents
4. Check if queue is empty/full*/


#include <iostream>
using namespace std;


class Queue{
private:
    int *arr;
    int front;
    int rear;
    int  size;
   
public:
    Queue(int size): size(size), front(-1), rear(-1){
        arr = new int[size];
    }
   
    void enqueue(int value) {
        if (isFull()) {
            cout<< "queue is full cannot push"<< endl;
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear++;
        arr[rear] =value;
        cout << "Enqueued: "<< value << endl;
    }
   
    void dequeue() {
        if (isEmpty()){
            cout << "queue empty cannot pop"<< endl;
            return;
        }
        cout<< "Dequeued: " <<arr[front] << endl;
        if (front==rear) {
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
    }
   
    void display() {
        if (!isEmpty()) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Queue empty" << endl;
        }
    }
   
    bool isEmpty() {
        return front == -1;
    }
   
    bool isFull() {
        return rear == size - 1;
    }
   
    ~Queue() {
        delete[] arr;
    }
};


int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
   
    q.display();    
    q.dequeue();
    q.dequeue();
    cout << endl <<"after dequeuing twice:"<<endl;
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
}


