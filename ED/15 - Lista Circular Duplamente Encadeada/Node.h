#ifndef NODE_H
#define NODE_H

struct Node{
    int value;
    Node *prev;
    Node *next;

    Node(const int& val, Node *prevPtr, Node *nextPtr){
        value = val;
        prev = prevPtr;
        next = nextPtr;
    }
};


#endif /* A6BFA923_02BB_4F7B_91A7_2B08E3035EDE */
