#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node** initialize_library();
void add_song_nodes(struct song_node** library, char name[], char artist[]);
void print_letter(struct song_node** library, char letter);
#endif
