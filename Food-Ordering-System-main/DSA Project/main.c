#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "Trie.h"
#include "queue.h"
#include "main.h"

int m1 = 0, m2 = 0;
int main()
{

    // printf("Welcome to FoodieBay");
    // printf("1.Login\n2.Signup\n");
    // int a;
    // char un[255];
    // char p[255];
    // char n[255];
    // char address[255];
    // char mobileno[10];
    // scanf("%d", &a);
    // FILE *fp;
    // if (a == 1)
    // {

    //     scanf("%s", un);
    //     scanf("%s", p);

    //     // fp = fopen("Login.txt", "a");
    //     //  fprintf(fp,"%s ",n);
    //     //  fprintf(fp,"%s\n",p);
    //     //  int len = sizeof(p) / sizeof(p[0]);
    //     //  if (len < 8)
    //     //      printf("Password must be at least 8 characters");
    //     //  else
    //     login(n, p);
    // }
    // else if (a == 2)
    // {
    //     int i = 1;
    //     char word[255];
    //     printf("Enter your name:\n");
    //     scanf("%s", n);
    //     printf("Enter your address:\n");
    //     scanf("%s", address);
    //     printf("Enter your mobile no:\n");
    //     scanf("%s", mobileno);

    //     while (i > 0)
    //     {
    //         printf("Enter your username:\n");
    //         scanf("%s", un);
    //         while (fscanf(fp, "%s", word) != -1)
    //         {
    //             if (!strcmp(un, word))
    //             {
    //                 printf("This username already exists!");
    //                 i = 2;
    //                 break;
    //             }
    //         }
    //         if (i != 2)
    //             i = -1;
    //     }
    //     i = 1;

    //     while (i > 0)
    //     {
    //         printf("Enter your password:\n");
    //         scanf("%s", p);
    //         int len = sizeof(p) / sizeof(p[0]);
    //         if (len < 8)
    //         {
    //             printf("Password must be at least 8 characters");
    //             i = 2;
    //         }
    //         if (i != 2)
    //             i = -1;
    //     }

    //     signup(n, address, mobileno, un, p);

    //     return 0;
    // }

    //     while (m >= 0)
    //     {

    //         printf("Welcome to FoodieBay\n");
    //         printf("1.Login\n2.Signup\n");
    //         int a, b, c;
    //         char un[255];
    //         char p[255];
    //         char n[255];
    //         char address[255];
    //         char mobileno[10];
    //         char rest[255];
    //         scanf("%d", &a);

    //         FILE *fp;
    //         if (a == 1)
    //         {
    //             printf("Enter your username:\n");
    //             scanf("%s", un);
    //             printf("Enter your password:\n");
    //             scanf("%s", p);

    //             // fp = fopen("Login.txt", "a");
    //             //  fprintf(fp,"%s ",n);
    //             //  fprintf(fp,"%s\n",p);
    //             //  int len = sizeof(p) / sizeof(p[0]);
    //             //  if (len < 8)
    //             //      printf("Password must be at least 8 characters");
    //             //  else
    //             login(un, p);
    //             if (m == 2)
    //             {
    //                 printf("Order your food now\n");
    //                 printf("1.Search by restaurants\n2.Search by dishes\n3.Exit");
    //                 scanf("%d", &b);
    //                 if (b == 1)
    //                 {
    //                     printf("1.Display list of all restaurants\n2.Search Specific restaurant");
    //                     scanf("%d", &c);
    //                     if (c == 1)
    //                     {
    //                         FILE *fp = fopen("restaurants.txt", "r");
    //                         char word[255];
    //                         while (fscanf(fp, "%s", word) != -1)
    //                         {
    //                             printf("%s\n",word);
    //                         }
    //                         fclose(fp);
    //                     }
    //                     else if(c==2){
    //                         printf("Enter the name of restaurant:\n");
    //                         scanf("%s",rest);
    //                         autocomplete()
    //                     }
    //                 }
    //             }
    //         }
    //         else if (a == 2)
    //         {
    //             fgetc(stdin);
    //             int i = 1;
    //             char word[255];
    //             printf("Enter your name:\n");
    //             // scanf("%s", n); fgets(n, 50, stdin);
    //             fgets(n, 50, stdin);
    //             printf("Enter your address:\n");
    //             // scanf("%s", address);
    //             fgets(address, 255, stdin);
    //             printf("Enter your mobile no:\n");
    //             scanf("%s", mobileno);

    //             while (i > 0)
    //             {
    //                 i = 1;
    //                 printf("Enter your username:\n");
    //                 scanf("%s", un);

    //                 fp = fopen("Login.txt", "r");
    //                 while (fscanf(fp, "%s", word) != -1)
    //                 {
    //                     if (!strcmp(un, word))
    //                     {
    //                         printf("This username already exists!\n");
    //                         i = 2;
    //                         break;
    //                     }
    //                 }
    //                 if (i != 2)
    //                     i = -1;
    //             }
    //             i = 1;

    //             while (i > 0)
    //             {
    //                 i = 1;
    //                 int j = 0, cnt = 0;
    //                 printf("Enter your password:\n");
    //                 scanf("%s", p);
    //                 while (p[j] != '\0')
    //                 {
    //                     cnt++;
    //                     j++;
    //                 }
    //                 //  int len = sizeof(p) / sizeof(p[0]);
    //                 // printf("%d",cnt);
    //                 if (cnt < 8)
    //                 {
    //                     printf("Password must be at least 8 characters:\n");
    //                     i = 2;
    //                 }
    //                 if (i != 2)
    //                     i = -1;
    //             }
    //             fclose(fp);
    //             signup(n, address, mobileno, un, p);
    //         }
    //         else if (a == 3)
    //             m = -1;
    //         else
    //             printf("Enter a valid number:\n");
    //     }
    // }
    int a, b, c, y, k, x;
    cart C;
    Queue Q1;
    char rest[255];
    Trie restaurant, vaishali;
    init(&vaishali);
    FILE *fp = fopen("vaishali.txt", "r");
    char word[255];
    while (fscanf(fp, "%s", word) != -1)
    {
        insert(&vaishali, word);
    }
    fclose(fp);
    while (m1 >= 0)
    {
        // Trie restaurant;

        init(&restaurant);
        FILE *fp = fopen("restaurants.txt", "r");
        char word[255];
        while (fscanf(fp, "%s", word) != -1)
        {
            insert(&restaurant, word);
        }
        fclose(fp);

        printf("Welcome to FoodieBay!\n");
        printf("1.Login\n2.Signup\n3.Exit");
        printf("\n");

        char un[255];
        char p[255];
        char n[255];
        char address[255];
        char mobileno[10];
        scanf("%d", &a);

        // FILE *fp;
        if (a == 1)
        {
            printf("Enter your username:\n");
            scanf("%s", un);
            printf("Enter your password:\n");
            scanf("%s", p);

            // fp = fopen("Login.txt", "a");
            //  fprintf(fp,"%s ",n);
            //  fprintf(fp,"%s\n",p);
            //  int len = sizeof(p) / sizeof(p[0]);
            //  if (len < 8)
            //      printf("Password must be at least 8 characters");
            //  else
            m2 = login(un, p);
            printf("%d", m2);
            if (m2 == 2)
                m1 = -1;
        }
        else if (a == 2)
        {
            fgetc(stdin);
            int i = 1;
            char word[255];
            printf("Enter your name:\n");
            // scanf("%s", n); fgets(n, 50, stdin);
            fgets(n, 50, stdin);
            printf("Enter your address:\n");
            // scanf("%s", address);
            fgets(address, 255, stdin);
            printf("Enter your mobile no:\n");
            scanf("%s", mobileno);

            while (i > 0)
            {
                i = 1;
                printf("Enter your username:\n");
                scanf("%s", un);

                fp = fopen("Login.txt", "r");
                while (fscanf(fp, "%s", word) != -1)
                {
                    if (!strcmp(un, word))
                    {
                        printf("This username already exists!\n");
                        i = 2;
                        break;
                    }
                }
                if (i != 2)
                    i = -1;
            }
            i = 1;

            while (i > 0)
            {
                i = 1;
                int j = 0, cnt = 0;
                printf("Enter your password:\n");
                scanf("%s", p);
                while (p[j] != '\0')
                {
                    cnt++;
                    j++;
                }
                //  int len = sizeof(p) / sizeof(p[0]);
                // printf("%d",cnt);
                if (cnt < 8)
                {
                    printf("Password must be at least 8 characters:\n");
                    i = 2;
                }
                if (i != 2)
                    i = -1;
            }
            fclose(fp);
            signup(n, address, mobileno, un, p);
        }
        else if (a == 3)
            m1 = -1;
        else
            printf("Enter a valid number:\n");
    }
    while (m2 >= 0)
    {
        if (m2 == 2)
        {
            printf("Order your food now\n");
            printf("1.Search by restaurants\n2.Search by dishes\n3.Exit");
            scanf("%d", &b);
            if (b == 1)
            {
                printf("1.Display list of all restaurants\n2.Search Specific restaurant");
                scanf("%d", &c);
                if (c == 1)
                {
                    int count = 1, c1;
                    FILE *fp = fopen("restaurants.txt", "r");
                    char word[255];
                    while (fscanf(fp, "%s", word) != -1)
                    {
                        printf("%d %s\n", count, word);
                        count++;
                    }
                    fclose(fp);
                    printf("From which restaurant would you like to order?(Press from 1-10)\n");
                    scanf("%d", &c1);
                    if (c1 == 1)
                    {
                        int menu, loop = 1, iloop = 1;
                        FILE *fp = fopen("vaishali.txt", "r");
                        char word[255];
                        count = 1;
                        while (loop >= 1)
                        {
                            printf("What would you like to order?\n");
                            // while (fscanf(fp, "%s", word) != -1)
                            // {
                            //     printf("%d %s\n", count, word);
                            //     count++;
                            // }
                            // count = 0;
                            char line[1000];
                            if (!fp)
                                return 0;
                            
                            while (fgets(line, sizeof(line), fp) != NULL)
                            {
                                fputs(line, stdout);
                                
                            }
                        
                            fclose(fp);
                            //          return 0;
                            //fclose(fp);
                            scanf("%d", &menu);
                            FILE *fptr = fopen("vaishali.txt", "r");
                            while (count != menu)
                            {
                                fscanf(fptr, "%s", word);
                                count++;
                            }
                            fclose(fptr);
                            printf("Add %s to the cart?\n1.Yes\n2.No", word);
                            scanf("%d", &y);
                            if (y == 1)
                            {
                                k = 0;
                                C.food[k] = word;
                                fscanf(fp, "%d", &menu);
                                C.price[k] = menu;
                                // cart.addr=address;
                                // init_Queue(&Q1);
                                // enQueue(&Q1,)
                                iloop = 1;
                                while (iloop >= 1)
                                {
                                    printf("Added to the cart!\nWould you like to order more?\n1.Yes\n2.No");
                                    scanf("%d", &y);
                                    if (y == 1)
                                        iloop = 0;
                                    if (y == 2)
                                    {
                                        printf("Would you like to place the order?\n1.Yes\n2.No");
                                        scanf("%d", &x);
                                        if (x == 1)
                                        {
                                            printf("Order placed!\nYour order will be delivered in 30 minutes\nThank you!\n");
                                            iloop = 0;
                                            loop = 0;
                                        }
                                    }
                                }
                                //   else{
                                //       deQueue(&Q1);
                                //   }
                            }
                        }
                    }
                }
                else if (c == 2)
                {
                    printf("Enter the name of restaurant:\n");
                    scanf("%s", rest);
                    autocomplete(&restaurant, rest);
                }
            }
            else if (b == 2)
            {
                printf("Enter the dish you want to order:\n");
                scanf("%s", rest);
                autocomplete(&vaishali, rest);
                // enter other restaurants also
            }
            else if (b == 3)
            {
                m2 = -1;
            }
        }
        else
        {
            m2 = -1;
        }
    }
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

// int main()
// {
//     Trie t1, restaurant;
//     int i = 0;
//     // char ch;
//     init(&t1);
//     init(&restaurant);

//     char *str;
//     // scanf("%s", str);

//     // insert(&t1, "apple");
//     insert(&t1, "masala dosa");
//     insert(&t1, "mysore dosa");
//     insert(&t1, "coffee");
//     insert(&t1, "uttappa");
//     insert(&t1, "pasta");
//     insert(&t1, "vaishali");
//     // display_menu(&t1);

//     // printf("%c", t1->ch);
//     // printf("%c", &t1->characters[0]->ch);
//     // print_trie(&t1);
//     //   printf("%c",t1->characters[0]->ch);
//     int s = search(&t1, "vaishali");
//     printf("search:%d\n", s);
//     autocomplete(&t1, "m");

//     FILE *fp = fopen("restaurants.txt", "r");
//     char word[255];
//     while (fscanf(fp, "%s", word) != -1)
//     {
//         insert(&restaurant, word);
//     }
//     fclose(fp);
//     // Trie restaurants;
//     // insert(&restaurant, "vaishali");
//    // insert_restaurants(restaurant);
//     int a = search(&restaurant, "vaishali");
//     printf("%d", a);
//     autocomplete(&restaurant, "g");

//     // insert_restaurants(restaurants);
//     // autocomplete(&restaurants, "Vai");
//     // display(&t1);
//     // int a = (int)ch;
//     // printf("%d", a);
//     return 0;
// }