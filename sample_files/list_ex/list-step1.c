#include <stdio.h>
#include <math.h>

#define LIST_LEN 5

void print_newline();

void print_list(int list[], int len, int next_idx);
int add_to_list(int list[], int len, int idx, int val);
int delete_from_list(int list[], int len, int next_idx, int idx);
int update_list(int list[], int len, int next_idx, int idx, int val);
int insert_list(int list[], int len, int next_idx, int idx, int val);

int main()
{
    int next_idx = 0;
    int list[LIST_LEN] = {0};

    print_list(list, LIST_LEN, next_idx);
    for (int i = 0; i < 3; i++)
    {
        next_idx = add_to_list(list, LIST_LEN, next_idx, i * 10);
    }

    print_newline();
    print_list(list, LIST_LEN, next_idx);

    // next_idx = delete_from_list(list, LIST_LEN, next_idx, 3);
    // next_idx = delete_from_list(list, LIST_LEN, next_idx, 1);

    next_idx = update_list(list, LIST_LEN, next_idx, 2, 333);

    print_newline();
    print_list(list, LIST_LEN, next_idx);

    next_idx = insert_list(list, LIST_LEN, next_idx, 1, 8888);
    next_idx = insert_list(list, LIST_LEN, next_idx, 0, 1000);
    next_idx = insert_list(list, LIST_LEN, next_idx, 4, 777);
    next_idx = insert_list(list, LIST_LEN, next_idx, 4, 747);

    print_newline();
    print_list(list, LIST_LEN, next_idx);

    // next_idx = add_to_list(list, LIST_LEN, next_idx, 1234);

    // print_newline();
    // print_list(list, LIST_LEN, next_idx);

    return 0;
}

void print_newline()
{
    printf("\n");
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

int update_list(int list[], int len, int next_idx, int idx, int val)
{
    if (idx < next_idx)
    {
        list[idx] = val;
    }
    return next_idx;
}

int insert_list(int list[], int len, int next_idx, int idx, int val)
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

    for (int i = next_idx - 1; i >= idx; i--)
    {
        list[i + 1] = list[i];
    }
    list[idx] = val;

    return next_idx + 1;
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

int n_digits(int num)
{
    return num == 0 ? 1 : floor(log10(num)) + 1;
}

void print_list(int list[], int len, int next_idx)
{
    int max_n_digits = n_digits(len - 1);
    for (int i = 0; i < len; i++)
    {
        int n = n_digits(i);
        for (int j = 0; j < max_n_digits - n; j++)
        {
            printf(" ");
        }
        if (i < next_idx)
        {
            printf("%d : %d\n", i, list[i]);
        }
        else
        {
            printf("%d : -\n", i);
        }
    }
    printf("next_idx: %d\n", next_idx);
}