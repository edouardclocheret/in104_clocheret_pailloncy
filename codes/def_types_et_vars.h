
#define taille_carreau 50
#define dy 50

//A name is given to each tetris bloc
enum nom {I, O, T, L, J, Z, S};

//Refer to bloc_names.png to see every bloc in its default/reference configuration
typedef struct bloc {
    enum nom son_nom;
    //position of the most right and down sub-bloc (including empty spaces)
    int x;
    int y;
    //number of clockwise rotations from the default configuration
    int rotation;
} bloc ;
