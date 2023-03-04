typedef struct node
{
    char ch;
    struct node *characters[26];
    int level;
    int eow;

} node;



typedef node *Trie;
void init(Trie *t);
void insert(Trie *t, char *word);
void print_trie(Trie *t, char *word, int l);
int search(Trie *t, char *word);
void autocomplete(Trie *t, char *word);
