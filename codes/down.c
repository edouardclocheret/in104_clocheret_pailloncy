#include "def_types_et_vars.h"
//fonction gerant la chute du bloc

void down (bloc* falling_meteor){
    while /*not colllision (a programmer) */{
        falling_meteor->y=falling_meteor->y-1;
    }
}