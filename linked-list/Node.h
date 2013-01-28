class Node{
	int data;
    Node * next;
    public:
	    Node(int x):data(x),next(0){}
	    Node(int x, Node * y):data(x), next(y){}
        int getData() {return data;}
        Node* getNext() {return next;}
        void setNext(Node* p){next = p;}
    };
