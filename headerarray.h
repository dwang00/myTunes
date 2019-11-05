struct song_node *library[27];
void blank();
int get_ind(char letter);

void add(char *name, char *artist);
struct song_node * search_name(char *name, char *artist);
struct song_node * search_artist(char *artist);
void print_letter(char letter);
void print_artist(char *artist);
void print_all();
void shuffle();
void delete(char *name, char *artist) ;
void clear();
