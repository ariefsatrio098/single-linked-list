/*TODO: 1. Insertion (Insert First, Last, Before/after)
        2. Deletion (Deletetion First, Last, After)
        3. Searching (Sequential)*/

#include <iostream>

using namespace std;

struct node{
    int info;
    node* next;

    node(int value, node* pos = 0)
    : info(value), next(pos){};
};

//deklarasi node awalan ssl;
node* first = new node(5);

//insert first
node* insertf(int value){
    node* n = new node(value);
    n->next = first;
    first = n;
    return n;
}

//insert last
node* insertl(int value){
    node* p = first;
    node* n = new node(value);
    while(p->next != NULL){
        p = p->next;
    }
    n->next = NULL;
    p->next = n;
    return p;
}

//insert before
node* insertbf(int value , node* pos){
    if (first != pos){
        node* temp;
        node* p = first;
        
        while(p != pos){
            temp = p;
            p = p->next;
        }
        
        node* n = new node(value);
        n->next = temp->next;
        temp->next = n;

        return n;
    } else {
        node* n = new node(value);
        n->next = first;
        first = n;
        return n; 
    }
}

//insert before
node* insertaf(int value, node* pos){
    node* temp;
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    
    node* n = new node(value);
    n->next = p->next;
    p->next = n;

    return n;
}

//delete first
void delf(){
    node* del = first;
    first = first->next;
    delete del;
}

//delete last
void dell(){
    node* p = first;
    while (p->next->next != NULL){
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}

//delete after
node* delaf(node* pos){
    node* temp;
    node* p = first;
    
    while(p != pos){
        p = p->next;
    }
    pos->next = p->next->next;
    delete p->next;
    return pos;
}

//search sequential
int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}

//print data
void print(node* pos){
    while(pos != NULL){
        cout << pos->info << " ";
        pos = pos->next;
    } cout << endl;
}

int main(){
    print(first);//print
    insertf(10);//insertion first
    print(first);
    insertl(2);//insertion last
    print(first);
    insertbf(25 , first->next->next);//insertion before
    print(first);
    insertaf(60 , first->next);//insertion after
    print(first);
    delf();//deletion first
    print(first);
    dell();//deletion last
    print(first);
    delaf(first);//deletion after
    print(first);
    int key = 25;//key search
    cout << "data "<< key <<" ditemukan di urutan ke-" << search(key);//search

    return 0;
}