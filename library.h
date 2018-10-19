#ifndef LIBRARY_H
#define LIBRARY_H
#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node * table[27];

void addnode(char songname[100], char songartist[100]);
struct song_node * song_search(char songname[100], char songartist[100]);
void artist_search(char songartist[100]);
void print_letter(char letter);
void print_artist_s(char songartist[100]);
void print_library();
void shuffle();
void delete_song(char songname[100], char songartist[100]);
void clear_lib();

#endif
