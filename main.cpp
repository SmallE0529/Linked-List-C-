#include <iostream>
#include <vector>
#include <string>
#include "linked_list.h"

using namespace std;

int main()
{
    linked_list list;
    list.print_list();

    cout << "push 0 ~ 9 to list" <<endl;
    for(int i = 0 ; i< 10 ; i++)
    {
        list.push_back(i);
    }
    list.print_list();

    cout << "insert 99 to index 3" <<endl;
    list.insert_node(99, 3);
    list.print_list();

    cout << "delete index 3 node" <<endl;
    list.delete_node(3);
    list.print_list();

    cout << "push 99 to head index 0 node" <<endl;
    list.push_front(99);
    list.print_list();

    cout << "delete index 0 node" <<endl;
    list.delete_node(0);
    list.print_list();

    cout << "reverse list" <<endl;
    list.reverse_list();
    list.print_list();

    return 0;
}