#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headerllist.h"
#include "headerarray.h"

void blank() {
  int i;
  for (i = 0; i < 27; i++) {
    library[i] = NULL;
  }
}

int get_ind(char letter) {
  int index = tolower(letter) - 'a';
  if (index < 0) {
    index = 26;
  }
}

void add(char *name, char *artist) {
  int index = get_ind(tolower(artist[0]));
  library[index] = insert_alpha(library[index], name, artist);
}

struct song_node * search_name(char *name, char *artist) {
  int index = get_ind(tolower(artist[0]));
  return find(library[index], name, artist);
}

struct song_node * search_artist(char *artist) {
  int index = get_ind(tolower(artist[0]));
  return first(library[index], artist);
}

void print_letter(char letter) {
  int index = get_ind(letter);
  print_list(library[index]);
}

void print_artist(char *artist) {
  struct song_node *song = search_artist(artist);
  struct song_node *list = NULL;
  while (song != NULL) {
    if (strcmp(song->artist, artist) == 0) {
      list = insert_alpha(list, song->name, song->artist);
    }
    song = song->next;
  }
  print_list(list);
}

void print_all() {
  struct song_node *list = NULL;
  int i;
  for (i = 0; i < 27; i++) {
    if (library[i] != NULL) {
      struct song_node *song = library[i];
      while (song != NULL) {
        list = insert_alpha(list, song->name, song->artist);
        song = song->next;
      }
    }
  }
  print_list(list);
}

void shuffle() {
  struct song_node *list = NULL;
  struct song_node *shuffled = NULL;
  int i;
  for (i = 0; i < 27; i++) {
    if (library[i] != NULL) {
      struct song_node *song = library[i];
      while (song != NULL) {
        list = insert_alpha(list, song->name, song->artist);
        song = song->next;
      }
    }
  }
  while (list != NULL) {
    struct song_node *song = random(list);
    shuffled = insert_front(shuffled, song->name, song->artist);
    list = remove_node(list, song->name, song->artist);
  }
  print_list(shuffled);
}

void delete(char *name, char *artist) {
  int index = get_ind(tolower(artist[0]));
  library[index] = remove_node(library[index], name, artist);
}

void clear() {
  int i;
  for (i = 0; i < 27; i++) {
    library[i] = free_list(library[i]);
  }
}
