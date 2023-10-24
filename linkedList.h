#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct song_node {
    char name[128];
    char artist[128];
    struct song_node * next;
};

struct song_node * insert_front(struct song_node * list, char n[], char a[]);

int song_compare(struct song_node a, struct song_node b);

struct song_node * insert_song(struct song_node * list, char name[], char artist[]);

void print_node(struct song_node * s);

void print_list(struct song_node * start);

struct song_node * find_song(struct song_node* startOfList, char name[], char artist[]);

struct song_node * find_artist(struct song_node* startOfList, char artist[]);

struct song_node * find_random(struct song_node * list);

struct song_node * remove_song(struct song_node * list, char name[], char artist[]);

struct song_node * free_list(struct song_node * s);
#endif
