//
// Created by michael on 2/25/2018.
//

#ifndef GROUP_PROGRAMMING_02_LINKEDLIST_H
#define GROUP_PROGRAMMING_02_LINKEDLIST_H

struct ListNode{
    ListNode* next;
    ListNode* prev;
    long data;
};

class LinkedList{
private:
    ListNode* head;
    ListNode* tail;
public:
    LinkedList();
    ~LinkedList();
    void insertionSort();
    void addTail(long data);
    void printByLine();
    void outputToFile(char* filePath);
};
#endif //GROUP_PROGRAMMING_02_LINKEDLIST_H
