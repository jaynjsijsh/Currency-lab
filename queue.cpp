/*
* Lab 3
* Harmony Trinh and Jayne Tan
* The purpose of this lab is to implement and demonstrate link-based ADTs to store Currency objects and perform different operations on these data structures
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include "stack.cpp"
//using namespace std;
class Queue : private SinglyLinkedList{
    public:
    Queue(){

    }

    //Pre:
    //Post: nodes of queue are cleared and deallocated through a linkedlist
    //Return:
    void createQueue(){
        createList();
    }

    //Pre: Pointer to currency object to be added
    //Post: New node is added to the of currency object is added to the end of the queue
    //Return: 
    void enqueue(Currency* curr){
        addCurrency(curr, countCurrency());
    }

    //Pre: 
    //Post: Currency object is removed from front of the queue
    //Return: currency object stored at start of queue
    Currency* dequeue(){
        Currency* val = getCurrency(0);
        removeCurrencyAtIndex(0);
        return val;
    }

    //Pre: 
    //Post: Currency object retrieved from start of queue
    //Return: Currency object at start of queue
    Currency* peekFront(){
        return getCurrency(0);
    }

    //Pre:
    //Post: Currency object retrieved from end of queue
    //Return: Currency object stored at end of queue
    Currency* peekRear(){
        return getCurrency(countCurrency() - 1);
    }

    //Pre:
    //Post: queue is printed
    //Return: queue which is printed as a string;
    std::string printQueue(){
        return printList();
    }

    ~Queue(){}
};