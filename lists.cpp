#include "lists.h"

List::List(){
    struct node *head = malloc(sizeof(struct node));
    struct node *tail = malloc(sizeof(struct node));

    head->previous = NULL;
    head->next = tail;
    head->value = 0;
    tail->previous = head;
    tail->next = NULL;
}

void List::add_element(struct node *head ,struct node *tail ,int new_element_value){
    struct node *new_element;
    struct node *last_element;
    new_element = malloc(sizeof(struct node));
    new_element->value = new_element_value;
    last_element = tail->previous;

    new_element->next = tail;
    new_element->previous = last_element;
    tail->previous = new_element;
    last_element->next = new_element;
    head->value++;
}

void List::void delete_element_at_position(struct g_node *head, struct g_node *tail, int position){
    int no_elements;
    int current_positon;
    struct node *iterator;
    struct node *previous_element;
    struct node *next_element;
    struct node *poped_element;

    no_elements = head->value;
    assert(position >= 0);
    assert(position < no_elements);

    if (position <= no_elements/2){
        current_positon = 0;
        iterator = head;
        while (current_positon < position){
            iterator = iterator->next;
            current_positon++;
        }
        previous_element = iterator;
        poped_element = iterator->next;
        next_element = iterator->next->next;
    }else{
        current_positon = no_elements-1;
        iterator = tail;
        while (current_positon > position){
            iterator = iterator->previous;
            current_positon--;
        }
        previous_element = iterator->previous->previous;
        poped_element = iterator->previous;
        next_element = iterator;
    }

    previous_element->next = next_element;
    next_element->previous = previous_element;
    free(poped_element);
    head->value--;
}

void List::delete_elements(struct node *head, struct node *tail, int element_value){
    struct node *iterator = head;
    struct g_node *previous_element;
    struct g_node *next_element;
    struct g_node *poped_element;

    while (iterator->next != tail) {
        if(iterator->next->value < element_value){
            previous_element = iterator;
            poped_element = iterator->next;
            next_element = iterator->next->next;

            previous_element->next = next_element;
            next_element->previous = previous_element;
            free(poped_element);
            head->value--;
        }
        iterator = iterator->next;
    }
}

void List::print_list(struct node *head, struct node *tail){
    struct g_node *iterator = head;

    printf("\n List: ");
    while (iterator->next != tail) {
        printf("%d ", iterator->next->value);
        iterator = iterator->next;
    }

