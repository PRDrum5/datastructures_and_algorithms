#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static int_node_t *new_node(const int value) {
    int_node_t *node = (int_node_t *)malloc(sizeof(int_node_t));
    if (node != NULL) {
        node->next = NULL;
        node->value = value;
    }
    return node;
}

linked_list_t *new_linked_list(const int value) {
    linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
    if (list != NULL) {
        list->head = new_node(value);
        list->length = 1;
    }

    return list;
}

void free_linked_list(linked_list_t *list) {
    int_node_t *next_node;
    while (list->head != NULL) {
        next_node = list->head->next;
        free(list->head);
        list->head = next_node;
    }

    free(list->head);
    free(list);

    return;
}

int get_length(linked_list_t const *const list) {
    int len = 0;
    if (list != NULL) {
        len = list->length;
    }
    return len;
}

int append(linked_list_t *list, const int value) {
    int status = 1;

    if (list != NULL) {
        int_node_t *node = new_node(value);
        if (node != NULL) {

            if (list->head == NULL) {
                list->length = 1;
                list->head = node;
            } else {
                int_node_t *tail = list->head;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                status = 0;
                tail->next = node;
                list->length++;
            }
        }
    }

    return status;
}

int prepend(linked_list_t *list, const int value) {
    int status = 1;

    if (list != NULL) {
        int_node_t *node = new_node(value);
        if (node != NULL) {
            status = 0;

            if (list->head == NULL) {
                list->length = 1;
                list->head = node;
            } else {
                node->next = list->head;
                list->head = node;
                list->length++;
            }
        }
    }

    return status;
}

int get(linked_list_t *list, const int index, int *value) {
    int number_of_returned_items = 0;
    int search_depth = 0;

    if ((list != NULL) && (list->head != NULL)) {
        if (index < list->length) {
            int_node_t *node = list->head;
            while (search_depth != index) {
                node = node->next;
                search_depth++;
            }

            *value = node->value;
            number_of_returned_items++;
        }
    }
    return number_of_returned_items;
}

/*
int insert_at(int_node_t **list_start, int value, int index) {
    int_node_t *node = *list_start;

    int status = 1;
    int pos = 0;

    if ((list_start != NULL) && (node != NULL)) {
        if (0 == index) {
            status = prepend(list_start, value);
        } else {
            while ((node->next != NULL) && (status == 1)) {
                pos++;
                if (pos == index) {
                    int_node_t *new_node = malloc(sizeof(int_node_t));
                    if (new_node != NULL) {
                        new_node->next = node->next;
                        new_node->value = value;
                        node->next = new_node;

                        status = 0;
                    }
                }

                node = node->next;
            }
        }
    }

    return status;
}

int remove_value(int_node_t **list_start, const int value) {
    int removal_count = 0;
    int_node_t *node = *list_start;
    int_node_t *next_node;

    if (node != NULL) {
        if (node->value == value) {
            if (node->next != NULL) {
                *list_start = node->next;
            } else {
                *list_start = NULL;
            }

            removal_count++;
        } else {
            while (node->next != NULL) {
                next_node = node->next;
                if (next_node->value == value) {
                    node->next = next_node->next;
                    removal_count++;

                    free(next_node);

                    break;
                }

                node = node->next;
            }
        }
    }

    return removal_count;
}

int remove_at(int_node_t **list_start, const int index, int *value) {
    int status = 1;
    int pos = 0;
    int_node_t *node = *list_start;
    int_node_t *next_node;

    if (node != NULL) {
        if (index == 0) {
            *value = node->value;
            *list_start = node->next;
            status = 0;
        } else {
            while (node != NULL) {
                pos++;

                next_node = node->next;
                if ((pos == index) && (status == 1)) {
                    *value = next_node->value;
                    node->next = next_node->next;

                    status = 0;

                    free(next_node);
                }

                node = node->next;
            }
        }
    }

    return status;
}
    */
