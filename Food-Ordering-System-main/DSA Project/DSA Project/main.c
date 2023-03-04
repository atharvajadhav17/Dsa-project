#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "Trie.h"

int m = 0;
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

    while (m >= 0)
    {

        printf("Welcome to FoodieBay\n");
        printf("1.Login\n2.Signup\n");
        int a, b, c;
        char un[255];
        char p[255];
        char n[255];
        char address[255];
        char mobileno[10];
        char rest[255];
        scanf("%d", &a);

        FILE *fp;
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
            login(un, p);
            if (m == 2)
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
                        FILE *fp = fopen("restaurants.txt", "r");
                        char word[255];
                        while (fscanf(fp, "%s", word) != -1)
                        {
                            printf("%s\n",word);
                        }
                        fclose(fp);
                    }
                    else if(c==2){
                        printf("Enter the name of restaurant:\n");
                        scanf("%s",rest);
                        autocomplete()
                    }
                }
            }
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
            m = -1;
        else
            printf("Enter a valid number:\n");
    }
}
