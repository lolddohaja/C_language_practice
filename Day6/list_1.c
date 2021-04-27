#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#define LIST_LEN 5

struct List
{
    int list_len;
    int next_idx;
    int *list;
};


int is_empty(struct List list_v1)
{
    return list_v1.next_idx ==0;
}

int is_full(struct List list_v1)
{
    return list_v1.next_idx == list_v1.list_len;
}

int* create_list(struct List list_v1)
{
    int*list = (int*)malloc(list_v1.list_len* sizeof(int));
}

void free_list(int **list)
{
    free(*list);
    *list = NULL;
}

int main()
{
   
    struct List list1 = {20, 0};

    list1.list = create_list(list1);
    for (int i = 0; i < 20; i++)
    {
        *(list1.list+i) = i;
        printf("%d\n",*(list1.list+i));
    }

    free_list(&list1.list);
    
    //free_list(list1);
    //free_list(list2);


    printf("text done\n");

    return 0;
}

