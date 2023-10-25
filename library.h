#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node** initialize_library();
struct song_node* addSongNodes(struct song_node** library, struct song_node *startOfList, struct song_node song);
#endif
