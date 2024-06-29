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

int insert_at(linked_list_t *list, const int value, const int index) {
    int status = 1;
    int pos = 0;

    if ((list != NULL) && (list->head != NULL) && (index <= list->length)) {
        if (0 == index) {
            status = prepend(list, value);
        } else if (list->length == index) {
            status = append(list, value);
        } else {
            int_node_t *node = list->head;
            int_node_t *insert_node = new_node(value);

            if (insert_node != NULL) {
                while (node->next != NULL) {
                    pos++;
                    if (pos == index) {
                        insert_node->next = node->next;
                        node->next = insert_node;
                        list->length++;
                        status = 0;
                        break;
                    }

                    node = node->next;
                }
            }
        }
    }

    return status;
}

int remove_at(linked_list_t *list, const int index, int *value) {
    int status = 1;
    int pos = 0;

    if ((list != NULL) && (list->length > index)) {
        if (index == 0) {
            int_node_t *remove_node = list->head;

            *value = remove_node->value;
            list->head = remove_node->next;
            list->length--;

            free(remove_node);

            status = 0;
        } else {
            int_node_t *prev_node = list->head;
            int_node_t *node = prev_node->next;

            while (node != NULL) {
                pos++;

                if (pos == index) {
                    // Grab the value.
                    *value = node->value;

                    // Make the previous node point past this one.
                    prev_node->next = node->next;

                    // Free this node.
                    free(node);
                    list->length--;

                    // Mark success!
                    status = 0;

                    break;
                }

                prev_node = node;
                node = prev_node->next;
            }
        }
    }

    return status;
}

int remove_value(linked_list_t *list, const int value) {
    int removal_count = 0;
    if ((list != NULL) && (list->length > 0)) {
        // If it's the very first item...
        if (list->head->value == value) {
            int_node_t *remove_node = list->head;
            list->head = remove_node->next;
            list->length--;

            free(remove_node);
            removal_count++;
        } else {
            int_node_t *prev_node = list->head;
            int_node_t *node = prev_node->next;

            while (node != NULL) {
                if (node->value == value) {
                    prev_node->next = node->next;
                    free(node);
                    list->length--;
                    removal_count++;
                    break;
                }

                prev_node = node;
                node = prev_node->next;
            }
        }
    }

    return removal_count;
}
