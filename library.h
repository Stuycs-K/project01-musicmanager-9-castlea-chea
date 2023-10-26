#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node** initialize_library();
void add_song_nodes(struct song_node** library, char name[], char artist[]);
void print_letter(struct song_node** library, char letter);
struct song_node* lib_find_song(struct song_node** library, char n[], char a[]);
struct song_node* lib_find_artist(struct song_node** library, char a[]);
void lib_remove_song(struct song_node** library, char n[], char a[]);
void lib_clear(struct song_node** library);
#endif
