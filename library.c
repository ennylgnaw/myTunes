#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct song_node * table[27];

//add song nodes
void addnode(struct song_node * table[27], char songname[100], char songartist[100]) {
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  
  for (int i = 0, i <= 27; i++)
    if (newsong->artist[0] == i + 97) {
      if (table[i] == NULL)
	table[i] = new;
      else:
	insert_order(table[i], 
    }
}
