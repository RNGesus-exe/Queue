//
// Created by rngesus on 12/1/20.
//
#include<iostream>

class Queue{
    int front;
    int* arr;
    int size;
public:
    Queue(): arr(nullptr),size(0),front(-1){}
    Queue(int size):size(size),front(-1),arr(new int[size]){}
    bool isFull(){
        return front == (size-1);
    }
    bool isEmpty(){
        return front == -1;
    }
    void enqueue(int data){
        if(!isFull()){
            arr[++front] = data;
        }
        else {
            std::cerr<<"There is no space to enqueue!!!"<<std::endl;
        }
    }
    int dequeue(){
        int temp = INT16_MIN;
        if(!isEmpty()){
            temp = arr[0];
            for(int i=0;i<front;i++){
                arr[i] = arr[i+1];
            }
            front--;
        }
        return temp;
    }
    int peekFront(){
        return arr[0];
    }
    int peekRear(){
        return arr[front];
    }
    void display() const{
        for(int i=0;i<=front;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
    ~Queue(){
        if(arr!=nullptr){
            delete[] arr;
            size = front = 0;
        }
    }
};

template <class T>
class CircularQueue{
    T* arr;
    int front;
    int rear;
    int size;
public:
    CircularQueue():arr(nullptr),front(0),rear(0),size(0){}
    CircularQueue(int size):size(size),front(0),rear(0),arr(new T[size]){}
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return (front == ((rear+1) % (size)));
    }
    void enqueue(T data){
        if(!isFull()){
            arr[++rear%size] = data;
        }
        else{
            std::cerr<<"There is no space to enqueue!!!"<<std::endl;
        }
    }
    T* dequeue(){
        T* tmp = nullptr;
        if(!isEmpty()){
            tmp = new T;
            *tmp = arr[++front % size];
        }
        return tmp;
    }
    void display() const{
        for(int i=front+1;i<=rear;i++){
            std::cout<<arr[i%size]<<" ";
        }
        std::cout<<std::endl;
    }
    ~CircularQueue(){
        if(arr!=nullptr){
            delete[] arr;
            front = rear = size = 0;
        }
    }
    void dequeue_print(){
        int *tmp = this->dequeue();
        std::cout<<*tmp<<std::endl;
        delete tmp;
    }
};

int main(){
    int size = 5;
    CircularQueue<int> cq(size+1);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(69);
    cq.enqueue(79);
    cq.enqueue(44);
    //========= F 10 20 69 79 44(R) =====
    cq.enqueue(1);
    cq.enqueue(1);
    cq.enqueue(1);
    //========= F 10 20 69 79 44(R) =====
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    //========= 0 0 0 F 79 44(R)=====
    cq.enqueue(10);
    cq.enqueue(10);
    cq.enqueue(10);
    //========= 10 10 10(R) F 79 44====
    cq.dequeue();
    cq.dequeue();
    //========= 10 10 10(R) 0 0 F======
    cq.enqueue(5);
    cq.enqueue(10);
    //========= 10 10 10 5 10(R) F====
    cq.dequeue();
    cq.dequeue();
    //========= 0 F 10 5 10(R) 0====

    return 0;
}
