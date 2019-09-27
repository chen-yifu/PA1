    #include "grid.h"
    #include "grid_given.cpp"

    // PA1 functions


    /**
     * Destroys the current Grid. This function should ensure that
     * memory does not leak on destruction of a grid.
     */
    Grid::~Grid(){
        for (Node* x: headOfCol_) {
            Node* n = x;
            x = NULL;
            Node* nPlusOne = n->down;
            n->down = NULL;
            nPlusOne->up = NULL;
            while (nPlusOne -> down != nullptr) {
                n = nPlusOne;
                nPlusOne = n->down;
                n->down = NULL;
                nPlusOne->up = NULL;
            }                     
        } 
        for (Node* x: headOfRow_) {
            Node* n = x;
            x = NULL;
            Node* nPlusOne = n->right;
            delete n;
            n->right = NULL;
            nPlusOne->left = NULL;
            while (nPlusOne -> right != nullptr) {
                n = nPlusOne;
                nPlusOne = n->right;
                delete n;
                n->right = NULL;
                nPlusOne->left = NULL;
            }
        }  
    }

    /**
     * Rotate row r (row 0 is the first) by count positions.
     * If row r is ABCDE (left to right) in grid g then row r
     * in grid g should be DEABC after the call g.rotateR(r, 2).
     * Rotate headOfCol_ if necessary.
     */
    void Grid::rotateR(int r, int count) { 
        r = r % numRows();
        if (r == 0) {
            for (Node* x: headOfCol_) {
                Node* correct = x;
                for (int i=0; i < count; i++) {
                    correct = correct->left;
                } 
                x = correct;       
            }
        }
        Node* curr = headOfCol_.at(r);
        Node* currdown;
        Node* currup;
        for (int i=0; i < numCols(); i++) {
            // for the upper pointers
            currdown = curr->down;
            for (int i=0; i < count; i++) {
                currdown = currdown->right;
            }
            curr->down = currdown;
            currdown->up = curr;

            // for the below pointers
            currup = curr->up;
            for (int i=0; i < count; i++) {
                currdown = currdown->right;
            }
            curr->up = currup;
            currup->down = curr;

            curr = curr->right;
        }

        // point column head to new head
        Node* newhead = headOfCol_.at(r);
        for (int i=0; i < count; i++) {
            newhead = newhead->left;
        } 
        headOfCol_.at(r) = newhead;
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
    Grid * newGrid = new Grid(*other->render(),other->bheight_, other->bwidth_)

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