#include "linkedList.h"
#include <stdio.h>

int main() {
    struct song_node * s0 = NULL;
    s0 = insert_front(s0, "Africa", "TOTO");
    s0 = insert_front(s0, "Hotel California", "Eagles");
    s0 = insert_front(s0, "Toccata and Fugue in D minor", "Johann Sebastian Bach");
    print_list(s0);
    return 0;
}