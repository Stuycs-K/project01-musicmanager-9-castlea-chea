#include "linkedList.h"
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

struct song_node** initialize_library(){
  struct song_node** library = malloc(27*sizeof(struct song_node*));
  for(int i = 0; i < 27; ++i) {
    library[i] = NULL;
  }
  return library;
}

void add_song_nodes(struct song_node** library, char name[], char artist[]){
  int firstLetter = artist[0];
  int i;
  if(firstLetter < 'a' || firstLetter > 'z') {
    i = 0;
  } else {
    i = firstLetter-'a' + 1;
  }
  library[i]=insert_song(library[i], name,artist);
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


void print_letter(struct song_node** library, char letter){
  int index = 0;
  if(letter>='a'&&letter<='z'){
    index = (letter - 96);
  }
  if(library[index]!=NULL){
    printf("%c:\n", letter);
    print_list(library[index]);
  }
  else{
    printf("%c:\nNO SONGS\n", letter);
  }
}

void shuffle(struct song_node** library, int n) {
    int file = open("/dev/random", O_RDONLY);
    while(--n >= 0) {
        int i = 0;
        if(read(file, &i, 4) == -1) {
            err();
        }
        i = i % 27;
        if(i < 0) {
          i = -1 * i;
        }
        while(library[i] == NULL) {
            if(read(file, &i, 4) == -1) {
                err();
            }
            i = i % 27;
            if(i < 0) {
              i = -1 * i;
            }
        }
        struct song_node * list = library[i];
        list = find_random(list);
        print_node(list);
    }
    close(file);
}

void lib_remove_song(struct song_node** library, char n[], char a[]) {
    int i;
    if(a[0] < 'a' || a[0] > 'z') {
        i = 0;
    } else {
        i = a[0] - 'a' + 1;
    }
    library[i] = remove_song(library[i], n, a);
}

void print_lib(struct song_node** library){
  for(int i = 0; i<27; i++){
    if(library[i]!=NULL){
      if(i>0){printf("%c:\n", i+96);}
      else{printf("misc characters:\n");}
      print_list(library[i]);
    }
  }
}

void print_artist(struct song_node** library, char artist[]){
  char firstLetter = artist[0];
  int index = 0;
  if(firstLetter>='a'&&firstLetter<='z'){
    index = (firstLetter - 96);
  }
  struct song_node *current = find_artist(library[index],artist);
  if(current == NULL) {
    return;
  }
  while(strcmp(current->artist,artist)==0){
    print_node(current);
    current=current->next;
    if(current == NULL) {
      return;
    }
  }
}

void lib_clear(struct song_node** library) {
    for(int i = 0; i < 27; ++i) {
        library[i] = free_list(library[i]);
    }
}
