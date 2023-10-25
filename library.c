#include "linkedList.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

struct song_node** initialize_library(){
  struct song_node** library = malloc(27*sizeof(struct song_node));
  return library;
}

struct song_node* addSongNodes(struct song_node** library, struct song_node *startOfList, struct song_node song){
  int i = 0;
  while
  return startOfList;
}

struct song_node* lib_find_song(struct song_node** library, char n[], char a[]) {
    int i;
    if(a[0] < 'a' || a[0] > 'z') {
        i = 0;
    } else {
        i = a[0] - 'a' + 1;
    }
    return find_song(library[i], n, a);
}

struct song_node* lib_find_artist(struct song_node** library, char a[]) {
    int i;
    if(a[0] < 'a' || a[0] > 'z') {
        i = 0;
    } else {
        i = a[0] - 'a' + 1;
    }
    return find_artist(library[i], a);
}