#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    int len;
    Node *head;

public:
    LinkedList() : len(0), head(nullptr) {}
    LinkedList(int val)
    {
        Node *newNode = new Node(val);
        head = newNode;
        len = 1;
    }
    ~LinkedList()
    {
        while (head)
        {
            Node *curr = head; //
            head = head->next; // moves head to next node
            delete curr;
        }
    }
    bool isEmpty() const { return (len == 0); }

    void insert(int pos, int val)
    {
        if (pos < 1 || pos > len + 1)
            return;

        Node *newNode = new Node(val);
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        len++;
    }

    void remove(int pos)
    {
        if (isEmpty()) return;
        if (pos < 1 || pos > len) return;
        Node *curr = head;
        if (pos == 1){ // removal from start ---> moves the head to second node
            head = head->next;
            delete curr;
        }
        else{// removal from middle or end
            for (int i = 1; i < (pos - 1); i++)
                curr = curr->next;
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        len--;
    }

    int get(int pos){
        if (pos < 1 || pos > len) throw out_of_range("invalid position");
        Node *curr = head;
        for(int i=1; i<pos; i++)
            curr = curr->next;
        return curr->data;
    }

    void update(int pos, int val){
        if (pos < 1 || pos > len) throw out_of_range("invalid position");
        Node *curr = head;
        for(int i=1; i<pos; i++)
            curr = curr->next;
        curr->data = val;
    }

    int find(int val){
        Node *curr = head;
        for(int i=1; i<len; i++){
            if(curr->data == val) return i;
            curr = curr->next;
        }
        return 0;
    }

    void removeByval(int val){
        int pos= find(val);
        if(pos!=0) remove(pos);
    }
    void removeAllDuplicates(int val){
        int pos;
        while(pos = find(val) != 0){
            remove(pos);
        }
    }

    void changePos(int from , int to){
        if(isEmpty()) return ;
        if (from < 1 || from > len || to < 1 || to > len ) 
        throw out_of_range("invalid position");
        Node *curr = head;
        Node *changeN = curr;

        if(from ==1){
            head = head->next;
        }
        else{
            for(int i=1; i<(from-1);i++){ curr = curr->next;}
            changeN = curr->next;
            curr->next = changeN -> next;
        }

        if(to == 1){
            changeN->next = head;
            head = changeN;
        }
        else{
            curr = head;
            for (int i = 1; i< (to-1) ; i++){curr =curr->next;}
            changeN->next = curr->next;
            curr->next = changeN;
        }
    }

    void swap(int id1, int id2){
        Node *curr1, *curr2 = head;
        for (int i = 1; i < (id1-1); i++){ curr1 = curr1->next; }

        for (int i = 1; i < (id2-1); i++){ curr2 = curr2->next; }

        Node*swap1= curr1->next;
        Node*swap2 =curr2->next;
        curr1->next = swap2;
        curr2->next = swap1;
        Node *temp = swap2->next;
        swap2->next = swap1->next;
        swap1->next = temp;
        
    }

    void print(){
        Node *curr = head;
        for(int i=1;i<=len; i++){
            cout<<curr->data<<"--->";
            curr = curr->next;
        }
        cout<<"null"<<"\n";

    }
};

int main()
{
    LinkedList list;

    // Build [10, 20, 30] via insert
    list.insert(1, 10);   // [10]
    list.insert(2, 20);   // [10, 20]
    list.insert(3, 30);   // [10, 20, 30]
    list.insert(1, 5);    // [5, 10, 20, 30]  (insert at front)
    list.insert(3, 15);   // [5, 10, 15, 20, 30]  (insert in middle)

    cout << "get(1): " << list.get(1) << endl;  // expect 5
    cout << "get(3): " << list.get(3) << endl;  // expect 15
    cout << "get(5): " << list.get(5) << endl;  // expect 30

    list.update(3, 99);
    cout << "after update(3, 99), get(3): " << list.get(3) << endl; // expect 99

    cout << "find(99): " << list.find(99) << endl;   // expect 3
    cout << "find(1000): " << list.find(1000) << endl; // expect 0 (not found)

    list.remove(1);   // remove front -> [10, 20, 99(was 15), 30] wait, values: [10, 20, 99, 30]
    cout << "get(1) after remove(1): " << list.get(1) << endl; // expect 10

    list.remove(4);   // remove last remaining element in current list, check no crash
    cout << "isEmpty after removes: " << list.isEmpty() << endl;

    list.print();

    list.insert(1, 10);   // [10]
    list.insert(2, 20);   // [10, 20]
    list.insert(3, 30);   // [10, 20, 30]
    list.insert(1, 5);    // [5, 10, 20, 30]  (insert at front)
    list.insert(3, 15);


    list.print();
     list.changePos(5,1);
     list.print();
     list.swap(5,1);
     list.print();

    // // Test removeByval / removeAllDuplicates with actual duplicates
    // LinkedList dupList;
    // dupList.insert(1, 7);
    // dupList.insert(2, 3);
    // dupList.insert(3, 7);
    // dupList.insert(4, 3);
    // dupList.insert(5, 7);
    // // dupList: [7, 3, 7, 3, 7]

    // dupList.removeAllDuplicates(7);
    // cout << "find(7) after removeAllDuplicates(7): " << dupList.find(7) << endl; // expect 0
    // cout << "find(3) still present: " << dupList.find(3) << endl; // expect nonzero

    return 0;
}




