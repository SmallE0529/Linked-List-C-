#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

class linked_list;

class node
{   
    public:
        int data;
        node *next;

        node()
        {
            data = 0;
            next = nullptr;
        };

        node(int _data)
        {
            data = _data;
            next = nullptr;
        };

        node(int _data, node *_next)
        {
            data = _data;
            next = _next;
        };

        friend class linked_list;
};

class linked_list
{
    public:
        node *_head;
        int _size;
        linked_list()
        {
            _head = nullptr;
            _size = 0;
        };

        void push_front(int _data);
        void push_back(int _data);
        void insert_node(int _data, int idx);
        void delete_node(int idx);
        void reverse_list();
        void clear_list();

        bool is_empty();     
        void print_list();
};

#endif