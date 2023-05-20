
-- 2D Tetris --

A project by Edouard Clocheret and Louis Pailloncy which is a 2D tetris game using the SDL2 library. Have fun !

This git folder "in104_clocheret_pailloncy" contains :

    - a folder "codes" : codes made by the two students

    - the image bloc_names : it is our reference configuration for the 7 tetris blocks

How to use : 

    - Compile with "make" command while being in the "codes" folder

    - Have fun playing with the ./game command (in the "codes" folder)

Description of the most important functions :

    -Definition of a bloc :
            - def_types_et_vars.h : The minimal definition of blocks is in def_types_et_vars.h We refer to them with the enum "shape" for its shape and the position of the higher left square, and the number of rotations from the reference configuration.

    - The graphics : 
            - initialisation.c initialises the SDL2 library
            
            - pre_render.c is used to display every bloc according to its shape (if it is a I, J, L, Z, O bloc), orientation, and position 

    - Updating the game state :
             - rotation.c updates the game when a rotation is needed
             - the other movements (suh as translations) are more simple and just take a few lines in entree_clavier.c

             - collision.c is a very important function that says if the bloc next position is allowed or not. It calls the function translate_bloc_to_posistions

             - translate bloc_to_positions.c is a function that translate a bloc defined minimally defined as described in def_types_et_vars.h (upper in this README) to the 4 positions that need to be tested. The bloc is either allowed or not to occupy the position, if the position is not empty.

    - The keyboard interactions : 
            - entree_clavier.c Different keys are attributed to actions : 
            Q to rotate the bloc to the left
            D to rotate the bloc to the right
            S to make the bloc fall all the way down

            the right arrow to make a translation to the right
            the left arrow to make a translation to the left

            escape and p to quit the game

            the cross on top of the window also allows to quit the program
    
    - The gaming loop :
            - in main.c which checks if a movement is possible, and successively makes the bloc automatically go down, prompt keyboard entries if the user wants to make an action, render and display the changes.

            -In order to keep in track the positions that are already occupied, those are stored in a matrix with 1, 2,3 ... according to their color or 0 if it is empty. This matrix is really useful to test if a position is allowed or not.



