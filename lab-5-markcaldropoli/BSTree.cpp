#include "BSTree.h"

using namespace std;

BSTree::Node::Node(int data, Node * parent) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = parent;
}

BSTree::BSTree() {
    this->root = nullptr;
}

BSTree::BSTree(const BSTree &old_tree) {
    this->root = nullptr;
    preOrder(old_tree.root);
}

BSTree::~BSTree() {
    postOrder(this->root);
}

bool BSTree::empty() {
    return (this->root == nullptr);
}

bool BSTree::insertNode(int val, Node * n) {
    if(val < n->getData()) {
        if(n->getLeft() == nullptr) {
            n->setLeft(new Node(val, n));
            return true;
        } else insertNode(val, n->getLeft());
    } else if(val > n->getData()) {
        if(n->getRight() == nullptr) {
            n->setRight(new Node(val, n));
            return true;
        } else insertNode(val, n->getRight());
    }
    return false;
}

bool BSTree::insert(int val) {
    if(root == nullptr) {
        this->root = new Node(val, nullptr);
        return true;
    }
    return insertNode(val, this->root);
}

bool BSTree::findNode(int val, Node * n) {
    if(val < n->getData()) {
        if(n->getLeft() == nullptr) return false;
        else return findNode(val, n->getLeft());
    } else if(val > n->getData()) {
        if(n->getRight() == nullptr) return false;
        else return findNode(val, n->getRight());
    }
    return true;
}

BSTree::Node * BSTree::findNode2(int val, Node * n) {
    if(val < n->getData()) {
        if(n->getLeft() == nullptr) return nullptr;
        return findNode2(val, n->getLeft());
    } else if(val > n->getData()) {
        if(n->getRight() == nullptr) return nullptr;
        return findNode2(val, n->getRight());
    }
    return n;
}

bool BSTree::find(int val) {
    if(this->root == nullptr) return false;
    return findNode(val, root);
}

void BSTree::sortedArray(vector<int> &list) {
    inOrder(list, this->root);
}

void BSTree::removeLeaf(Node * del) {
    if(del == root) root = nullptr;
    else if(del->getParent()->getLeft() == del) {
        del->getParent()->setLeft(nullptr);
    } else {
        del->getParent()->setRight(nullptr);
    }
    delete del;
}

void BSTree::shortcircuit(Node * del) {
    if(del == this->root) {
        if(del->getLeft() != nullptr) this->root = del->getLeft();
        else this->root = del->getRight();
    } else if(del->getParent()->getLeft() == del) {
        if(del->getLeft() != nullptr) {
            del->getParent()->setLeft(del->getLeft());
            del->getLeft()->setParent(del->getParent());
        } else {
            del->getParent()->setLeft(del->getRight());
            del->getRight()->setParent(del->getParent());
        }
    } else {
        if(del->getLeft() != nullptr) {
            del->getParent()->setRight(del->getLeft());
            del->getLeft()->setParent(del->getParent());
        } else {
            del->getParent()->setRight(del->getRight());
            del->getRight()->setParent(del->getParent());
        }
    }
    delete del;
}

BSTree::Node * BSTree::getMinMax(Node * n) {
    if(n->getLeft() == nullptr) return n;
    else return getMinMax(n->getLeft());
}

void BSTree::promotion(Node * del) {
    Node * promote = getMinMax(del->getRight());
    del->setData(promote->getData());

    if(promote->getLeft() == nullptr && promote->getRight() == nullptr) {
        removeLeaf(promote);
    } else {
        shortcircuit(promote);
    }
}

bool BSTree::remove(int num) {
    if(this->root == nullptr) return false;

    Node * del = findNode2(num, root);

    if(del == nullptr) return false;

    if(del->getLeft() == nullptr && del->getRight() == nullptr) {
        removeLeaf(del);
    } else if(del->getLeft() == nullptr || del->getRight() == nullptr) {
        shortcircuit(del);
    } else promotion(del);
    return true;
}

void BSTree::preOrder(Node * n) {
    if(n == nullptr) return;

    insert(n->getData());
    preOrder(n->getLeft());
    preOrder(n->getRight());
}

void BSTree::inOrder(vector<int> &list, Node * n) {
    if(n == nullptr) return;

    inOrder(list, n->getLeft());
    list.push_back(n->getData());
    inOrder(list, n->getRight());
}

void BSTree::postOrder(Node * n) {
    if(n == nullptr) return;

    postOrder(n->getLeft());
    postOrder(n->getRight());
    this->remove(n->getData());
}

