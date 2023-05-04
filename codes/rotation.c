#include "def_types_et_vars.h"

// argument -1 pour une rotation vers la gauche
//argument +1 pour une rotation vers la droite

void rotation (int sens, bloc* falling_meteor){
    if (sens == -1){
        falling_meteor->rotation=(falling_meteor->rotation-1)%4;
    }
    if (sens == 1){
        falling_meteor->rotation=(falling_meteor->rotation+1)%4;
    }
}

//redéfinir le carreau en bas à droite pour avoir des belles rotations