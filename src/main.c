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
    getTokens("let foo = 10\n \
              let bar = 20\n \
              fn main() { \n \
                  let x = foo + bar \n \
                  print!(x) \n \
              } \
    ");

}

