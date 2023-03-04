#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "Trie.h"
//#include "queue.h"
#include "main.h"
#include "linkedlist.h"
#include "DLL.h"

int order_num, m1, m2;

int main()
{

    order_num = 1, m1 = m2 = 0;
    int a, b, c, y, k, x, cost, total_cost = 0;
    Queue Q1;
    // init_Queue(&Q1);
    Queue *q = createQueue(3);

    hash h1;
    // init_hash(3);
    hash *h = createhash(10);

    list L1;
    init_list(&L1);

    cart arr[30];
    int index = 0, items = 0;

    char rest[255];
    char un[255];
    char p[255];
    char n[255];
    char address[255];
    char mobileno[10];

    char food1[30];
    char food2[30];
    char food3[30];
    char food4[30];
    char food5[30];
    Trie FB;
    init(&FB);

    FILE *FP;
    FP = fopen("Orders.txt", "a");

    FILE *fp = fopen("FoodieBay.txt", "r");
    char word[255];
    while (fscanf(fp, "%s", word) != -1)
    {
        insert(&FB, word);
    }
    fclose(fp);

    // login-signup
    while (m1 >= 0)
    {
        // Trie restaurant;

        // init(&restaurant);
        // FILE *fp = fopen("restaurants.txt", "r");
        // char word[255];
        // while (fscanf(fp, "%s", word) != -1)
        // {
        //     insert(&restaurant, word);
        // }
        // fclose(fp);

        printf("Welcome to FoodieBay!\n");
        printf("1.Login\n2.Signup\n3.Exit");
        printf("\n");

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
            // printf("%d", m2);
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
            m1 = -2;
        else
            printf("Enter a valid number:\n");
    }

    if (m1 != -2)
    {

        // ordering food
        while (m2 >= 0)
        {
            if (m2 == 2)
            {
                printf("Order your food now\n");
                printf("1.Display menu\n2.Search for a specific dish\n3.View previous orders\n4.Exit\n");
                scanf("%d", &b);
                if (b == 1)
                {
                    int count = 1, c1;
                    FILE *fp = fopen("FoodieBay.txt", "r");
                    char word[255];
                    while (fscanf(fp, "%s", word) != -1)
                    {
                        printf("%d %s\n", count, word);
                        count++;
                    }
                    fclose(fp);
                }
                else if (b == 2)
                {
                    int iloop = 1;
                    while (iloop >= 1)
                    {

                        printf("What would you like to order?\n");
                        char line[1000];

                        scanf("%s", line);

                        // while (fgets(line, sizeof(line), fp) != NULL)
                        // {
                        //     fputs(line, stdout);
                        // }
                        // autocomplete(&FB, line);
                        printf("\n");
                        char p[2];
                        p[0] = line[0];
                        p[1] = line[1];
                        autocomplete(&FB, p);
                        // p[0] = line[0];
                        // p[1] = line[2];
                        // p[2] = line[1];
                        // p[3] = line[4];
                        // autocomplete(&FB, p);
                        printf("\n");
                        printf("We have following items related to your search\n");
                        printf("What would you like to order?\n");
                        scanf("%s", line);
                        printf("Enter the quantity:\n");
                        scanf("%d", &k);
                        printf("Add %s to the cart?\n1.Yes\n2.No", line);

                        scanf("%d", &y);
                        if (y == 1)
                        {
                            // enQueue(&Q1,)
                            int count = 1, count1 = 1;
                            FILE *fp = fopen("FoodieBay.txt", "r");
                            while (count1 == 1)
                            {
                                fscanf(fp, "%s", word);
                                if (strcmp(line, word) == 0)
                                    count1 = 0;
                                else
                                    count++;
                            }
                            printf("%d\n", count);
                            count1 = 0;
                            // printf("Hi\n");
                            // while (fscanf(fp, "%s", word) != -1)
                            // {
                            //     if (line == word)
                            //     {
                            //         break;
                            //     }
                            //     else
                            //         count++;
                            // }
                            fclose(fp);
                            FILE *fptr = fopen("Prices.txt", "r");
                            while (count1 != count)
                            {
                                count1++;
                                fscanf(fptr, "%d", &cost);
                            }
                            //  printf("hi\n");
                            printf("%d\n", cost);
                            cost = cost * k;
                            // while (fscanf(fptr, "%d", &cost) != -1)
                            // {
                            //     if (count1 == count)
                            //     {
                            //         break;
                            //     }
                            //     else
                            //         count1++;
                            // }
                            fclose(fptr);
                            // strcpy(arr[index].food, line);
                            // arr[index].orderno = order_num;
                            // arr[index].price = cost;
                            // arr[index].quantity = k;
                            // index++;
                            // items++;
                            static int j = 0;
                            if (j == 0)
                            {
                                fprintf(FP, "%d\n", order_num);
                                j = 1;
                            }
                            fprintf(FP, "%s\n", line);
                            insert_begin(&L1, line, cost, k, order_num);
                            total_cost = total_cost + cost;
                            // order[k].food=word;
                            // order[k].price=cost;

                            // cart *q;
                            // q=order;
                            // q->food=word;
                            // q->price=cost;
                            // C.food[k] = word;
                            // C.price[k] = cost;
                            printf("Do you want to order more?\n1.Yes\n2.No\n");
                            scanf("%d", &y);
                            if (y == 2)
                            {
                                printf("    Order details    \n");
                                printf("Order no: %d\n", order_num);
                                //  printf("%s\n", line);
                                print_cart(L1);

                                printf("Do you want to confirm your order?\n1.Yes\n2.No\n");
                                scanf("%d", &y);
                                if (y == 1)
                                {
                                    // FILE *fp;
                                    // if (is_capacity_full(&Q1))
                                    // {
                                    //     fp = fopen("Orders.txt", "w");
                                    // }
                                    // else
                                    // {
                                    //     fp = fopen("Orders.txt", "a");
                                    // }
                                    // int i = 0;
                                    // while (i < items)
                                    // {
                                    //     fwrite(&arr[i], sizeof(arr[i]), 1, fp);
                                    //     i++;
                                    // }
                                    // fclose(fp);
                                    LRU_order(q, h, order_num);

                                    printf("Order placed!\nThanks for ordering!\n");
                                    printf("Your order:\n");
                                    print_cart(L1);

                                    printf("Total:%d Rs\n", total_cost);
                                    destroy_List(&L1);
                                    j = 0;
                                    // FILE *fp = fopen("Signup.txt", "r");
                                    // // printf("%s",un);
                                    // while (fscanf(fp, "%s", word) != -1)
                                    // {
                                    //     if (un == word)
                                    //     {
                                    //         break;
                                    //     }
                                    // }
                                    // fscanf(fp, "%s", word);
                                    // fgets(word,sizeof(word),fp);
                                    //  fscanf(fp, "%s", word);
                                    // C.addr[0] = word;
                                    // printf("Delivery address:%s\n", word);

                                    // fclose(fp);
                                    iloop = 0;
                                    m2 = -1;
                                }
                                if (y == 2)
                                {
                                    int loop = 0;
                                    while (loop == 0)
                                    {
                                        printf("Do you want to delete an item from the cart?\n1.Yes\n2.No\n");
                                        scanf("%d", &y);
                                        if (y == 1)
                                        {
                                            printf("Enter the name of item you want to delete:\n");
                                            scanf("%s", word);
                                            delete_item(&L1, word);
                                            printf("Order details:\n");
                                            print_cart(L1);
                                            printf("Do you want to confirm your order?\n1.Yes\n2.No\n");
                                            scanf("%d", &y);
                                            if (y == 1)
                                            {

                                                // FILE *fp;
                                                // if (is_capacity_full(&Q1))
                                                // {
                                                //     fp = fopen("Orders.txt", "w");
                                                // }
                                                // else
                                                // {
                                                //     fp = fopen("Orders.txt", "a");
                                                // }
                                                // int i = 0;
                                                // printf("%d",items);
                                                // while (i < items)
                                                // {
                                                //     fwrite(&arr[i], sizeof(arr[i]), 1, fp);
                                                //     i++;
                                                // }
                                                // fclose(fp);
                                                LRU_order(q, h, order_num);

                                                printf("Order placed!\nThanks for ordering!\n");
                                                destroy_List(&L1);
                                                j = 0;
                                                printf("Your order:\n");

                                                printf("Order no: %d\n", order_num);

                                                print_cart(L1);

                                                printf("Total:%d Rs\n", total_cost);
                                                loop = 1;
                                            }
                                        }
                                    }
                                }
                                printf("Do you want to exit?\n1.Yes\n2.No");
                                scanf("%d", &y);
                                if (y == 1)
                                {
                                    m2 = -1;
                                }
                                else
                                {
                                    iloop = 0;
                                    m2 = 2;
                                }

                                // iloop = 0;
                                order_num++;
                            }
                        }
                    }
                }
                else if (b == 3)
                {
                    if (isQueueEmpty(q))

                    {
                        printf("There are no previous orders\n");
                    }
                    else
                    {
                        int num;
                        char menu[50];
                        FILE *fp = fopen("Orders.txt", "r");
                        printf("Order %d:\n", q->front->orderno);
                        while (fscanf(fp, "%d", &num) != -1)
                        {
                            if (num == q->front->orderno)
                                break;
                        }
                        fscanf(fp, "%s", menu);
                        printf("%s\n", menu);

                        fseek(fp,0,SEEK_SET);

                        printf("%d\n", q->front->next->orderno);
                        while (fscanf(fp, "%d", &num) != -1)
                        {
                            if (q->front->next->orderno)
                                break;
                        }
                        fscanf(fp, "%s", menu);
                        printf("%s\n", menu);


                        fseek(fp,0,SEEK_SET);
                        
                        printf("%d\n", q->front->next->next->orderno);
                        while (fscanf(fp, "%d", &num) != -1)
                        {
                            if (q->front->next->next->orderno)
                                break;
                        }
                        fscanf(fp, "%s", menu);
                        printf("%s\n", menu);
                        fclose(fp);
                        // char *ch;
                        // while (fscanf(FP, "%s", ch) != -1)
                        // {
                        //     printf("%s", ch);
                        // }
                        // fclose(FP);
                    }
                }
                else
                {
                    m2 = -1;
                }
            }
        }
    }
}
