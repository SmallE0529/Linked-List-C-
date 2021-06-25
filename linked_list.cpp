#include "linked_list.h"

using namespace std;

void linked_list::push_front(int _data)
{
    node *temp = new node(_data);
    temp->next = _head;
    _head = temp;
}

void linked_list::push_back(int _data)
{
    node *temp = new node(_data);

    if(is_empty())
    {
        _head = temp;
        return;
    }

    node *current = _head;
    while(current->next != nullptr)
    {
        current = current->next;
    }
    current->next = temp;
}

void linked_list::insert_node(int _data, int idx)
{
    node* new_node = new node(_data);
    node* pre_node = _head;
    int cnt = 0;

    if(is_empty())
    {
        _head = new_node;
        return;
    }

    while(cnt < idx - 1 && pre_node != nullptr) 
    {
        pre_node = pre_node->next;
        cnt++;
    }

    if(pre_node == nullptr)
    {
        cout << "err insert index" << endl;
        return;
    }

    new_node->next = pre_node->next;
    pre_node->next = new_node;
}

void linked_list::delete_node(int idx)
{
    node* pre_node  = _head;
    int cnt = 0;

    if(is_empty())
    {
        return;
    }

    if(idx == 0)
    {
        _head = pre_node->next;
        delete pre_node;
    }


    while(cnt < idx - 1  && pre_node != nullptr) 
    {
        pre_node = pre_node->next;
        cnt++;
    }

    if(pre_node == nullptr)
    {
        cout << "err delete index" << endl;
        return;
    }

    node *current = pre_node->next;

    if(current == nullptr)
    {
        cout << "already null" << endl;
        return;
    }

    pre_node->next = current->next;
    delete current;
}

void linked_list::clear_list()
{
    node *current;
    while(_head != nullptr)
    {
        current = _head;
        _head = current->next;
        delete current;
    }
}

bool linked_list::is_empty()
{
    if(_head != nullptr)
    {
        return false;
    }
    return true;
}

void linked_list::print_list()
{
    if(is_empty())
    {
        cout << "list is empty" << endl;
    }

    node *current = _head;
    
    while(current != nullptr)
    {
        if(current == _head)
        {
            cout <<current->data;
        }
        else
        {
            cout << "->" << current->data;
        }
        
        current = current->next;
    }
    cout << endl;
}

void linked_list::reverse_list()
{
    if(_head == nullptr || _head->next == nullptr)
    {
        return;
    }

    node *current = _head;
    node *current_next = _head->next;
    node *temp = nullptr;

    while(current_next != nullptr)
    {
        current->next = temp;
        temp = current;
        current = current_next;
        current_next = current_next->next;
    }

    current->next = temp; // last node next need reverse.
    _head = current;

}