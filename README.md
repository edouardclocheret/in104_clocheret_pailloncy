
-- 2D Tetris --

A project by Edouard Clocheret and Louis Pailloncy aiming at creating a 2D tetris game using the SDL2 library


This git folder "in104_clocheret_pailloncy" contains :

    - a folder "src" : templates

    - a folder "codes" : codes made by the two students

    - the image bloc_names : it is our reference configuration for the 7 tetris blocks

How to use : 

    - Compile with "make game" command while being in the "codes" folder

Project state :

    - The definition of blocks is in def_types_et_vars.h We refer to them with the enum "shape" for its shape and the position of the lower right square, and the umber of rotations from the reference configuration.

    - We are working on the actions that the user makes using the keybord : down.c rotation.c 

    - The graphics : initialisation.c update_render.c

    - The keyboard interactions : entree_clavier.c





