#include<iostream>
using namespace std;

class arraylist{
    private:
    int *datalist;
    int *pp;
    int capacity;
    int len;

    public:
    arraylist(): datalist(NULL), capacity(0), len(0),pp(NULL){};
    arraylist(int capacity){
        this->capacity = capacity;
        this->len = 0;
        datalist = new int[this->capacity];
        pp = NULL;
    }
    ~ arraylist(){ delete[] datalist; }
    void start(){ pp = datalist;}
    void next() { pp++; }
    void back() { pp--; }
    void tail(){
        /*               method 1 O(n)
        start();
        for(int i=0;i < (len-1); i++){ next();}
        */
        pp = datalist+len-1;  // method 2 O(1)
    }

    // insert function
    void insert(int value, int pos){ // shift to right, store and update len
        if((!datalist)){
            cout<<"Empty data list"<<endl;
            return ;
        }
        if(len == capacity) return;
        if(pos<1 || pos>len+1) return;
        if (len == 0) {
           *datalist = value;
           len++;
           return;
        }
        tail();
        for (int i = len; i >= pos; i--){
            *(pp+1) = *pp;
            back();
        }
        *(pp+1) = value;
        len++;
    }

    void remove(int pos){
        start();
        if(len == 0) return ;
        if(pos<1 || pos>len) return;
        pp = datalist + pos - 1;   // remove(1) --> pp = 0 +1-1 => 0
        for (int i = pos; i < len; i++){
            *pp = *(pp+1);
            next();
        }
        len--;
    }

    // get() function
    int get(int pos){
        if(len == 0) return 0;
        if(pos<1 || pos>len) return 0;

        pp = datalist + pos -1;
        return *pp;
    }

    // clear()

    // 1st method
    void clear(){ len = 0;}

    // 2nd method 
    // while(len!=0){
    //     remove(1);
    // }

    // while(length!=0){
    //     remove(len);
    // }

    //update(.. , ..)
    void update(int val, int pos){
        if(len == 0) return;    
        if(pos<1 || pos>len) return ;

        pp=datalist + pos -1;
        *pp = val;
    }

    //len()
    int length(){ return len;}
    // find(..)
    int find(int val){
        start();
        for (int i = 0; i < len; i++){
            if(*pp == val) return i+1;
            next();
        }
        return false;
    }
    
    void removeByVal(int val){
        int pos = find(val);
        if(pos!=0) remove(pos);
    }

    void removeAllduplicates(int val){
        int pos ;
        while((pos = find(val)) != 0){
            remove(pos);
        }

    }
};
int main(){
    
    arraylist *p = new arraylist(10);

    // --- Test insert() into empty list ---
    p->insert(99, 1);
    cout << "After insert(99,1): " << p->get(1) << " | len=" << p->length() << endl;
    // expected: 99 | len=1

    // --- Test insert() at the end ---
    p->insert(50, 2);
    cout << "After insert(50,2): " << p->get(1) << " " << p->get(2)
         << " | len=" << p->length() << endl;
    // expected: 99 50 | len=2

    // --- Test insert() in the middle (forces shifting) ---
    p->insert(75, 2);
    cout << "After insert(75,2): " << p->get(1) << " " << p->get(2) << " " << p->get(3)
         << " | len=" << p->length() << endl;
    // expected: 99 75 50 | len=3

    // --- Test insert() at the front ---
    p->insert(10, 1);
    cout << "After insert(10,1): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << "| len=" << p->length() << endl;
    // expected: 10 99 75 50 | len=4

    // --- Test find() ---
    cout << "find(75): position " << p->find(75) << endl;   // expected: 3
    cout << "find(1000): position " << p->find(1000) << endl; // expected: 0 (not found)

    // --- Test update() ---
    p->update(999, 3);
    cout << "After update(999,3): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << endl;
    // expected: 10 99 999 50

    // --- Test remove() from middle ---
    p->remove(2);
    cout << "After remove(2): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << "| len=" << p->length() << endl;
    // expected: 10 999 50 | len=3

    // --- Test removeByVal() ---
    p->removeByVal(999);
    cout << "After removeByVal(999): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << "| len=" << p->length() << endl;
    // expected: 10 50 | len=2

    // --- Test removeAllduplicates() ---
    p->insert(7, 1);
    p->insert(7, 1);
    p->insert(7, 1);
    cout << "Before removeAllduplicates(7): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << endl;

    p->removeAllduplicates(7);
    cout << "After removeAllduplicates(7): ";
    for(int i=1; i<=p->length(); i++) cout << p->get(i) << " ";
    cout << "| len=" << p->length() << endl;
    // expected: 10 50 | len=2 (all three 7's removed)

    // --- Test clear() ---
    p->clear();
    cout << "After clear(): len=" << p->length() << endl;
    // expected: len=0

    // --- Test insert() after clear (back to empty-list path) ---
    p->insert(42, 1);
    cout << "After insert(42,1) post-clear: " << p->get(1) << " | len=" << p->length() << endl;
    // expected: 42 | len=1

    // --- Clean up ---
    delete p;

    return 0;
}
