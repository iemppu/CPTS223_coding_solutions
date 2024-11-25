

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


template <typename Comparable>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void makeEmpty();
    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;
    int computeHeight() const;
    int readRootHeight() const;
    bool isBalanced() const;
    bool isBST() const;

    double averageDepth() const;

    // void removeRandomNode();
    void removeByRank(int rank);

    // the next line follows textbook Figure 4.42, Line 19
    static const int ALLOWED_IMBALANCE = 1;

    void printMaxPath() const;
private:
    struct AVLNode  // refer to textbook, Figure 4.40
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt ): element(theElement), left(lt), right(rt) {}
        AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt ): element(move(theElement)), left(lt), right(rt) {}
    };

    AVLNode *root;

    void insert( const Comparable & x, AVLNode * & t);
    void insert( Comparable && x, AVLNode * & t);
    void remove( const Comparable & x, AVLNode * & t);
    void balance( AVLNode * & t );
    bool isBalanced(AVLNode *t) const;
    int height(AVLNode * t) const;
    void rotateWithLeftChild( AVLNode * & t );
    void rotateWithRightChild( AVLNode * & t );
    void doubleWithLeftChild( AVLNode * & t);
    void doubleWithRightChild( AVLNode * & t);
    AVLNode * findMin( AVLNode * t ) const;
    AVLNode * findMax( AVLNode * t ) const;

    bool contains( const Comparable & x, AVLNode *t ) const;
    void makeEmpty( AVLNode * & t );
    int treeSize( AVLNode * t ) const;
    int computeHeight( AVLNode * t ) const;
    int sumDepth(AVLNode * t, int depth) const;
    double averageDepth(AVLNode * t) const;
    void readInOrder(AVLNode * t, vector<AVLNode*> & readNodes) const;
    bool isBST(AVLNode* t, Comparable min, Comparable max) const;

    void printMaxPath( AVLNode * t ) const;
};


// public printMaxPath
template <typename Comparable>
void AVLTree<Comparable>::printMaxPath() const {
    printMaxPath(root);
    cout << "</s>";
}

// private printMaxPath
template <typename Comparable>
void AVLTree<Comparable>::printMaxPath(AVLNode* t) const {
    if (t == NULL) {
        return; // empty BST
    }

    cout << t->element << " -> ";

    // recursive heights from left and right subtrees
    int leftHeight = computeHeight(t->left);
    int rightHeight = computeHeight(t->right);
    if (leftHeight > rightHeight)
        printMaxPath(t->left);
    else
        printMaxPath(t->right);
}

// constructor
template <class Comparable>
AVLTree<Comparable>::AVLTree() : root(NULL) {}

// destructor
template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

// public makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode * & t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// public findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}

// private findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMin(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMax() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element;
}

// private findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMax(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// public contains: follow the contains in BST, referring to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x ) const {
    return contains(x, root);
}

// private recursive contains: follow the contains in BST, referring to textbook, Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x, AVLNode *t) const {
    if ( t == NULL ) 
        return false;
    else if ( x < t->element ) // should go to left subtree
        return contains( x, t->left );
    else if ( t-> element < x ) // should go to right subtree
        return contains( x, t->right );
    else
        return true; // Match
}

// public insert: following BST, referring to textbook, Figure 4.42
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x) {
    insert(x, root);
}

// private recursive insert: following BST, referring to textbook, Figure 4.42
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x, AVLNode * & t) {
    if ( t == NULL )   // empty BST
        t = new AVLNode(x, NULL, NULL);
    else if ( x < t->element )   // should go to left subtree
        insert( x, t->left );
    else if ( x > t->element )   // should go to right subtree
        insert( x, t->right );
    
    balance( t );
}

// private balance: refer to textbook, Figure 4.42, Line 21 - 40
// assume t is the node that violates the AVL condition, and we then identify which case to use (out of 4 cases)
template<typename Comparable>
void AVLTree<Comparable>::balance(AVLNode * & t) {
    if ( t == NULL )
        return;

    if ( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE ) { // violation: heigth(left subtree) - heigth(right subtree) > 1
        if ( height( t->left->left ) >= height( t->left->right ) ) // case 1, see Figure 4.34 in textbook
            rotateWithLeftChild( t );
        else // case 2: height( t->left->left ) < height( t->left->right ), see Figure 4.38 in textbook
            doubleWithLeftChild( t );
    }
    else if ( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ) { // violation: heigth(right subtree) - heigth(left subtree) > 1
        if ( height( t->right->right ) >= height( t->right->left ) ) // case 4, see Figure 4.36 in textbook
            rotateWithRightChild( t );
        else // case 3: height( t->right->right ) < height( t->right->left ), see Figure 4.39 in textbook
            doubleWithRightChild( t );
    }

    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

// private height: refer to textbook, Figure 4.41
// this function is useful in "balance" (see also Page 154 in textbook): 
// if t is not empty (NULL), then height(t) == t->height; 
// but it can be annoying if t == NULL, because we do not have t->height (i.e., segmentation fault)
template<typename Comparable>
int AVLTree<Comparable>::height(AVLNode * t) const {
    return t == NULL ? -1 : t->height;
}

// private rotateWithLeftChild: for case 1, referring to textbook, Figure 4.44 (code) and Figure 4.43 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode * & k2) {
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;

    k2 = k1; // The reference k2 is updated to point to k1: the address k2 was originally pointing to, now points to k1.
}

// private rotateWithRightChild: for case 4 (the mirrored case of case 1)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode * & k2) {
    AVLNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max( height( k2->right ), height( k2->left ) ) + 1;
    k1->height = max( height( k1->right ), k2->height ) + 1;

    k2 = k1; // The reference k2 is updated to point to k1: making the original k1 as the new root
}

// private doubleWithLeftChild: for case 2, see textbook, Figure 4.46 (code) and Figure 4.45 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode * & k3) {
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

// private doubleWithRightChild: for case 3 (the mirrored case of case 2)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode * & k3) {
    rotateWithLeftChild( k3->right );
    rotateWithRightChild( k3 );
}

// public remove: refer to textbook, Figure 4.47
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x ) {
    remove(x, root);
}

// private recurive remove: refer to textbook, Figure 4.47
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x, AVLNode* & t) {
    if (t == NULL)
        return;  // item not found; do nothing

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
        AVLNode* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }

    balance( t );
}


// public treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize() const {
    return treeSize(root);
}

// private recursive treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize(AVLNode* t) const {
    if (t == NULL) {
        return 0; // empty tree
    }
    return 1 + treeSize(t->left) + treeSize(t->right); // 1 (count the current node) + count_from_left + count_from_right
}


// public computeHeight. See Figure 4.61 in Textbook
template <typename Comparable>
int AVLTree<Comparable>::computeHeight() const {
    return computeHeight(root);
}

// private recursive computeHeight
template <typename Comparable>
int AVLTree<Comparable>::computeHeight(AVLNode* t) const {
    if (t == NULL) {
        return -1; // empty tree
    }
    int leftHeight = computeHeight(t->left);
    int rightHeight = computeHeight(t->right);
    return 1 + max(leftHeight, rightHeight);
}

// public readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight() const {
    return root->height;
}

// public averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth() const {
    return averageDepth(root);
}

// private averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth(AVLNode * t) const {
    if (root == NULL) {
        return 0.0;
    }
    int totalNodes = treeSize(t);
    int totalPathLength = sumDepth(t, 0); 
    return static_cast<double>(totalPathLength) / totalNodes;
}

// private recursive sumDepth
template <typename Comparable>
int AVLTree<Comparable>::sumDepth(AVLNode * t, int depth) const {
    if (t == NULL) {
        return 0;
    }
    return depth + sumDepth(t->left, depth + 1) + sumDepth(t->right, depth + 1);
}

// private readInOrder
template <typename Comparable>
void AVLTree<Comparable>::readInOrder(AVLNode * t, vector<AVLNode*> & readNodes) const {
    if (t == NULL) 
        return;
    readInOrder(t->left, readNodes);
    readNodes.push_back(t);
    readInOrder(t->right, readNodes);
}

// public removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank) {
    vector<AVLNode*> nodes;
    readInOrder(root, nodes);

    if (rank < 1 || rank > nodes.size()) {
        cout << "Invalid rank: " << rank << endl;
        return;
    }

    AVLNode* nodeToDelete = nodes[rank - 1]; 
    remove(nodeToDelete->element);

}

// public isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced() const {
    return isBalanced(root);
}

// private isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced(AVLNode *t) const {
    if (t == NULL)
    {
        return true;
    }

    // Recursively check if left and right subtrees are balanced
    if (!isBalanced(t->left) || !isBalanced(t->right)) {
        return false;
    }

    // Calculate the height of the left and right subtrees
    int leftHeight = computeHeight(t->left);
    int rightHeight = computeHeight(t->right);

    // Check the balance factor
    if ( abs(leftHeight - rightHeight) > 1 ) {
        return false;
    }

    return true;
}

// public isBST
template <class Comparable>
bool AVLTree<Comparable>::isBST() const {
    return isBST(root, numeric_limits<Comparable>::min(), numeric_limits<Comparable>::max());
}

// private isBST helper
template <class Comparable>
bool AVLTree<Comparable>::isBST(AVLNode* t, Comparable min, Comparable max) const {
    if (t == NULL) {
        return true;  // An empty tree is a valid BST
    }

    // Check if the current node's value violates the min/max constraint
    if (t->element <= min || t->element >= max) {
        return false;
    }

    // Recursively check the left subtree with updated max constraint
    bool leftIsValid = isBST(t->left, min, t->element);
    // Recursively check the right subtree with updated min constraint
    bool rightIsValid = isBST(t->right, t->element, max);

    return leftIsValid && rightIsValid;
}
