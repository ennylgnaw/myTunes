#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#include "library.h"


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
  q = remove_song(q, rand_song(q)->name, rand_song(q)->artist);
  printf("Size of the list when a random song has been removed: %d\n", size(q));
  printf("Size of the list when freed: %d\n", size(free_list(q)));
  
  printf("---------------\n\n");  


  //testing library
  printf("---------------\nTESTING LIBRARY\n---------------\n\n");
  addnode("blood, sweat, and tears", "bts");
  addnode("fake love", "bts");
  addnode("tomorrow", "bts");
  addnode("love story", "taylor swift");
  addnode("you belong to me", "taylor swift");
  addnode("our song", "taylor swift");
  addnode("counting stars", "onerepublic");
  addnode("black horse", "katy perry");
  addnode("bon appetit", "katy perry");
  addnode("off to the races", "lana del rey");
  addnode("summertime sadness", "lana del rey");
  addnode("what makes you beautiful", "one direction");
  addnode("24k magic", "bruno mars");
  addnode("animals", "maroon 5");
  addnode("chandelier", "sia");
  addnode("payphone", "drake");
  addnode("new rules", "dua lipa");
  addnode("despacito", "justin bieber");

  //testing print_library

  printf("Testing addnode and print_library...\n\n");
  print_library();

  printf("---------------\n\n");

  printf("Testing artist_search...\n\n");
  artist_search("taylor swift");
  artist_search("bts");
  artist_search("bruno mars");
  artist_search("onerepublic");

  printf("---------------\n\n");

  printf("Testing print_letter...\n\n");
  print_letter('a');
  print_letter('b');
  print_letter('k');
  print_letter('t');
  print_letter('l');
  print_letter('o');

  printf("---------------\n\n");

  printf("Testing print_artist_s (print all songs by an artist)...\n\n");
  print_artist_s("bts");
  print_artist_s("taylor swift");
  print_artist_s("katy perry");
  print_artist_s("onerepublic");
  print_artist_s("bruno mars");
  print_artist_s("lana del rey");

  printf("---------------\n\n");

  printf("Testing shuffle...\n\n");
  shuffle();
  shuffle();
  shuffle();

  printf("---------------\n\n");

  printf("Testing delete_song...\n\n");
  printf("Before deletion...\n\n");
  print_library();
  printf("\n\nAfter deleting songs from dua lipa, bruno mars, maroon 5, and justin bieber...\n\n");
  delete_song("new rules", "dua lipa");
  delete_song("24k magic", "bruno mars");
  delete_song("animals", "maroon 5");
  delete_song("despacito", "justin bieber");
  print_library();

  printf("---------------\n\n");

  printf("Testing clear_lib...\n\n");
  clear_lib();
  print_library();
}
