#pragma once

#include <stddef.h>

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

struct intrusive_node {
    struct intrusive_node *next;
    struct intrusive_node *prev;
};

struct intrusive_list {
    struct intrusive_node head;
};


void init_list(struct intrusive_list * head);
struct intrusive_list * add_node(struct intrusive_list *head, struct intrusive_node *add);
struct intrusive_list * remove_node(struct intrusive_list *head, struct intrusive_node *add);
int get_length(struct intrusive_list *head);
