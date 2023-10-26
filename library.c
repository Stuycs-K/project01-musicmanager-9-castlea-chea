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
  int index = (letter - 96);
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
        printf("a");
        fflush(stdout);
        int i = 0;
        if(read(file, &i, 4) == -1) {
            err();
        }
        i = i % 27;
        printf("a");
        fflush(stdout);
        while(library[i] != NULL) {
            if(read(file, &i, 4) == -1) {
                err();
            }
            i = i % 27;
        }
        printf("a");
        fflush(stdout);
        struct song_node * list = library[i];
        print_node(find_random(list));
        fflush(stdout);
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

void lib_clear(struct song_node** library) {
    for(int i = 0; i < 27; ++i) {
        library[i] = free_list(library[i]);
    }
}
