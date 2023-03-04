#include <stdio.h>
#include <stdlib.h>
#include"DLL.h"
// typedef struct hash_node
// {
//     int key;
//     struct hash_node *next;
// } hash_node;

// typedef hash_node *hash;

// typedef struct table
// {
//     int size;
//     hash *array;
// } table;

// table *init_table(int s)
// { // s is size
//     table *t = (table *)malloc(sizeof(table));
//     t->size = s;
//     t->array = (hash_node **)malloc(sizeof(hash_node *) * s);
//     int i;
//     for (i = 0; i < s; i++)
//         t->array[i] = NULL;
//     return t;
// }

// // int hashCode(table *t, int key)
// // {
// //     if (key < 0)
// //         return -(key % t->size);
// //     return key % t->size;
// // }

// void insert(table *t, int key, int val)
// {

//     int pos = hashCode(t, key);
//     hash_node *ptr = t->array[pos];
//     hash_node *nn = (hash_node *)malloc(sizeof(hash_node));
//     hash_node *p = ptr;
//     if (t->array[0]==NULL || t->array[1] == NULL)
//     {

//         nn->key = key;
//         nn->next = ptr;
//         if (t->array[0] == NULL)
//             t->array[0] = nn;
//         else if (t->array[1] == NULL)
//             t->array[0] = nn;
//     }
//     else{
//         t->array[2]=nn;
//     }
//     return;
// }
// int lookup(table *t, int key)
// {
//     int pos = hashCode(t, key);
//     hash_node *ptr = t->array[pos];
//     hash_node *temp = ptr;
//     while (temp)
//     {
//         if (temp->key == key)
//         {
//             return temp->val;
//         }
//         temp = temp->next;
//     }
//     return -1;
// }
// int main()
// {
//     table *t = init_table(3);
//     insert(t, 2, 2);
//     insert(t, 0, 0);
//     insert(t, 1, 1);
//     printf("%d", lookup(t, 0));
//     printf("%d", lookup(t, 1));
//     printf("%d", lookup(t, 2));
//     return 0;
// }



hash* init_hash(int s)
{
    hash* h = (hash*)malloc(sizeof(hash));
    h->size = s;
    h->array = (QNode**)malloc(h->size * sizeof(QNode*));
    int i;
    for (i = 0; i < h->size; ++i)
        h->array[i] = NULL;
  
    return h;
}

