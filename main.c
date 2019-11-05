#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "headerllist.h"
#include "headerarray.h"

void main() {
  srand(time(NULL));

  struct song_node *lib = NULL;
  struct song_node *test = NULL;
  lib = insert_alpha(lib, "Yes or Yes", "TWICE");
  lib = insert_alpha(lib, "My Headphones On", "TWICE");
  lib = insert_alpha(lib, "BDZ", "TWICE");
  lib = insert_alpha(lib, "Way Back Home", "Shaun");
  lib = insert_alpha(lib, "Russian Roulette", "Red Velvet");
  lib = insert_alpha(lib, "Dalla Dalla", "ITZY");

  printf("LINKED LIST TESTS\n");
  printf("=================\n");

  printf("Testing print (helper function, prints 1 node)\n");
  print(lib);
  printf("-----------------\n");

  printf("Testing print_list\n");
  print_list(lib);
  printf("-----------------\n");

  printf("Testing insert_alpha\n");
  lib = insert_alpha(lib, "Bbibbi", "IU");
  print_list(lib);
  printf("-----------------\n");

  printf("Testing insert_front\n");
  lib = insert_front(lib, "Lalala", "TWICE");
  print_list(lib);
  printf("-----------------\n");

  printf("Testing find\n");
  printf("Looking for \"Yes or Yes\" by TWICE\n");
  test = find(lib, "Yes or Yes", "TWICE");
  print(test);
  printf("Looking for \"Turtle\" by TWICE\n");
  test = find(lib, "Turtle", "TWICE");
  print(test);
  printf("-----------------\n");

  printf("Testing first (song by artist)\n");
  printf("Looking for TWICE\n");
  test = first(lib, "TWICE");
  print(test);
  printf("Looking for iKon\n");
  test = first(lib, "iKon");
  print(test);
  printf("-----------------\n");

  printf("Testing random\n");
  test = random(lib);
  print(test);
  test = random(lib);
  print(test);
  test = random(lib);
  print(test);
  printf("-----------------\n");

  printf("Testing remove_node\n");
  printf("Removing \"Lalala\" by TWICE\n");
  lib = remove_node(lib, "Lalala", "TWICE");
  print_list(lib);
  printf("Removing \"Way Back Home\" by Shaun\n");
  lib = remove_node(lib, "Way Back Home", "Shaun");
  print_list(lib);
  printf("Removing \"Yes or Yes\" by TWICE\n");
  lib = remove_node(lib, "Yes or Yes", "TWICE");
  print_list(lib);
  printf("-----------------\n");

  printf("Testing free_list\n");
  lib = free_list(lib);
  printf("List after freeing\n");
  print_list(lib);

  printf("=================\n");
  printf("MUSIC LIBRARY TESTS\n");
  printf("=================\n");

  printf("Testing blank (helper function, sets all elements of library to null)\n");
  blank();
  printf("Library:\n");
  print_all();
  printf("-----------------\n");

  printf("Testing add\n");
  add("Wishing", "TWICE");
  add("Eye Eye Eyes", "TWICE");
  add("Jelly Jelly", "TWICE");
  add("Breakthrough", "TWICE");
  add("Sappy", "Red Velvet");
  add("Power Up", "Red Velvet");
  add("Love Poem", "IU");
  add("Solo", "Jennie");
  printf("-----------------\n");

  printf("Testing print_all\n");
  print_all();
  printf("-----------------\n");

  printf("Testing print_letter\n");
  printf("Printing \"t\"\n");
  print_letter('t');
  printf("Printing \"r\"\n");
  print_letter('r');
  printf("Printing \"a\"\n");
  print_letter('a');
  printf("-----------------\n");

  printf("Testing print_artist\n");
  printf("Printing TWICE\n");
  print_artist("TWICE");
  printf("Printing IU\n");
  print_artist("IU");
  printf("Printing iKon\n");
  print_artist("iKon");
  printf("-----------------\n");

  printf("Testing shuffle\n");
  shuffle();
  printf("-----------------\n");

  printf("Testing delete\n");
  printf("Deleting \"Love Poem\"\n");
  delete("Love Poem", "IU");
  print_all();
  printf("Deleting \"Power Up\"\n");
  delete("Power Up", "Red Velvet");
  print_all();
  printf("Deleting \"Wishing\"\n");
  delete("Wishing", "TWICE");
  print_all();
  printf("-----------------\n");

  printf("Testing clear\n");
  clear();
  printf("Library after clear\n");
  print_all();
}
