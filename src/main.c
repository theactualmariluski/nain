/////////////////////////////////////////////////////////////
/////// The Nain programming language compiler //////////////
/////////////////////////////////////////////////////////////
/* This is free and unencumbered software released into the public domain.
The hope to make a better world by colaborating.
Over all now that the software and internet popularity is growing, exponentially,
As of today, this is a work in progress.
*/

#include <stdio.h> // for printing
#include "lexer.h" // for tokenizing

int main() {
    // gets the .nainrc file
    char *file = getFile("$HOME/.nainrc");
    if (file == NULL) {
        printf("No .nainrc file found, making one...\n");
        char defContent[] = "vm_max_instances = 5 \n vm_max_mem = 1024 \n vm_max_cores = 3 \n collect_garbage = true \n";
    }
    return 0;
}

