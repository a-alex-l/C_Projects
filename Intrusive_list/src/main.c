#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"



struct point {
    int x, y;
    struct intrusive_node node;
};

struct intrusive_list * add_point(struct intrusive_list *head, int x, int y) {
    struct point *add = (struct point*) malloc(sizeof(struct point));
    if (add == NULL) {
        printf("Bad malloc add\n");
        return head;
    }
    add->node.next = add->node.prev = NULL;
    add->x = x;
    add->y = y;
    add_node(head, (struct intrusive_node*)(&add->node));
    return head;
}

struct intrusive_list * remove_point(struct intrusive_list *head, int x, int y) { // removes all (x, y) pairs
    for (struct intrusive_node *now = head->head.next; now != &head->head; now = now->next) {
        struct point *item = container_of(now, struct point, node);
        if (item->x == x && item->y == y) {
            now = now->prev;
            remove_node(head, now->next);
            free(item);
        }
    }
    return head;
}

struct intrusive_list * show_all_points(struct intrusive_list *head) {
    for (struct intrusive_node *now = head->head.next; now != &head->head; now = now->next) {
        struct point *item = container_of(now, struct point, node);
        printf("(%d %d) ", item->x, item->y);
    }
    printf("\n");
    return head;
}

struct intrusive_list * remove_all_points(struct intrusive_list *head) {
    for (struct intrusive_node *now = head->head.next; now != &head->head; now = now->next) {
        struct point *item = container_of(now, struct point, node);
        now = now->prev;
        remove_node(head, now->next);
        free(item);
    }
    return head;
}

int main() {
    struct intrusive_list l;
    init_list(&l);
    while (1) {
        char input[25];
        int x, y;
        fgets(input, 25, stdin);
        if (sscanf(input, "add %d %d\n", &x, &y)) {
            add_point(&l, x, y);
            continue;
        }

        if (sscanf(input, "rm %d %d\n", &x, &y)) {
            remove_point(&l, x, y);
            continue;
        }
        
        if (strcmp(input, ("len\n")) == 0) {
            printf("%d\n", get_length(&l));
            continue;
        }

        if (strcmp(input, ("rma\n")) == 0) {
            remove_all_points(&l);
            continue;
        }

        if (strcmp(input, ("print\n")) == 0) {
            show_all_points(&l);
            continue;
        }

        if (strcmp(input, ("exit\n")) == 0) {
            break;
        }

        printf("Unknown command\n");
        int no_endl = 1;
        while (no_endl) {
            for (int i = 0; i < 25 && no_endl; i++) {
                if (input[i] == '\0' || input[i] == '\n') 
                    no_endl = 0;
            }
            if (no_endl)
                fgets(input, 25, stdin);
        }  
    }
    remove_all_points(&l);
    return 0;
}
