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
            while (nPlusOne -> down != NULL) {
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
            while (nPlusOne -> right != NULL) {
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

        //if it's first row fix all the head pointers
        if (r == 0) {
            for (Node* x: headOfCol_) {
                Node* correct = x;
                for (int i=0; i < count; i++) {
                    correct = correct->left;
                } 
                x = correct;       
            }
        }
        Node* curr = headOfRow_.at(r);
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
        Node* newhead = headOfRow_.at(r);
        for (int i=0; i < count; i++) {
            newhead = newhead->left;
        } 
        headOfRow_.at(r) = newhead;
    }

    /**
     * Rotate column c (column 0 is the first) by count positions.
     * If column c is ABCDE (top to bottom) in grid g then column c
     * in grid g should be DEABC after the call g.rotateC(c, 2).
     * Rotate headOfRow_ if necessary.
     */
    void Grid::rotateC(int c, int count) {

        //if it's first column fix all the head pointers
        if (c == 0) {
            for (Node* x: headOfRow_) {
                Node* correct = x;
                for (int i=0; i < count; i++) {
                    correct = correct->up;
                } 
                x = correct;       
            }
        }
        Node* curr = headOfCol_.at(c);
        Node* currright;
        Node* currleft;
        for (int i=0; i < numRows(); i++) {
            // for the right pointers
            currright = curr->right;
            for (int i=0; i < count; i++) {
                currright = currright->down;
            }
            curr->right = currright;
            currright->left = curr;

            // for the left pointers
            currleft = curr->left;
            for (int i=0; i < count; i++) {
                currleft = currleft->down;
            }
            curr->left = currleft;
            currleft->right = curr;

            curr = curr->down;
        }

        // point column head to new head
        Node* newhead = headOfCol_.at(c);
        for (int i=0; i < count; i++) {
            newhead = newhead->up;
        } 
        headOfCol_.at(c) = newhead;

    }


    /**
     * Destroys all dynamically allocated memory associated with the
     * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
     * Sets bwidth_, bheight_ to zero.
     * After clear() the grid represents an empty grid.
     */
    
    void Grid::clear() { 

    for (Node *n : headOfRow_)
        delete n;
    for (Node *n : headOfCol_)
        delete n;
    headOfRow_.clear();
    headOfCol_.clear();
    bwidth_ = 0;
    bheight_ = 0;
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