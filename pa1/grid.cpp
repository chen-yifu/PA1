    #include "grid.h"
    #include "grid_given.cpp"

    // PA1 functions


    /**
     * Destroys the current Grid. This function should ensure that
     * memory does not leak on destruction of a grid.
     */
Grid::~Grid(){
	clear();

}

    /**
     * Rotate row r (row 0 is the first) by count positions.
     * If row r is ABCDE (left to right) in grid g then row r
     * in grid g should be DEABC after the call g.rotateR(r, 2).
     * Rotate headOfCol_ if necessary.
     */
void Grid::rotateR(int r, int count) { 
	r = r % numRows();

	//if it's first column fix all the head pointers
		if (r == 0) {
			for (int i = 0; i < numCols(); i++) {
				Node* correct = headOfCol_[i];
				for (int i=0; i < count; i++) {
					correct = correct->left;
				} 
				headOfCol_[i] = correct;
			}
		}
    // store neighbor nodes in two vectors

		vector<Node *> upperNeighbors;
		vector<Node *> lowerNeighbors;
		Node * curr = headOfRow_[r];
		for (int i = 0; i < numCols(); i++) {
			upperNeighbors.push_back(curr->up);
			lowerNeighbors.push_back(curr->down);
			curr = curr->right;
		}


    // modify pointers of upperNeighbors, lowerNeighbors, and rotated row
		curr = headOfRow_[r];
		for (int i = 0; i < numCols(); i++) {
			curr->up   = upperNeighbors[(i + count) % numCols()];
			curr->down = lowerNeighbors[(i + count) % numCols()];
			upperNeighbors[(i + count) % numCols()]->down = curr;
			lowerNeighbors[(i + count) % numCols()]->up   = curr;
			curr = curr->right;
		}
		curr = headOfRow_[r];
		for (int i = 0; i < count; i++) {
			curr = curr-> left;
		}
		headOfRow_[r] = curr;
		upperNeighbors.clear();
		lowerNeighbors.clear();


  // --------------------------Evan's code-----------------------------
     //if it's first row fix all the head pointers

  // }
  // Node* curr = headOfRow_.at(r);
  // Node* currdown;
  // Node* currup;
  // for (int i=0; i < numCols(); i++) {
  //           // for the upper pointers
  //   currdown = curr->down;
  //   for (int i=0; i < count; i++) {
  //     currdown = currdown->right;
  //   }
  //   curr->down = currdown;
  //   currdown->up = curr;

  //           // for the below pointers
  //   currup = curr->up;
  //   for (int i=0; i < count; i++) {
  //     currdown = currdown->right;
  //   }
  //   curr->up = currup;
  //   currup->down = curr;

  //   curr = curr->right;
  // }

  //       // point column head to new head
  // Node* newhead = headOfRow_.at(r);
  // for (int i=0; i < count; i++) {
  //   newhead = newhead->left;
  // } 
  // headOfRow_.at(r) = newhead;
	}

    /**
     * Rotate column c (column 0 is the first) by count positions.
     * If column c is ABCDE (top to bottom) in grid g then column c
     * in grid g should be DEABC after the call g.rotateC(c, 2).
     * Rotate headOfRow_ if necessary.
     */
	void Grid::rotateC(int c, int count) {

		c = c % numCols();

        //if it's first column fix all the head pointers
		if (c == 0) {
			for (int i = 0; i < numRows(); i++) {
				Node* correct = headOfRow_[i];
				for (int i=0; i < count; i++) {
					correct = correct->up;
				} 
				headOfRow_[i] = correct;
			}
		}

		// store neighbor nodes in two vectors

		vector<Node *> leftNeighbors;
		vector<Node *> rightNeighbors;
		Node * curr = headOfCol_[c];
		for (int i = 0; i < numRows(); i++) {
			leftNeighbors.push_back(curr->left);
			rightNeighbors.push_back(curr->right);
			curr = curr->down;
		}


    // modify pointers of upperNeighbors, lowerNeighbors, and rotated row
		curr = headOfCol_[c];
		for (int i = 0; i < numRows(); i++) {
			curr->left   = leftNeighbors[(i + count) % numRows()];
			curr->right = rightNeighbors[(i + count) % numRows()];
			leftNeighbors[(i + count) % numRows()]->right   = curr;
			rightNeighbors[(i + count) % numRows()]->left   = curr;
			curr = curr->down;
		}
		curr = headOfCol_[c];
		for (int i = 0; i < count; i++) {
			curr = curr->up;
		}
		headOfCol_[c] = curr;
		leftNeighbors.clear();
		rightNeighbors.clear();



  // --------- Evan's Code --------------  
  // }
  // Node* curr = headOfCol_.at(c);
  // Node* currright;
  // Node* currleft;
  // for (int i=0; i < numRows(); i++) {
  //           // for the right pointers
  //   currright = curr->right;
  //   for (int i=0; i < count; i++) {
  //     currright = currright->down;
  //   }
  //   curr->right = currright;
  //   currright->left = curr;

  //           // for the left pointers
  //   currleft = curr->left;
  //   for (int i=0; i < count; i++) {
  //     currleft = currleft->down;
  //   }
  //   curr->left = currleft;
  //   currleft->right = curr;

  //   curr = curr->down;
  // }

  //       // point column head to new head
  // Node* newhead = headOfCol_.at(c);
  // for (int i=0; i < count; i++) {
  //   newhead = newhead->up;
  // } 
  // headOfCol_.at(c) = newhead;

		}


    /**
     * Destroys all dynamically allocated memory associated with the
     * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
     * Sets bwidth_, bheight_ to zero.
     * After clear() the grid represents an empty grid.
     */
    void Grid::clear() { /*your code here*/
    // cout << __LINE__ << endl;

	for (int x = 0; x < numRows(); x++) {
		// cout << x << "x" << endl;
		// cout << numCols() << endl;
		Node* next = headOfRow_.at(x);
		for (int j = 0; j < numCols(); j++) {
			Node* temp = next;

				next = next->right;
	
			delete(temp);
		}
	}

	headOfRow_.clear();
	headOfCol_.clear();
	bwidth_ = 0;
	bheight_ = 0;
	// cout << __LINE__ << endl;
}



    /**
     * Makes the current Grid a copy of the "other" Grid.
     * The dimensions should be the same.  The Nodes should
     * contain the same blocks, but the Nodes should be newly
     * allocated. This function is used in both the copy
     * constructor and the assignment operator for Grids.
     */
void Grid::copy(Grid const& other) {

	int nRows = other.numRows();
	int nCols = other.numCols();

  // Set up a temporary two-dimensional vector of ptrs to Nodes containing
  // the correct sub-blocks of the image.
  vector < vector < Node * > > A;
  int i = 0;
  for( int j=0; j<nRows; j++ ) {
    vector < Node * > temp;
	Node* row = headOfRow_.at(i);
	i = i + 1;
	Node* col = row;
    for( int i=0; i<nCols; i++ ) {
      Node* p = new Node(col->block);
	  col = col -> down;
      temp.push_back(p);
    }
    A.push_back(temp);
  }
  // Set up the pointer structure between Nodes
  for( int j=0; j<nRows; j++ ) {
    for( int i=0; i<nCols; i++ ) {
      Node *p = A[j][i];
      // The following uses the C++ conditional operator
      // (also known as the C ternary operator):
      //
      // (condition) ? (if_true) : (if_false)
      //
      // which has the value if_true if the condition is true
      // and has the value if_false otherwise.
      p->up    = A[(j==0) ? nRows-1 : j-1] [i]; 
      p->down  = A[(j==nRows-1) ? 0 : j+1][i];
      p->left  = A[j] [(i==0) ? nCols-1 : i-1];
      p->right = A[j] [(i==nCols-1) ? 0 : i+1];
    }
  }
  for( int j=0; j<nRows; j++ ) {
    headOfRow_.push_back(A[j][0]);
  }
  for( int i=0; i<nCols; i++ ) {
    headOfCol_.push_back(A[0][i]);
  }
}