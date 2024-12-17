#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;


/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */

template <typename Comparable>
class BST
{
public:
	BST();
	~BST();

	const Comparable & findMin() const;
	const Comparable & findMax() const;

	bool contains(const Comparable & x) const;
	bool isEmpty() const;
	// void printTree( ostream & out = cout ) const;
	void printInOrder() const;
	void printLevels() const;
	int treeSize() const;
	int treeHeight() const;
	void printMaxPath() const;
	double averageInternalPathLength() const;
	void removeByRank(int rank);

	void makeEmpty();
	void insert(const Comparable & x);
	void remove(const Comparable & x);


private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt): element(theElement), left(lt), right(rt) {}
		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt): element(move(theElement)), left(lt), right(rt) {}
	};

	BinaryNode *root;

	void insert( const Comparable & x, BinaryNode * & t);
	void insert( Comparable && x, BinaryNode * & t);
	void remove( const Comparable & x, BinaryNode * & t);
	BinaryNode * findMin( BinaryNode * t ) const;
	BinaryNode * findMax( BinaryNode * t ) const;

	bool contains( const Comparable & x, BinaryNode *t ) const;
	void makeEmpty( BinaryNode * & t );
	void printInOrder( BinaryNode * t ) const;
	void printLevels( BinaryNode * t) const;
	// BinaryNode * clone( BinaryNode * t ) const;
	int treeSize( BinaryNode * t ) const;
	int treeHeight( BinaryNode * t ) const;
	void printMaxPath( BinaryNode * t ) const;
	int sumInternalPaths(BinaryNode * t, int depth) const;
	double averageInternalPathLength(BinaryNode * t) const;
	void readInOrder(BinaryNode * t, vector<BinaryNode*> & readNodes) const;
};


/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */

// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(NULL) {}

// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
	makeEmpty();
}

// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// // public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMin(root)->element;
}

// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
    if (root == NULL) {
    	throw underflow_error("Tree is empty");
	}
    return findMax(root)->element;
}

// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x ) const {
	return contains(x, root);
}

// private recursive contains: refer to textbook, Figure 4.18
template<typename Comparable>
bool BST<Comparable>::contains( const Comparable & x, BinaryNode *t) const {
	if ( t == NULL ) 
		return false;
	else if ( x < t->element ) // should go to left subtree
		return contains( x, t->left );
	else if ( t-> element < x ) // should go to right subtree
		return contains( x, t->right );
	else
		return true; // Match
}

// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x) {
	insert(x, root);
}

// private recursive insert: refer to textbook, Figure 4.23, Line 7 - 17
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x, BinaryNode * & t) {
	if ( t == NULL )   // empty BST
		t = new BinaryNode(x, NULL, NULL);
	else if ( x < t->element )   // should go to left subtree
		insert( x, t->left );
	else if ( x > t->element )   // should go to right subtree
		insert( x, t->right );
	else
		; // duplicate; do nothing
}

// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x ) {
	remove(x, root);
}

// private recurive remove: refer to textbook, Figure 4.26
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x, BinaryNode* & t) {
	if (t == NULL)
		return;

	if ( x < t->element ) { // should go to left
		remove( x, t->left );
	}
	else if ( t->element < x ) { // should go to right
		remove( x, t->right );
	}
	else if ( t->left != NULL && t->right != NULL) { // Case 2: (t->element == x) and (t has two children) 
		t->element = findMin(t->right)->element; // action 1: replace t with the value of the minimal successor from right subtree
		remove(t->element, t->right);            // action 2: delete this value from right subtree
	}
	else { // Case 1: (t->element == x) and (t has 0 or 1 child), attach one child and directly remove this node
		BinaryNode* oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldNode;
	}
}

// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize() const {
	return treeSize(root);
}

// private recursive treeSize
template <typename Comparable>
int BST<Comparable>::treeSize(BinaryNode* t) const {
    if (t == NULL) {
        return 0; // empty BST
    }
    return 1 + treeSize(t->left) + treeSize(t->right); // 1 (count the current node) + count_from_left + count_from_right
}

// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight() const {
	return treeHeight(root);
}

// private recursive treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight(BinaryNode* t) const {
    if (t == NULL) {
        return -1; // empty BST
    }
    int leftHeight = treeHeight(t->left);
    int rightHeight = treeHeight(t->right);
    return 1 + max(leftHeight, rightHeight);
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const {
	printInOrder(root);
	cout << "</s>";
}

// private recursive printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder(BinaryNode* t) const {
	if ( t != NULL ) {
		printInOrder(t->left);
		cout << t->element << " -> ";
		printInOrder(t->right);
	}
}

// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
	printLevels(root);
}


// private printLevels
template <typename Comparable>
void BST<Comparable>::printLevels(BinaryNode * t) const {
    if (t == NULL) { // empty BST
        return; 
    }

    queue<BinaryNode*> q;
    q.push(t);

    int indexLevel = 0;
    while (!q.empty()) {
        int levelSize = q.size(); // # of nodes in the current level

        cout << "Level " << indexLevel << ": ";
        // traversal on the current level
        for (int i = 0; i < levelSize; ++i) {
            BinaryNode* current = q.front();
            q.pop();
            cout << current->element << " ";

            // push nodes in the next level into the queue
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << endl; 
        indexLevel ++;
    }
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath() const {
	printMaxPath(root);
	cout << "</s>";
}

// private printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath(BinaryNode* t) const {
    if (t == NULL) {
        return; // empty BST
    }

    cout << t->element << " -> ";

    // recursive heights from left and right subtrees
    int leftHeight = treeHeight(t->left);
    int rightHeight = treeHeight(t->right);
    if (leftHeight > rightHeight)
    	printMaxPath(t->left);
    else
    	printMaxPath(t->right);
}

// private recursive averageInternalPathLength
template <typename Comparable>
int BST<Comparable>::sumInternalPaths(BinaryNode * t, int depth) const {
    if (t == NULL) {
        return 0;
    }
    return depth + sumInternalPaths(t->left, depth + 1) + sumInternalPaths(t->right, depth + 1);
}

// public averageInternalPathLength
template <typename Comparable>
double BST<Comparable>::averageInternalPathLength() const {
	return averageInternalPathLength(root);
}

// private averageInternalPathLength
template <typename Comparable>
double BST<Comparable>::averageInternalPathLength(BinaryNode * t) const {
    if (root == NULL) {
        return 0.0;
    }
    int totalNodes = treeSize(t);
    int totalPathLength = sumInternalPaths(t, 0); 
    return static_cast<double>(totalPathLength) / totalNodes;
}

// private readInOrder
template <typename Comparable>
void BST<Comparable>::readInOrder(BinaryNode * t, vector<BinaryNode*> & readNodes) const {
    if (t == NULL) 
    	return;
    readInOrder(t->left, readNodes);
    readNodes.push_back(t);
    readInOrder(t->right, readNodes);
}

// public removeByRank
template <typename Comparable>
void BST<Comparable>::removeByRank(int rank) {
    vector<BinaryNode*> nodes;
    readInOrder(root, nodes);

    if (rank < 1 || rank > nodes.size()) {
        cout << "Invalid rank: " << rank << endl;
        return;
    }

    BinaryNode* nodeToDelete = nodes[rank - 1]; 
    remove(nodeToDelete->element);

}

#endif
