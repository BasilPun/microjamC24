/******************    basic game framework    *********************/
you are a fish

you move with dpad directionally

(possible _a boost? or iframes XD)

you are attempting to eat a number of food determined by difficulty (3, 5, 5)

fishing hooks come down and the player must avoid them
the hooks will swing using logic simmilar to orbiter

the number of hooks will increase depending on difficulty (1, 1, 3)

/******************    class framework    *********************/

entity is anything onscreen
    it stores sprite object as well as bounding box

player class child of entity 
    controls movement and ability

food class child of entity
    spawns, potentially moves, sends score to win condtiion check

hook class child of entity
    spawns, swings, sends loss condition, physics of how to move, possible line connected

scoreboard-ish
    controls counter for win condition (hot persuit implementation)

possible food manager
    deterimines spawn

possible hook manager
    determines where hook drops

background class?
    puts a backdrop

bubble class child of entity
    makes the background look dynamic
