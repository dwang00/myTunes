#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headerllist.h"

void print(struct song_node *node) {
  if (node == NULL) {
    printf("[]\n");
  }
  else {
    printf("%s - %s\n", node->artist, node->name);
  }
}

struct song_node * insert_front(struct song_node *next, char *name, char *artist) {
  struct song_node *ins = malloc(sizeof(struct song_node));
  strcpy(ins->name, name);
  strcpy(ins->artist, artist);
  ins->next = next;
  return ins;
}

struct song_node * insert_alpha(struct song_node *list, char *name, char *artist) {
  struct song_node *ins = insert_front(NULL, name, artist);
  struct song_node *lib = list;
  struct song_node *prev = NULL;
  while (lib != NULL ) {
    if (strcmp(ins->artist, lib->artist) < 0 || (strcmp(ins->artist, lib->artist) == 0 && strcmp(ins->name, lib->name) <= 0)) {
      if (prev == NULL){
        ins->next = list;
        return ins;
      }
      prev->next = ins;
      ins->next = lib;
      return list;
    }
    prev = lib;
    lib = lib->next;
  }
  if (prev == NULL){
    return ins;
  }
  prev -> next = ins;
  return list;
}

void print_list(struct song_node *node) {
  if (node != NULL) {
    while (node->next != NULL) {
      printf("%s - %s | ", node->artist, node->name);
      node = node->next;
    }
    printf("%s - %s\n", node->artist, node->name);
  }
  else {
    printf("[]\n");
  }
}

struct song_node * find(struct song_node *list, char *name, char *artist) {
  while(strcmp(list->name, name) != 0 || strcmp(list->artist, artist) != 0) {
    if (list->next == NULL) {
      return NULL;
    }
    list = list->next;
  }
  return list;
}

struct song_node * first(struct song_node *list, char* artist) {
  while(strcmp(list->artist, artist) != 0) {
    if (list->next == NULL) {
      return NULL;
    }
    list = list->next;
  }
  return list;
}

struct song_node * random(struct song_node *list) {
  while (list->next != NULL) {
    if (rand() % 2 == 0) {
      return list;
    }
    list = list->next;
  }
  return list;
}


struct song_node * remove_node(struct song_node *list, char *name, char *artist) {
  struct song_node *comp = find(list, name, artist);
  if (list == comp) {
    struct song_node *rest = list->next;
    free(list);
    return rest;
  }
  else {
    if (list->next != NULL) {
      list->next = remove_node(list->next, name, artist);
    }
    return list;
  }
}

struct song_node * free_list(struct song_node *list) {
  struct song_node *next = list;
  while (list != NULL) {
    next = list->next;
    printf("freeing %s - %s\n", list->artist, list->name);
    free(list);
    list = next;
  }
  return NULL;
}
