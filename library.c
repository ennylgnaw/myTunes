#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct music_lib {struct song_node * table[27];};

//add song nodes
struct music_lib * addnode(struct music_lib * library, char songname[100], char songartist[100]) {
  int i;
  for (i = 0; i <= 27; i++)
    if (library->table[i]->artist[0] == i + "a")
      library->table[i] = insert_order(library->table[i], songname, songartist);
  return library;
}

int main() {
  struct music_lib * lib1 = addnode(NULL, "Love Story", "Taylor Swift");
  printf("%s, by %s", lib1->table[19]->name, lib1->table[1]->artist);
}
