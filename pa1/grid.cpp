    #include "grid.h"
    #include "grid_given.cpp"

    // PA1 functions


    /**
     * Destroys the current Grid. This function should ensure that
     * memory does not leak on destruction of a grid.
     */
    Grid::~Grid(){ /*your code here*/

        clear();

    }

    /**
     * Rotate row r (row 0 is the first) by count positions.
     * If row r is ABCDE (left to right) in grid g then row r
     * in grid g should be DEABC after the call g.rotateR(r, 2).
     * Rotate headOfCol_ if necessary.
     */
    void Grid::rotateR(int r, int count) { /* your code here */

    }

    /**
     * Rotate column c (column 0 is the first) by count positions.
     * If column c is ABCDE (top to bottom) in grid g then column c
     * in grid g should be DEABC after the call g.rotateC(c, 2).
     * Rotate headOfRow_ if necessary.
     */
    void Grid::rotateC(int c, int count) { /* your code here */

    }


    /**
     * Destroys all dynamically allocated memory associated with the
     * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
     * Sets bwidth_, bheight_ to zero.
     * After clear() the grid represents an empty grid.
     */
    void Grid::clear() { /*your code here*/
    //
    //    std::function void deleteNext = [](Node current) {
    //        if (current->*down != NULL) {
    //            deleteNext(current->*down);
    //        }
    //        delete current;
    //    }
    //
    //    for (int i = 0; i < numCols(); i++) {
    //        Node temp = headOfCol_[i];
    //        deleteNext(temp);
    //    }
    }



    /**
     * Makes the current Grid a copy of the "other" Grid.
     * The dimensions should be the same.  The Nodes should
     * contain the same blocks, but the Nodes should be newly
     * allocated. This function is used in both the copy
     * constructor and the assignment operator for Grids.
     */
    void Grid::copy(Grid const& other) { /*your code here*/

    }


    Node * getNthNode(string direction, int steps, const Node * current) {
            if (steps == 0) {
                return current;
            }
            if (direction == "up") {
                return getNthNode(direction, steps - 1, current->up);
            }
            if (direction == "down") {
                return getNthNode(direction, steps - 1, current->down);
            }
            if (direction == "left") {
                return getNthNode(direction, steps - 1, current->left);
            }
            if (direction == "right") {
                return getNthNode(direction, steps - 1, current->right);
            }
    }