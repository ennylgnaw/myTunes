#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct music_lib {struct song_node * table[27];};

//add song nodes
struct music_lib * addnode(struct music_lib * library, char songname[100], char songartist[100]) {
  if (! library) {
      struct music_lib * lib = malloc(sizeof(struct music_lib));
      library = lib;
      int i;
      for (i=0; i<=26; i++) library->table[i] = NULL;
  }
  if (!library->table[songartist[0]-'a'])
  library->table[songartist[0] -'a'] = insert_order(library->table[songartist[0]-'a'], songname, songartist);
  return library;
}

void print_library(struct music_lib * library) {
    int i;
    for( i=0; i<=26; i++ ) {
        if (library->table[i]) print_list(library->table[i]);
    }
}

int main() {
  struct music_lib * lib1 = addnode(NULL, "love story", "taylor swift");
  lib1 = addnode(lib1, "peek-a-boo", "red velvet");
  lib1 = addnode(lib1, "homework", "kero kero bonito");
  lib1 = addnode(lib1, "pocket crocodile", "kero kero bonito");
  lib1 = addnode(lib1, "automatic", "red velvet");
  print_library(lib1);
}
