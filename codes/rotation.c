#include "def_types_et_vars.h"


// argument -1 pour une rotation vers la gauche
//argument +1 pour une rotation vers la droite

void rotation (int sens, bloc* falling_meteor){

    falling_meteor->rotation=((falling_meteor->rotation+sens)+4)%4;

}