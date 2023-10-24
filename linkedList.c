#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SONG_LESS = -1; // make constants for future reference
int SONG_MORE = 1;
int SONG_EQUAL = 0;
int ARTIST_LESS = -2;
int ARTIST_MORE = 2;

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
    else if(names>0){
      return SONG_MORE;
    }
    else{
      return SONG_EQUAL;
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


struct song_node * find_song(struct song_node* startOfList, char name[], char artist[]) {
  struct song_node *current = startOfList; // current struct node pointer points to front of list
  struct song_node comparing = createnode(name,artist); // make a song node to song_compare
  while(song_compare(*current,comparing)!=SONG_EQUAL){
    current = current->next;
  }
  return current;
}

struct song_node * find_artist(struct song_node* startOfList, char artist[]) {
  struct song_node *current = startOfList; // current struct node pointer points to front of list
  struct song_node comparing = createnode(name,artist); // make a song node to song_compare
  while(song_compare(*current,comparing)==ARTIST_LESS||song_compare(*current,comparing)==ARTIST_MORE){ // until artists are the same, incrememnt current node
    current = current->next;
  }
  return current;
}

/*struct song_node * find_random() {

}

struct song_node * remove_song(char name[], char artist[]) {

}
*/

struct song_node * free_list(struct song_node * s) {
    if(s == NULL) {
        return s;
    }
    struct song_node* next = s->next;
    free(s);
    return free_list(next);
}
