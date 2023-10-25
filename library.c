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

void add_song_nodes(struct song_node** library, struct song_node* song){
  int firstLetter = song->artist[0];
  int i = firstLetter-95;
  if(library[i]!= NULL){insert_song(library[i],song->name,song->artist);}
  else{library[i]=song}
}
