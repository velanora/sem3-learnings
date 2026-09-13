#include<iostream>
using namespace std;

class Node{
    public:
    Node *next;
    Node * prev;
    int data;

    Node(int val): prev(nullptr), next(nullptr), data(val){};

};

class DoublyLinkedList{
    private:
    Node * head;
    int len;
    public:
   
    DoublyLinkedList(int val){
        Node* n = new Node(val);
        head = n;
        len= 1;
    }
    bool isEmpty(){  return (len==0); }

    void insert(int pos, int val){
        if(isEmpty()) return;
        if(pos<1 || pos>len+1) return ;
        Node *newNode = new Node(val);

        if(pos ==1 ){
            if(head){
                head->prev = newNode;
            }
            newNode->next = head;
            head = newNode;
        }
        else{

        }
    }
};
