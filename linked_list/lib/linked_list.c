#include "linked_list.h"
#include <stdlib.h>

int_node *get_linked_list(int value) {
    int_node *list = malloc(sizeof(int_node));
    if (list != NULL) {
        list->next = NULL;
        list->value = value;
    }

    return list;
}

void free_linked_list(int_node *node_start) {
    int_node *next_node;
    while (node_start->next != NULL) {
        next_node = node_start->next;
        free(node_start);
        node_start = next_node;
    }
    free(node_start);
    return;
}

int get_length(int_node *node) {
    int length = 0;

    if (node == NULL) {
        length = -1;
    } else {
        length++;
        while (node->next != NULL) {
            length++;
            node = node->next;
        }
    }

    return length;
}

int get(int_node *node, int index, int *value) {
    int status = 1;
    int current_idx = 0;

    if (node != NULL) {
        // We can return the value instantly
        if (index == 0) {
            *value = node->value;
            status = 0;
        } else {
            while (node->next != NULL) {
                node = node->next;
                current_idx++;

                if (current_idx == index) {
                    *value = node->value;
                    status = 0;
                    break;
                }
            }
        }
    }

    return status;
}

int prepend(int_node **node_start, int value) {
    int status = 0;
    if (*node_start == NULL) {
        status = 1;
    } else {
        int_node *new_node = malloc(sizeof(int_node));
        if (new_node == NULL) {
            status = 1;
        } else {
            new_node->value = value;
            new_node->next = *node_start;
            *node_start = new_node;
        }
    }

    return status;
}

int append(int_node *node, int value) {
    int status = 1;
    if (node != NULL) {
        while (node->next != NULL) {
            node = node->next;
        }

        int_node *new_node = malloc(sizeof(int_node));
        if (new_node != NULL) {
            new_node->next = NULL;
            new_node->value = value;

            node->next = new_node;

            status = 0;
        }
    }

    return status;
}

int insert_at(int_node **list_start, int value, int index) {
    int_node *node = *list_start;

    int status = 1;
    int pos = 0;

    if ((list_start != NULL) && (node != NULL)) {
        if (0 == index) {
            status = prepend(list_start, value);
        } else {
            while ((node->next != NULL) && (status == 1)) {
                pos++;
                if (pos == index) {
                    int_node *new_node = malloc(sizeof(int_node));
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

int remove_value(int_node **list_start, const int value) {
    int removal_count = 0;
    int_node *node = *list_start;
    int_node *next_node;

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

int remove_at(int_node **list_start, const int index, int *value) {
    int status = 1;
    int pos = 0;
    int_node *node = *list_start;
    int_node *next_node;

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
