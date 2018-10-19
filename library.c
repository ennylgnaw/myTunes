#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"
#include "library.h"

//add song nodes
void addnode(char songname[100], char songartist[100]) {
  int i = songartist[0] - 'a';
  if (i >= 27 || i < 0)
    i = 26;
  table[i] = insert_order(table[i], songname, songartist);
}

//Print out the entire library.
void print_library() {
  int i;
  for( i=0; i<=26; i++ ) {
    if (table[i]) {
      printf("%c list: ", i + 'a');
      print_list(table[i]);
    }
  }
}

//Search for a song given song and artist name (return a pointer).
struct song_node * song_search(char songname[100], char songartist[100]) {
  return find_song(table[songartist[0] - 'a'], songname, songartist);
}

//Search for an artist.
void artist_search(char songartist[100]){
  struct song_node * current = find_artist(table[songartist[0]-'a'], songartist);
  if (current)
    printf("Found %s: ", songartist);
  while (current) {
    if (strcmp(current->artist, songartist) == 0)
      printf("%s by %s - > ", current->name, current->artist);
    current = current->next;
  }
  printf("\n");
}

//Print out all the entries under a certain letter.
void print_letter(char letter) {
  printf("%c list:\n", letter);
  print_list(table[letter - 'a']);
  printf("\n");
}

//Print out all the songs of a certain artist
void print_artist_s(char songartist[100]) {
  printf("%s playlist:\n", songartist);
  struct song_node * current = find_artist(table[songartist[0]-'a'], songartist);
  while (current) {
    if (strcmp(current->artist, songartist) == 0)
      printf("%s by %s\n", current->name, current->artist);
    current = current->next;
  }
  printf("\n");
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle() {
  for (int i = 0; i < 10; i++) {
    int randletter = (rand() % 27);
    if (table[randletter]) {
      struct song_node * randnode = rand_song(table[randletter]);
      printf("%s by %s\n", randnode->name, randnode->artist);
    }
  }
  printf("\n");
}

//Delete a song
void delete_song(char songname[100], char songartist[100]) {
  int pos = songartist[0] - 'a';
  table[pos] = remove_song(table[pos], songname, songartist);
}

//Clear the library
void clear_lib() {
  for (int i = 0; i < 27; i++) {
    table[i] = free_list(table[i]);
  }
}
