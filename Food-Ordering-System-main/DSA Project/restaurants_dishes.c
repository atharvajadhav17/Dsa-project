#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "Trie.h"



void insert_restaurants(Trie t1){
           init(&t1);
           FILE *fp=fopen("restaurants.txt","r");
           char word[255];
           while (fscanf(fp, "%s", word) != -1){
                            insert(&t1,word);
           }
           fclose(fp);
           return;

}


int main(){
        Trie restaurants;
        insert_restaurants(restaurants);
        autocomplete(&restaurants,"Vai");
        return 0;
}