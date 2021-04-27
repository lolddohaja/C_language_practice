#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc/malloc.h>

#define LIST_LEN 5

typedef struct list
{
    int len;
    int next_idx;
    int *data;
} List;

void create_list(List *list, unsigned int size);
void free_list(List *list);
bool is_empty(List *list);
bool is_full(List *list);
void print_list(List *list);
void add_to_list(List *list, int val);
void delete_from_list(List *list, int idx);
void update_list(List *list, int idx, int val);
void insert_list(List *list, int idx, int val);
int get_size_list(List *list);
void claer_list(List *list);

int main()
{
    const int size1 = 20;

    List list1;
    create_list(&list1, size1);

    assert(list1.len == size1);
    assert(list1.next_idx == 0);
    assert(malloc_size(list1.data) == size1 * sizeof(int));

    free_list(&list1);
    assert(list1.len == 0);
    assert(list1.next_idx == 0);
    assert(list1.data == NULL);

    printf("test done\n");

    return 0;
}

void create_list(List *list, unsigned int size)
{
    list->len = size;
    list->next_idx = 0;
    list->data = (int *)malloc(size * sizeof(int));
}

void free_list(List *list)
{
    free(list->data);
    list->len = 0;
    list->next_idx = 0;
    list->data = NULL;
}

bool is_empty(List *list)
{
    return list->next_idx == 0;
}

bool is_full(List *list)
{
    return list->next_idx == list->len;
}

int get_size_list(List *list)
{
    return list->next_idx;
}
void claer_list(List *list)
{
    list->next_idx = 0;
}

void add_to_list(List *list, int val)
{
    if (list->next_idx > list->len - 1)
    {
        return;
    }

    list->data[list->next_idx] = val;
    list->next_idx += 1;
}

void update_list(List *list, int idx, int val)
{
    if (idx < list->next_idx)
    {
        list->data[idx] = val;
    }
}

void insert_list(List *list, int idx, int val)
{
    if (idx >= list->next_idx)
    {
        return;
    }
    if (idx == list->len - 1)
    {
        list->data[idx] = val;
        return;
    }

    for (int i = list->next_idx - 1; i >= idx; i--)
    {
        list->data[i + 1] = list->data[i];
    }
    list->data[idx] = val;

    list->next_idx += 1;
}

void delete_from_list(List *list, int idx)
{
    if (idx >= list->next_idx)
    {
        return;
    }
    for (int i = idx; i < list->next_idx - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->next_idx -= 1;
}

int n_digits(int num)
{
    return num == 0 ? 1 : floor(log10(num)) + 1;
}

void print_list(List *list)
{
    int max_n_digits = n_digits(list->len - 1);
    for (int i = 0; i < list->len; i++)
    {
        int n = n_digits(i);
        for (int j = 0; j < max_n_digits - n; j++)
        {
            printf(" ");
        }
        if (i < list->next_idx)
        {
            printf("%d : %d\n", i, list->data[i]);
        }
        else
        {
            printf("%d : -\n", i);
        }
    }
    printf("next_idx: %d\n", list->next_idx);
}