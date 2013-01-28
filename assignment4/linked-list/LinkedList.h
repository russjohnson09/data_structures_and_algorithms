//LinkedList.h
class LinkedList{
    Node *head;
    int numberOfItems;
    public:
	    LinkedList():head(0),numberOfItems(0){}
	    void insert(int);
        bool remove(int);
        int getNumberOfItems() const {return numberOfItems;}
        Node* getHead() const {return head;}
};
