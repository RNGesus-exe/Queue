//
// Created by rngesus on 12/1/20.
//
#include<iostream>
#include<array>

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

template<class T>
class DEQueue{
    class Node{
    public:
        Node* prev;
        T data;
        Node* next;
    }*front,*rear;
public:
    DEQueue(): front(nullptr),rear(nullptr){}
    DEQueue(T data){
        this->enqueueFront(data);
    }
    void enqueueFront(T data){
        Node *temp = new Node;
        if(!this->front){
            this->rear = this->front = temp;
            this->rear->next = this->front;
            this->front->prev = this->rear;
        }
        else{
              temp->next = this->front;
              this->front->prev = temp;
              this->rear->next = temp;
              temp->prev = this->rear;
              this->front = temp;
        }
        temp = nullptr;
        this->front->data = data;
    }
    void enqueueRear(T data){
        if(!this->front){
            this->enqueueFront(data);
        }
        else{
            Node* temp = new Node;
            temp->prev = this->rear;
            this->rear->next = temp;
            this->rear = temp;
            temp = nullptr;
            this->rear->next = this->front;
            this->front->prev = this->rear;
            this->rear->data = data;
        }
    }
    T dequeueFront(){
        T temp = INT16_MIN;
        if(this->front) {
            temp = this->front->data;
            if (this->front == this->rear) {
                delete this->front;
                this->front = this->rear = nullptr;
            } else {
                this->front = this->front->next;
                delete this->front->prev;
                this->front->prev = this->rear;
                this->rear->next = this->front;
            }
        }
        return temp;
    }
    T dequeueRear(){
        T temp = INT16_MIN;
        if(this->rear) {
            temp = this->rear->data;
            if (this->front == this->rear) {
                delete this->front;
                this->front = this->rear = nullptr;
            } else {
                this->rear = this->rear->prev;
                delete this->rear->next;
                this->front->prev = this->rear;
                this->rear->next = this->front;
            }
        }
        return temp;
    }
    void stackPrint() const{
        Node *temp = this->rear;
        do{
            std::cout<< temp->data <<" ";
            temp = temp->prev;
        }while(temp!=this->rear);
        std::cout<<std::endl;
    }
    void queuePrint() const{
        Node *temp = this->front;
        do{
            std::cout<< temp->data <<" ";
            temp = temp->next;
        }while(temp!=this->front);
        std::cout<<std::endl;
    }
    ~DEQueue(){
        while(this->front){
            this->dequeueFront();
        }
    }
};


int main(){
    DEQueue<int> dq;
    dq.enqueueRear(10);
    dq.enqueueRear(4);
    dq.enqueueRear(7);
    //============================10 4 7
    dq.dequeueFront();
    //============================4 7
    dq.enqueueFront(22);
    dq.enqueueFront(44);
    //============================44 22 4 7
    dq.dequeueRear();
    //============================44 22 4
    dq.queuePrint();
    return 0;
}
