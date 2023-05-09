#include "def_types_et_vars.h"

// argument -1 pour une rotation vers la gauche
//argument +1 pour une rotation vers la droite

void rotation (int sens, bloc* falling_meteor){
    //on met à jour les coordonnées du coin en haut à gauche (avant le nombre de rotations)

    switch(falling_meteor->son_nom){
    case I:
        if (sens == -1){
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                falling_meteor->x=falling_meteor->x+1;
                falling_meteor->y=falling_meteor->y-1;
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                falling_meteor->x=falling_meteor->x-1;
                falling_meteor->y=falling_meteor->y+1;
            }
        }
            

        if (sens == 1){
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                falling_meteor->x=falling_meteor->x+2;
                falling_meteor->y=falling_meteor->y-1;
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                falling_meteor->x=falling_meteor->x-2;
                falling_meteor->y=falling_meteor->y+1;
            }
        }
    break;
        

        //revoir à partir de là

    case T:
        if (sens == -1){
            if (falling_meteor->rotation==0){
                falling_meteor->x=falling_meteor->x+1;
                falling_meteor->y=falling_meteor->y-1;
            }
            if (falling_meteor->rotation==1){
                falling_meteor->y=falling_meteor->y-1;
            }
            // if falling_meteor->rotation==2 do nothing
            // if falling_meteor->rotation==3 do nothing
        }
            

        if (sens == 1){
            if (falling_meteor->rotation==0||falling_meteor->rotation==2){
                falling_meteor->x=falling_meteor->x+2;
                falling_meteor->y=falling_meteor->y-1;
            }
            if (falling_meteor->rotation==1||falling_meteor->rotation==3){
                falling_meteor->x=falling_meteor->x-2;
                falling_meteor->y=falling_meteor->y+1;
            }
        }
    break;
    default : //rotation du O, la plus simple
    break;
}
    //on met à jour le nombre de rotation du bloc
    if (sens == -1){
        falling_meteor->rotation=(falling_meteor->rotation-1)%4;
    }
    if (sens == 1){
        falling_meteor->rotation=(falling_meteor->rotation+1)%4;
    }
    


}

//redéfinir le carreau en bas à droite pour avoir des belles rotations