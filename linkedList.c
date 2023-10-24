#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node* createnode(char s[], char a[], struct song_node* nx) {
    struct song_node *t = malloc(sizeof(struct song_node));
    strncpy(t->name, s, 128);
    strncpy(t->artist, a, 128);
    t->next = nx;
    return t;
}

struct song_node * insert_front(struct song_node * list, char name[], char artist[]) {
    return createnode(name, artist, list);
}
/*
int song_compare(struct song_node a, struct song_node b) {

}

struct song_node insert_song(char name[], char artist[], index) {

}
*/
void print_node(struct song_node * s) {
    printf("\"%s\" by %s\n", s->name, s->artist);
}

void print_list(struct song_node * start) {
    print_node(start);
    while((start = start->next)) {
        print_node(start);
    }
}
/*
struct song_node * find_song(char name[], char artist[]) {

}

struct song_node * find_artist(char artist[]) {

}

struct song_node * find_random() {

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
