#include "linkedList.h"
#include "library.h"
#include <stdio.h>

int main() {
    /*struct song_node * s0 = NULL;
    s0 = insert_song(s0, "Africa", "TOTO");
    s0 = insert_song(s0, "Toccata and Fugue in D minor", "Johann Sebastian Bach");
    s0 = insert_song(s0, "Hotel California", "Eagles");
    s0 = insert_song(s0, "Rosanna", "TOTO");
    s0 = insert_song(s0, "Livin' on a Prayer", "Bon Jovi");
    printf("Song list:\n");
    print_list(s0);
    printf("\nThree random songs:\n");
    print_node(find_random(s0));
    print_node(find_random(s0));
    print_node(find_random(s0));
    struct song_node *s1 = find_song(s0,"Africa", "TOTO");
    printf("\nfind song 'Africa':\n\n");
    print_list(s1);
    s1 = find_song(s0,"Hotel California","Eagles");
    printf("\nfind song 'Hotel California': \n\n");
    print_list(s1);
    s1 = find_song(s0,"Hotel Arizona","Eagles");
    printf("\nfind song 'Hotel Arizona': \n\n");
    print_list(s1);
    s1 = find_artist(s0,"TOTO");
    printf("\nfind_artist TOTO: \n\n");
    print_list(s1);
    s1 = find_artist(s0, "Bon Jovi");
    printf("\nfind_artist Bon Jovi: \n\n");
    print_list(s1);
    s1 = find_artist(s0, "Jon Bovi");
    printf("\nfind artist Jon Bovi: \n\n");
    print_list(s1);
    printf("\nremove_song Livin' on a Prayer by Bon Jovi\n\n");
    s0 = remove_song(s0, "Livin' on a Prayer", "Bon Jovi");
    print_list(s0);
    printf("\nremove_song both songs by TOTO\n\n");
    s0 = remove_song(s0, "Africa", "TOTO");
    s0 = remove_song(s0, "Rosanna", "TOTO");
    print_list(s0);
    printf("\nFreeing list, nothing should print below\n");
    s0 = free_list(s0);
    print_list(s0);*/
    struct song_node** library = initialize_library();
    add_song_nodes(library,"havana","camila cabello");
    add_song_nodes(library,"vienna","billy joel");
    add_song_nodes(library,"shape of you","ed sheeran");
    add_song_nodes(library,"piano man","billy joel");
    print_letter(library, 'b');
    print_letter(library, 'c');
    print_letter(library, 'z');
    printf("Shuffle 10 songs:\n");
    shuffle(library, 10);
    /*
    lib_remove_song(library, "vienna man", "billy joel");
    print_letter(library, 'b');
    lib_remove_song(library,"vienna", "billy joel");
    print_letter(library, 'b');
    lib_remove_song(library, "piano man", "billy joel");
    print_letter(library, 'b');
    */
    return 0;
}
