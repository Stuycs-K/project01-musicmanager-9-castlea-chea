#include "linkedList.h"
#include <stdio.h>

int main() {
    struct song_node * s0 = NULL;
    s0 = insert_song(s0, "Africa", "TOTO");
    s0 = insert_song(s0, "Toccata and Fugue in D minor", "Johann Sebastian Bach");
    s0 = insert_song(s0, "Hotel California", "Eagles");
    s0 = insert_song(s0, "Rosanna", "TOTO");
    s0 = insert_song(s0, "Livin' on a Prayer", "Bon Jovi");
    print_list(s0);
    struct song_node *s1 = find_song(s0,"Africa", "TOTO");
    printf("\nfind song 'Africa':\n\n");
    print_list(s1);
    s1 = find_song(s0,"Hotel California","Eagles");
    printf("\nfind song 'Hotel California': \n\n");
    print_list(s1);
    s1 = find_artist(s0,"TOTO");
    printf("\nfind_artist TOTO: \n\n");
    print_list(s1);
    s1 = find_artist(s0, "Bon Jovi");
    printf("\nfind_artist Bon Jovi: \n\n");
    print_list(s1);
    s0 = free_list(s0);
    print_list(s0);
    return 0;
}
