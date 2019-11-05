struct song_node{char name[100], artist[100]; struct song_node *next;};
void print(struct song_node *node);

void print_list(struct song_node *node);
struct song_node * insert_front(struct song_node *next, char *name, char *artist);
struct song_node * insert_alpha(struct song_node *list, char *name, char *artist);
struct song_node * find(struct song_node *list, char *name, char *artist);
struct song_node * first(struct song_node *list, char* artist);
struct song_node * random(struct song_node *list);
struct song_node * remove_node(struct song_node *list, char *name, char *artist);
struct song_node * free_list(struct song_node *list);
