#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"


// because I got tired of typing the same two lines every I tried to test the finding functions.
void found_song(struct song_node * a) {
  if (a) printf("Found a song: %s by %s\n", a->name, a->artist);
  else printf("Couldn't find any songs!\n");    
}

int main() {
  srand( time(NULL));
  printf("---------------\nTESTING LINKED LIST\n---------------\n\n");
  printf("Testing print_list:\n\n");
    
  struct song_node * q = insert_front(NULL, "Trouble", "Taylor Swift");
  q = insert_order(q, "Single Lady", "Beyonce");
  q = insert_order(q, "Love Story", "Taylor Swift");
  q = insert_order(q, "Young Forever", "Taylor Swift");
  q = insert_order(q, "All Too Well", "Taylor Swift");
  q = insert_order(q, "Flamingo", "Kero Kero Bonito");
  q = insert_order(q, "Peek-A-Boo", "Red Velvet");
  q = insert_order(q, "Automatic", "Red Velvet");
  
  print_list(q);
  printf("---------------\n\n");
  
  printf("Testing find_song:\n\n");
  printf("Looking for a song by Taylor Swift:\n");
  struct song_node *a = find_artist(q, "Taylor Swift");
  found_song(a);
  
  printf("Looking for a song by Red Velvet:\n");
  a = find_artist(q, "Red Velvet");
  found_song(a);
  
  printf("Looking for a song by Lady Gaga:\n");
  a = find_artist(q, "Lady Gaga");
  found_song(a);
  
  printf("---------------\n\n");
  
  printf("Testing find_node:\n\n");
  //find and return a pointer to a node based on artist and song name
  printf("Looking for \"Love Story\" by Taylor Swift\n");
  a = find_song(q, "Love Story", "Taylor Swift");
  found_song(a);
  
  printf("Looking for \"Flamingo\" by Kero Kero Bonito\n");
  a = find_song(q, "Flamingo", "Kero Kero Bonito");
  found_song(a);
  
  printf("Looking for \"Young Forever\" by Taylor Swift\n");
  a = find_song(q, "", "Taylor Swift");
  found_song(a);
  
  printf("---------------\n\n");  
  
  //Return a pointer to random element in the list.
  
  printf("Testing rand_song by generating three random songs:\n\n");
  
  a  = rand_song(q);
  printf("Artist: %s, Song: %s\n", a->artist, a->name);
  a  = rand_song(q);
  printf("Artist: %s, Song: %s\n", a->artist, a->name);
  a  = rand_song(q);
  printf("Artist: %s, Song: %s\n", a->artist, a->name);
  
  printf("---------------\n\n");  

  printf("Testing remove_song by removing three random songs:\n\n");
  
  a = rand_song(q);
  printf("Removing %s by %s...\n", a->name, a->artist);
  q = remove_song(q, a->name, a->artist);
  a = rand_song(q);
  printf("Removing %s by %s...\n", a->name, a->artist); 
  q = remove_song(q, a->name, a->artist);
  a = rand_song(q);
  printf("Removing %s by %s...\n", a->name, a->artist);
  q = remove_song(q, a->name, a->artist);
  
  print_list(q);
  printf("---------------\n\n");  

  //remove a single specified node from the list

  printf("Testing free_list...\n");
  print_list(free_list(q));
  
  printf("---------------\n\n");  
  
  printf("Testing insert_front [HELPER FUNCTION]...\n");
  q = insert_front(NULL, "Dudu", "Tarkan");
  printf("Inserting %s by %s\n", q->name, q->artist);
  q = insert_front(q, "Kuzu Kuzu", "Tarkan");
  printf("Inserting %s by %s\n", q->name, q->artist);
  q = insert_front(q, "Baam", "Momoland");
  printf("Inserting %s by %s\n", q->name, q->artist);
  print_list(q);
  
  printf("---------------\n\n");  

  printf("Testing size [HELPER FUNCTION]...\n");
  printf("Size of the list: %d\n", size(q));
  printf("Size of the list when a random song has been removed: %d\n", size( remove_song(q, rand_song(q)->name, rand_song(q)->artist)));
  printf("Size of the list when freed: %d\n", size(free_list(q)));
  
  printf("---------------\n\n");  

}
