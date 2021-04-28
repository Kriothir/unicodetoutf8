#include "pretvori.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {




    int test = preberiVhod(argv);
    int new = pretvoriZnak(test);
    izpisiZnak(new);

    return 0;

}
