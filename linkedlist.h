struct song_node { char name[100]; char artist[100]; struct song_node *next; };

void print_list(struct song_node * head);

struct song_node * insert_front(struct song_node * head, char songname[100], char songartist[100]);

struct song_node * insert_order(struct song_node * head, char songname[100], char songartist[100]);

struct song_node * find_song(struct song_node * head, char songname[100], char songartist[100]);

struct song_node * find_artist(struct song_node * head, char songartist[100]);

int size(struct song_node * head);

struct song_node * rand_song(struct song_node * head);

struct song_node * remove_song(struct song_node * head, char songname[100], char songartist[100]);

struct song_node * free_list(struct song_node * head);
