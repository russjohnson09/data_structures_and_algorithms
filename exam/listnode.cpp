#include <stdio.h>

struct ListNode{int element; ListNode * rest;
ListNode(int e, ListNode* r):element(e),rest(r){}
};

ListNode* gen(int n) {
    if(n<1)
        return 0;
    else
        return new ListNode(n,gen(n-1));
}

int main() {

    ListNode* head = gen(5);

    while (head != 0) {
        printf("%d --> ",head->element);
        head = head->rest;
    }
    printf("#\n");

}
