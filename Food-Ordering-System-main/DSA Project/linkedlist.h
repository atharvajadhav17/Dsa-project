typedef struct cart
{
    char food[255];
    int price;
    int quantity;
    int orderno;
    struct cart *next;
} cart;

typedef cart *list;
void init_list(list *L);
void print_cart(list L);
void insert_begin(list *L, char *Food,int Price,int quant,int onum);
void delete_item(list *L, char *d);
void destroy_List(list *L);
