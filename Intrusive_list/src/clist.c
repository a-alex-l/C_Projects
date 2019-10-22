#include "clist.h"
#include <stdlib.h>


void init_list(struct intrusive_list * head) {
    head->head.next = head->head.prev = &head->head;
    return;
}

struct intrusive_list * add_node(struct intrusive_list *head, struct intrusive_node *add) {
    add->next = head->head.next;
    head->head.next = add;
    add->prev = &head->head;
    add->next->prev = add;
    return head;
}


struct intrusive_list * remove_node(struct intrusive_list *head, struct intrusive_node *remove) {
    remove->next->prev = remove->prev;
    remove->prev->next = remove->next;
    return head;
}


int get_length(struct intrusive_list *head) {
    int list_size = 0;
    for (struct intrusive_node *now = head->head.next; now != &head->head; now = now->next) {
        list_size++;
    }
    return list_size;
}
