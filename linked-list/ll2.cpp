#include <iostream>
using namespace std;

class Node{
    public:
    	int data;
	    Node * next;
	    Node(int x){
		    data = x;
		    next = 0;
		    }
	    Node(int x, Node * y){
		    data = x; 
		    next = y;
		    }
    };


class linkedList{
    Node *head;
    public:
	    linkedList(){
		    head = 0;
		    }
	    void addNode(int value){
		    Node *p;
		    if(head == 0)
			    head = new Node (value, 0);
		    else{
			    p=head;
			    while(p->next !=0)
				    p=p->next;
			    p->next = new Node (value, 0);
			    }
		    }
	    void print(){
		    Node * p;
		    p = head;
		    while(p != 0){
			    cout << p->data << "\n";
			    p = p->next;
			    }
		    }
};


int main(void){
linkedList test;
test.addNode(4);
test.addNode(76);
test.addNode(12);
test.print();
return(0);
}
