#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//song node
struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

//print the entire list
void print_list(struct song_node * head) {
  if (head == NULL) printf("EMPTY");
  while ( head != NULL) {
    printf("%s by %s -> ", head->name, head->artist);
    head = head->next;
  }
  printf("\n");
}

//insert node at the front
struct song_node * insert_front(struct song_node * head, char songname[100], char songartist[100]) {
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  strcpy(new->name, songname);
  strcpy(new->artist, songartist);
  new->next = head;
  return new;
} 

//insert node in order
struct song_node * insert_order(struct song_node * head, char songname[100], char songartist[100]) {
    
  struct song_node *current = head;
  if (! current) return insert_front(NULL, songname, songartist); //if head is null, insert in front
  if (strcmp(songartist, current->artist) < 0) return insert_front(head, songname, songartist); //if head is greater than value, insert in front
  if (strcmp(songartist, current->artist) == 0)
    if (strcmp(songname, current->name) <= 0)
      return insert_front(head, songname, songartist);
  while (current->next) {
    if (strcmp(current->next->artist, songartist) > 0) {
      current->next = insert_front(current->next, songname, songartist); //if the data has a place between two nodes
      return head;
    }
    else if (strcmp(current->next->artist, songartist) == 0) {
      while (current->next) {
	if (strcmp(current->next->name, songname) > 0) {
	  current->next = insert_front(current->next, songname, songartist); //if the data has a place between two nodes
	  return head;
	}
	current = current->next;
      }
      current->next = insert_front(current->next, songname, songartist);
      return head;
    }
    current = current->next;
  }
    
  current->next = insert_front(current->next, songname, songartist);
  return head;
  // if current doesn't have a next but it hasn't beeen sorted
}

//find and return a pointer to a node based on artist and song name
struct song_node * find_song(struct song_node * head, char songname[100], char songartist[100]) {
  struct song_node *current = head;
  while (current) {
    if (strcmp(current->artist, songartist) == 0 && strcmp(current->name, songname) == 0)
      return current;
    current = current->next;
  }
  return NULL;
}

//find and return a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node * head, char songartist[100]) {
  struct song_node *current = head;
  while (current) {
    if (strcmp(current->artist, songartist) == 0)
      return current;
    current = current->next;
  }
  return NULL;
}

//size of linked list
int size(struct song_node * head) {
  int i = 0;
  struct song_node *current = head;
  while (current) {
    i++;
    current = current->next;
  }
  return i;
}

//Return a pointer to random element in the list.
struct song_node * rand_song(struct song_node * head) {
  struct song_node *current = head;
  int randNum = rand() % size(head);
  while (randNum > 0) {
    current = current->next;
    randNum--;
  }
  return current;
}

//remove a single specified node from the list
struct song_node * remove_song(struct song_node * head, char songname[100], char songartist[100]) {
  struct song_node *current = head;
  if (strcmp(current->artist, songartist) == 0 && strcmp(current->name, songname) == 0) {
    struct song_node *nextNode = head->next;
    free(head);
    head = nextNode;
    return head;
  }
  while (current->next) {
    if (strcmp(current->next->artist, songartist) == 0 && strcmp(current->next->name, songname) == 0) {
      struct song_node *newNext = current->next->next;
      free(current->next);
      current->next = newNext;
      return head;
    }
    current = current->next;
  }
  return head;
}

//free the entire list
struct song_node * free_list(struct song_node * head) {
  while (head) {
    struct song_node *nextNode = head->next;
    free(head);
    head = nextNode;
  }
  return NULL;
}
