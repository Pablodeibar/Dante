
# Dante

The goal of this project is to create a solver and a generator of maze.


## Description 📜

What is a maze:
- Mazes are rectangular.
- They are coded in ASCII.
- The ‘X’s represent the walls and the’*’s represent the free spaces.
- It is possible to move to the four surrounding squares (up, down, right, left).
- “Start” is in the upper left-hand corner (0;0)
- “Finish” is in the bottom right-hand corner.
- A solution is a series of free, adjacent squares, from “Start” to “Finish” included.
- “Start” and “Finish” can be occupied. In this case, there is no solution.
- The last line of the maze doesn’t terminate with a return line.
- Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path.

During this project we only had the right to some functions that are the system functions and libC, but no external libraries.


For the generator there were 2 forms of creation. Perfect and imperfect mazes. Perfect mazes are mazes that have only one possible path.


![Alt text](image/perfect.png?raw=true "Title")


Imperfect mazes are mazes who have several paths to get to the end, this is often due to islands, or simply because there are several possible paths.


![Alt text](image/imperfect.png?raw=true "Title")

To create a maze we had to choose its size and if it's a perfect like that.
If perfect is not indicated then the maze will be imperfect.

```bash
  ./generator/generator x y [perfect]
```

![Alt text](image/example.png?raw=true "Title")


To solve the maze you have to do like this.


```bash
  ./solver/solver maze.txt
```

![Alt text](image/example2.png?raw=true "Title")

## Installation 🔌

Install my_rpg

```bash
  git clone git@github.com:Pablodeibar/Dante.git
  cd Dante
  make
```
    