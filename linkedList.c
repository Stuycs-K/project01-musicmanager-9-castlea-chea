#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int SONG_LESS = -2; // make constants for future reference
int SONG_MORE = 2;
int ARTIST_LESS = -1;
int ARTIST_MORE = 1;

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

struct song_node* createnode(char s[], char a[], struct song_node* nx) {
    struct song_node *t = malloc(sizeof(struct song_node));
    strncpy(t->name, s, 128);
    strncpy(t->artist, a, 128);
    t->next = nx;
    return t;
}

int song_compare(struct song_node a, struct song_node b) {
  int artists = strcmp(a.artist,b.artist);
  if(artists==0){
    int names = strcmp(a.name,b.name);
    if(names<0){
      return SONG_LESS;
    }
    else{
      return SONG_MORE;
    }
  }
  else if(artists<0){
    return ARTIST_LESS;
  }
  else{
    return ARTIST_MORE;
  }
}

struct song_node * insert_song(struct song_node * list, char name[], char artist[]) {
    //printf("a");
    //fflush(stdout);
    struct song_node * newNode = createnode(name, artist, NULL); //create a node with the values given
    if(list == NULL) {
        return newNode;
    }
    struct song_node *pointer = list; // make a pointer to the array of linked lists
    struct song_node *previous = NULL;
    while(song_compare(*pointer,*newNode) < 0){ //song less or artist less
        previous = pointer;
        pointer=pointer->next;
        if(pointer == NULL) {
            previous->next = newNode;
            return list;
        }
    }
    if(previous == NULL) { //list is just one element and newNode belongs before it
        newNode->next = list;
        return newNode;
    }
    previous->next = newNode;
    newNode->next = pointer;
    return list;
}

void print_node(struct song_node * s) {
    printf("\"%s\" by %s\n", s->name, s->artist);
}

void print_list(struct song_node * start) {
    if(start == NULL) {
        return;
    }
    print_node(start);
    while((start = start->next)) {
        print_node(start);
    }
}

struct song_node * insert_front(struct song_node * list, char name[], char artist[]) {
    return createnode(name, artist, list);
}

/*
struct song_node * find_song(char name[], char artist[]) {

}

struct song_node * find_artist(char artist[]) {

}
*/
int get_size(struct song_node * list) {
    if(list == NULL) {
        return 0;
    }
    int i = 1;
    while((list = list->next)) {
        ++i;
    }
    return i;
}

struct song_node * find_random(struct song_node * list) {
    int rand;
    int file = open("/dev/random", O_RDONLY);
    if(read(file, &rand, sizeof(int)) == -1) {
        err();
    }
    rand %= get_size(list);
    if(rand < 0) {
        rand = -1 * rand;
    }
    while(rand-- > 0) {
        list = list->next;
    }
    close(file);
    return list;
}

struct song_node * remove_song(struct song_node * list, char n[], char a[]) {
    if(strcmp(list->artist, a) == 0 && strcmp(list->name, n) == 0) {
        return list->next;
    }
    struct song_node * prev = list;
    struct song_node * spare = list;
    while((list = list->next)) {
        if(strcmp(list->artist, a) == 0 && strcmp(list->name, n) == 0) {
            prev->next = list->next;
            free(list);
            return spare;
        }
        prev = list;
    }
    return spare;
}



struct song_node * free_list(struct song_node * s) {
    if(s == NULL) {
        return s;
    }
    struct song_node* next = s->next;
    free(s);
    return free_list(next);
}
