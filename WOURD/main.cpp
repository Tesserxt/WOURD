#include <iostream>
#include "WORD.h"

int main() {
   
    WORD w;
    while (!w.isGameOver())
    {
        w.fetch_word();
        w.mask_word();
        w.take_input();
        w.verify_input();
    
    }
    return 0;
}
