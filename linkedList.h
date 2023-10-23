#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct song_node {
    char name[128];
    char artist[128];
    struct song_node * next;
}

struct song_node insert_front(char name[], char artist[]);

int song_compare(struct song_node a, struct song_node b);

struct song_node insert(char name[], char artist[], index);

void print_list(struct song_node * start);

struct song_node * find_song(char name[], char artist[]);

struct song_node * find_artist(char artist[]);

struct song_node * find_random();

struct song_node * remove(char name[], char artist[]);

struct song_node * free_list();
#endif