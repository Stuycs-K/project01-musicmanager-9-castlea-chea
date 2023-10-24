#include "linkedList.h"
#include <string.h>
int SONG_LESS = -2; // make constants for future reference
int SONG_MORE = 2;
int ARTIST_LESS = -1;
int ARTIST_MORE = 1;
/*
struct song_node insert_front(char name[], char artist[]) {

} */

int song_compare(struct song_node a, struct song_node b) {
  int artists = strcmp(a.artist,b.artist);
  if(artists==0){
    int names = strcmp(a.name,b.name)
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

struct song_node insert(char name[], char artist[]) {
  struct song_node newNode; //create a node with the values given
  struct song_node *pointer = list; // make a pointer to the array of linked lists
  strcpy(newNode.artist,artist);
  strcpy(newNode.name,name);
  while(song_compare(*pointer,newNode)==ARTIST_LESS){ //while the pointer has a lower value
    pointer++;
  }
  if(song_compare(*pointer,newNode)==SONG_LESS){
    pointer=pointer->next;
  }
}

/*void print_list(struct song_node * start) {

}

struct song_node * find_song(char name[], char artist[]) {

}

struct song_node * find_artist(char artist[]) {

}

struct song_node * find_random() {

}

struct song_node * remove(char name[], char artist[]) {

}

struct song_node * free_list() {

}
*/
