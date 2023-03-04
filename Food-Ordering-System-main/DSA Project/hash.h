typedef struct hash
{
    int size;
    QNode **array;
} hash;

hash *init_hash(int s);