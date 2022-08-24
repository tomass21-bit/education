#pragma once
#include <iostream>

struct ListNode
{
public:
    ListNode::ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr) : value(value), prev(prev), next(next) {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }
       
    

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List();
        

    virtual ~List();
    

    bool Empty();

    unsigned long Size();

    void PushFront(int value);
    

    void PushBack(int value);
    

    int PopFront();
    

    int PopBack();
    

    void Clear();
   

private:
    ListNode* extractPrev(ListNode* node);
   

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


