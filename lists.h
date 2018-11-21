#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class List{
private:
    struct node{
        int value;
        struct node *next;
        struct node *previous;
    };

public:
    List();
    void add_element(struct node *head ,struct node *tail ,int new_element_value);
    void delete_element_at_position(struct node *head, struct node *tail, int position);
    void delete_elements(struct node *head, struct node *tail, int element_value);
    void print_list(struct node *head, struct node *tail);

};

#endif // LISTS_H_INCLUDED
