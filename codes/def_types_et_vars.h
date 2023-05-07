
#define taille_carreau 50

//A name is given to each tetris bloc
enum shape {I, O, T, L, J, Z, S};

//Refer to bloc_names.png to see every bloc in its default/reference configuration
typedef struct bloc {
    enum shape son_nom;
    //position of the most left and high sub-bloc (including empty spaces)
    int x;
    int y;
    //number of clockwise rotations from the default configuration
    int rotation;
} bloc ;
