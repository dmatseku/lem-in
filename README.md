# lem-in #

42 School project.

This project about an ant farm.
The goal of this program is to find the best solution to transfer all ants from the start room to the end.

## Compilation ##

Clone this repository.

There are two ways to compile: with cmake and with make.
All compilation commands need to execute in the root repository folder.

Run with cmake (recommended):

    mkdir build && cd build
    cmake ../
    make
  
Or run with make:

    make

## Usage ##

### Basic execute ###
Program accept file in standard input.
So, you can transfer the file via '<' or through the pipeline:

    ./lem-in < *path to file*
    cat *path to file* | ./lem-in

### Flags ###

The program has 6 flags:
* -help - print flag information
* -color - print all in colors
* -last - print the last line in the file, if it is a comment
* -p - print all the paths
* -r - print the number of rooms
* -c - print the number of my lines

## Syntax ##

### Form ###

The input file should be in this form:

    number_of_ants
    room
    ...
    link
    ...

First line is a number of ants.

Next lines are rooms in next format:

    room_name x_coord y_coord
    
Coordinates were not needed for me.

Last lines are links in next format:

    room_name-room_name

### Comments ###

The file can contain comments anywhere except after commands.
Comment starts at '#'.

### Commands ###

Commands give features the following line. They start at '##'.
Undefined commands are understood as comments.
There are two commands: '##start' and '##end', which mark a room as start_room or end_room.

### Example ###

    #comment
    200
    0 0 0
    ##start
    start 1 1
    2 2 2
    #comment
    3 3 3
    ##end
    end 4 4
    5 5 5
    start-0
    start-2
    2-3
    0-3
    #comment
    3-5
    3-end
    #comment

## Output ##

Each ant in one step can walk no more than once. 1 line - 1 step.
The step of each ant is separated by a comma and space.
The record of the ant’s step looks like this:

    L(ant number)-(room name)
