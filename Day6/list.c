#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LIST_LEN 5

void print_list(int list[], int len, int next_idx);
int add_to_list(int list[], int len, int idx, int val);
int delete_from_list(int list[], int len, int next_idx, int idx);
int update_list(int list[], int len, int next_idx, int idx, int val);
int insert_to_list(int list[], int len, int next_idx, int idx, int val);
int is_empty(int list[], int len);

int main()
{
    int next_idx = 0;
    int list[LIST_LEN] = {0};

    print_list(list, LIST_LEN, next_idx);

    for (int i = 0; i < 100; i++)
    {
        next_idx = add_to_list(list, LIST_LEN, next_idx, i * 10);
    }
    print_list(list, LIST_LEN, next_idx);
    next_idx = delete_from_list(list, LIST_LEN, next_idx, 2);
    print_list(list, LIST_LEN, next_idx);
    next_idx = update_list(list, LIST_LEN, next_idx, 2, 333);
    print_list(list, LIST_LEN, next_idx);
    next_idx = insert_to_list(list, LIST_LEN, next_idx, 2, 40);
    print_list(list, LIST_LEN, next_idx);
    next_idx = delete_from_list(list, LIST_LEN, next_idx, 2);
    print_list(list, LIST_LEN, next_idx);
    next_idx = insert_to_list(list, LIST_LEN, next_idx, 2, 45);
    print_list(list, LIST_LEN, next_idx);

    return 0;
}

int n_digits(int num)
{
    return num == 0 ? 1 : floor(log10(num)) + 1;
}

void print_list(int list[], int len, int next_idx)
{
    int max_n_digits = n_digits(len - 1);
    for (int i = 0; i < len; i++)
    {
        int n = n_digits(1);
        for (int j = 0; j < max_n_digits - n; j++)
        {
            printf(" ");
        }
        printf("%d : %d\n", i, list[i]);
    }
    printf("next_idx: %d\n", next_idx);
}

int add_to_list(int list[], int len, int idx, int val)
{
    if (idx > len - 1)
    {
        return idx;
    }
    list[idx] = val;
    return idx + 1;
}

int delete_from_list(int list[], int len, int next_idx, int idx)
{
    if (idx >= next_idx)
    {
        return next_idx;
    }
    for (int i = idx; i < next_idx - 1; i++)
    {
        list[i] = list[i + 1];
    }
    return next_idx - 1;
}

int update_list(int list[], int len, int next_idx, int idx, int val)
{
    if (idx < next_idx)
    {
        list[idx] = val;
    }
    return next_idx;
}

int insert_to_list(int list[], int len, int next_idx, int idx, int val)
{
    if (idx >= next_idx)
    {
        return next_idx;
    }
    if (idx == len - 1)
    {
        list[idx] = val;
        return next_idx;
    }
    for (int i = next_idx; i >= idx; i--)
    {
        list[i + 1] = list[i];
    }
    list[idx] = val;
    return next_idx + 1;
}

int is_empty(int list[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (list[i] = !0)
        {
            return 0;
        }
        else
            ;
        {
            return 1;
        }
    }
}

int is_full(int list[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (list[i] = !0)
        {
            return 1;
        }
        else
            ;
        {
            return 0;
        }
    }
}