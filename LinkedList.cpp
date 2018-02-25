#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Constructor using sentry nodes
 */
LinkedList::LinkedList() {
    //set up sentry node for tail and head
    this->tail = new ListNode;
    this->tail->data = 0;
    this->head = new ListNode;
    this->head->data = 0;
    head->next = tail;
    tail->prev = head;
}
/**
 * Deconstructor
 */
LinkedList::~LinkedList() {
    ListNode* traveler = head;
    while (traveler != tail){
        ListNode* temp = traveler;
        traveler = traveler->next;
        delete temp;
        temp = nullptr;
    }
    traveler = nullptr;
    delete head;
    delete tail;
}

/**
 * Addes data to the tail end using sentry nodes
 * @param data
 */
void LinkedList::addTail(long data) {
    ListNode* n = new ListNode;
    n->data = data;
    //h<->t : h<->n<->t
    tail->prev->next = n;
    n->prev = tail->prev;
    tail->prev = n;
    n->next = tail;
}
/**
 * Prints the linked list on the same line
 */
void LinkedList::printByLine() {
    ListNode* traveler = head->next;

    cout << "List: ";
    while (traveler != tail){
        cout << traveler->data << " ";
        traveler = traveler->next;
    }
    cout << endl;
    traveler = nullptr;
}
/**
 * Insertion sorts the linked list I tried putting lots of comments
 * But it is easier to see if you trace the code using an example.
 *
 */
void LinkedList::insertionSort() {
    //empty list or list with one item
    if(head->next == tail || head->next->next == tail)
        return;

    //at this point we have a list with at least 2 elements (4 if you include the sentry nodes)
    //start at second real node, assume left is already sorted
    ListNode* t1 = head->next->next;
    while (t1 != tail)
    {
        //pick up current node and travel backwards until it is less then the previous node
        if(t1->data < t1->prev->data)
        {
            ListNode* n = t1;
            ListNode* t2 = t1;
            //find place where n should be inserted before
            while(n->data < t2->prev->data){
                t2 = t2->prev;
            }
            ListNode* insertPrev = t2->prev;

            //update insertion neighbors
            t2->prev->next = n;
            t2->prev = n;
            //now update the spot that it was moved from
            t1->prev->next = t1->next;
            t1->next->prev = t1->prev;
            //now update t1 to point to next element to examine
            t1 = t1->next;
            //now update n
            n->prev = insertPrev;
            n->next = t2;
            insertPrev = nullptr;
            n = nullptr;
            t2 = nullptr;
            continue;
        }

        t1 = t1->next;
    }
    t1 = nullptr;
}
/**
 * Writes each element on a seperate line
 * starting at head (ignores sentry nodes)
 * @param filePath
 */
void LinkedList::outputToFile(char *filePath) {
    ofstream outputFile(filePath);
    ListNode* traveler = head->next;

    if(!outputFile.is_open()){
        cout << "unable to open output file" << endl;
        return;
    }
    while(traveler != tail){
        outputFile << traveler->data << endl;
        traveler = traveler->next;
    }
    outputFile.close();
    traveler = nullptr;
}