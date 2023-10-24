#include "linkedList.h"
#include <stdio.h>

int main() {
    struct song_node * s0 = NULL;
    s0 = insert_song(s0, "Africa", "TOTO");
    s0 = insert_song(s0, "Toccata and Fugue in D minor", "Johann Sebastian Bach");
    s0 = insert_song(s0, "Hotel California", "Eagles");
    s0 = insert_song(s0, "Rosanna", "TOTO");
    s0 = insert_song(s0, "Livin' on a Prayer", "Bon Jovi");
    //printf("done");
    fflush(stdout);
    print_list(s0);
    return 0;
}