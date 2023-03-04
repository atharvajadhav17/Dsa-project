#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"

typedef struct node
{
    char ch;
    struct node *characters[26];
    int level;
    int eow;

} node;

typedef node *Trie;

void init(Trie *t)
{
    *t = NULL;
    return;

    // int j;
    // (*t) = (node *)malloc(sizeof(node));
    // for (j = 0; j < 26; j++)
    // {
    //     (*t)->characters[j] = NULL;
    // }
    // (*t)->ch = 'R';
    // (*t)->eow = 0;
    // // (*t) = nn;
    // return;
}

void insert(Trie *t, char *word)
{
    int a = 2;
    // printf("%d", a);
    int j;
    int l = 1;
    node *p;

    // printf("%d", 2);
    if (*t == NULL)
    {
        p = (node *)malloc(sizeof(node));
        for (j = 0; j < 26; j++)
        {
            p->characters[j] = NULL;
        }
        p->ch = 'R';
        p->eow = 0;
        p->level = 0;
        *t = p;
    }
    else
    {
        // printf("ALL fine\n");
        p = *t;
    }
    // printf("%d", 2);
    // printf("%c", p->ch);
    // printf("%d", p->eow);
    // for (j = 0; j < 26; j++)
    // {
    //     printf("%d", p->characters[j]);
    // }

    int i = 0, index;
    // node *nn = (node *)malloc(sizeof(node));
    // for (j = 0; j < 26; j++)
    // {
    //     nn->characters[j] = NULL;
    // }
    // nn->ch = 'R';
    // nn->eow = 0;
    // p=nn;

    while (word[i] != '\0')
    {
        index = (int)word[i] - 97;
        // printf("%d", index);
        if (p->characters[index] == NULL)
        {
            p->characters[index] = (node *)malloc(sizeof(node));
            p = p->characters[index];
            p->ch = word[i];
            p->eow = 0;
            p->level = l;
            l++;
            for (j = 0; j < 26; j++)
            {
                p->characters[j] = NULL;
            }
        }
        else
        {
            p = p->characters[index];
            l++;
        }

        i++;
    }
    p->eow = 1;
    return;
}

//     p->ch = word[i];
//     p->eow = 0;
//     for (j = 0; j < 26; j++)
//     {
//         p->characters[j] = NULL;
//     }
//     if (word[i + 1] != '\0')
//     {

//         index = (int)word[i + 1] - 97;
//         p = p->characters[index];
//         // nn->characters[index] = (node *)malloc(sizeof(node));
//     }
//     else
//         p->eow = 1;
//     i++;
// }
// index = (int)word[0] - 97;
// (*t)->characters[index] = nn;
// return;

void print_trie(Trie *t, char *word, int l)
{

    // Prints the nodes of the trie
    // if (!t)
    //     return;
    static int index = 0;
    //  char *menu;
    node *p = *t;
    // int l = p->level;
    //  node *q = *t;
    if (*t == NULL)
        return;
    // printf("%s",temp);
    // temp = temp->characters[0];
    // printf("%s",temp);
    if (p->ch != 'R')
    {
        if (p->level != (l + 1))
        {
            if (p->level != l)

                printf("%c", p->ch);
        }
        else
        {
            printf("\n");
            printf("%s", word);
            printf("%c", p->ch);
        }
    }
    // printf("\n");
    //    printf("%d",index);
    for (int i = 0; i < 26; i++)
    {

        print_trie(&p->characters[i], word, l);
    }
    // printf("\n");
    return;
}

int search(Trie *t, char *word)
{
    // node *p = *t;
    // node *q;
    // int index, i = 0;
    // if (*t == NULL)
    //     return INT_MIN;
    // checking if first character is present or not
    // index = (int)word[i] - 97;
    // if (p->characters[index] == NULL)
    //     return 0;
    // else
    // {
    //     p = p->characters[index];
    // }
    // i = 1;
    // index = (int)word[i] - 97;
    // while (word[i] != '\0')
    // {

    //     if (p->characters[index] == NULL)
    //         return 0;
    //     else
    //     {
    //         // p = &p->characters[index];
    //         index = (int)word[i + 1] - 97;
    //         q = p;
    //         p = p->characters[index];
    //         i++;
    //     }
    // }
    // if (p->eow == 1)
    //     return 1;
    // else
    //     return 0;

    // for (i = 0; word[i] != '\0'; i++)
    // {
    //     index = (int)word[i] - 97;
    //     if (p->characters[index] == NULL)
    //         return 0;
    //     else
    //     {
    //         q = p;
    //         index = (int)word[i + 1] - 97;
    //         p = p->characters[index];
    //     }
    // }
    // if (q->eow == 1)
    //     return 1;
    // else
    //     return 0;

    node *p;
    p = *t;
    int j;
    if (*t == NULL)
    {
        printf("Fail\n");

        return 0;
    }

    int i = 0, index;

    while (word[i] != '\0')
    {
        index = (int)word[i] - 97;
        // printf("%d", index);
        p = p->characters[index];

        if (p != NULL)
        {
            // p = p->characters[index];
            i++;
        }
        else
            return 0;
    }
    if (p->eow == 1)
        return 1;
    else
        return 0;
}

// void display_menu(Trie *t)
// {
//     node *p, *q, *r;
//     p = *t;
//     int i = 0, cnt = 0;
//     char *menu;
//     if (*t == NULL)
//         return;
//     for (i = 0; i < 26; i++)
//     {
//         p = p->characters[i];

//         q = p;
//         while (p)
//         {
//             p = p->characters[i];
//             r = p;
//             if (p != NULL)
//             {
//                 for (i = 0; i < 26; i++)
//                 {
//                     printf("%c", r->ch);
//                     while (p->eow != 1 && p)
//                     {
//                         p = p->characters[i];
//                         printf("%c", p->ch);
//                         cnt++;
//                     }
//                 }
//             }
//         }
//     }
// }

// void display(Trie *t)
// {
//     node *p = *t;
//     if (*t == NULL)
//         return;
//     printf("%c->", p->ch);
//     printf("%d\n", p->level);
//     for (int i = 0; i < 26; i++)
//     {
//         display(&p->characters[i]);
//     }
//     return;
// }
void autocomplete(Trie *t, char *word)
{
    int a = 0;
    node *p, *q;
    p = *t;
    int j;
    if (*t == NULL)
    {
        printf("Fail\n");

        return;
    }
    int res = search(&p, word);
    if (res == 1)
        printf("%s", word);

    int i = 0, index;

    while (word[i] != '\0')
    {
        index = (int)word[i] - 97;
        // printf("%d", index);
        p = p->characters[index];

        if (p != NULL)
        {
            // p = p->characters[index];
            i++;
        }
        else
        {
            printf("No such menu found!");
            return;
        }
    }
    q = p;

    int l = q->level;
    // printf("%d", l);
    print_trie(&q, word, l);
    // for (i = 0; i < 26; i++)
    // {
    //     p = q;
    //     a = 0;
    //     p = p->characters[i];
    //     r=p;
    //     // if (p->eow == 1)
    //     //     printf("%s\n", word);
    //     // else
    //     // {
    //     while (p->eow != 1)
    //     {

    //         if (p != NULL)
    //         {
    //             for (j = 0; j < 26; j++)
    //             {
    //                 p=p->characters[j];
    //                 a = 1;
    //                 printf("%s", word);
    //                 printf("%c", p->ch);
    //             }
    //         }

    //         else
    //             break;

    //         // }

    //         if (a == 1)
    //             printf("\n");
    //     }
    //     return;
    // }
    return;
}

// void insert_restaurants(Trie t2)
// {
//     // init(&t2);
//     FILE *fp = fopen("restaurants.txt", "r");
//     char word[255];
//     while (fscanf(fp, "%s", word) != -1)
//     {
//         insert(&t2, word);
//     }
//     fclose(fp);
//     return;
// }

int main()
{
    Trie t1, restaurant;
    int i = 0;
    // char ch;
    init(&t1);
    init(&restaurant);

    char *str;
    // scanf("%s", str);

    // insert(&t1, "apple");
    insert(&t1, "masala dosa");
    insert(&t1, "mysore dosa");
    insert(&t1, "coffee");
    insert(&t1, "uttappa");
    insert(&t1, "pasta");
    insert(&t1, "vaishali");
    // display_menu(&t1);

    // printf("%c", t1->ch);
    // printf("%c", &t1->characters[0]->ch);
    // print_trie(&t1);
    //   printf("%c",t1->characters[0]->ch);
    int s = search(&t1, "vaishali");
    printf("search:%d\n", s);
    autocomplete(&t1, "m");

    FILE *fp = fopen("restaurants.txt", "r");
    char word[255];
    while (fscanf(fp, "%s", word) != -1)
    {
        insert(&restaurant, word);
    }
    fclose(fp);
    // Trie restaurants;
    // insert(&restaurant, "vaishali");
   // insert_restaurants(restaurant);
    int a = search(&restaurant, "vaishali");
    printf("%d", a);
    autocomplete(&restaurant, "g");


    // insert_restaurants(restaurants);
    // autocomplete(&restaurants, "Vai");
    // display(&t1);
    // int a = (int)ch;
    // printf("%d", a);
    return 0;
}