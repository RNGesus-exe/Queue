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
    void display(){
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



int main(){

    Queue q(10);
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(15);
    q.enqueue(12);
    q.display();
    q.dequeue();
    q.display();
    std::cout<<q.peekFront()<<
    q.peekRear()<<std::endl;
    return 0;
}
