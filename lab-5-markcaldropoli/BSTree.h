#ifndef BSTREE_H
#define BSTREE_H

#include <queue>
#include <vector>

class BSTree {
    private:
        class Node {
            private:
                Node * left, * right, * parent;
                int data;
            public:
                Node(int data, Node *parent);

                Node * getLeft() {return left;}
                Node * getRight() {return right;}
                Node * getParent() {return parent;}
                int getData() {return data;}

                void setLeft(Node * n) {left = n;}
                void setRight(Node * n) {right = n;}
                void setParent(Node * n) {parent = n;}
                void setData(int val) {data = val;}
        };
        
        Node * root;

        bool insertNode(int data, Node * n);
        bool findNode(int data, Node * n);
        Node * findNode2(int val, Node * n);
        void removeLeaf(Node * del);
        void shortcircuit(Node * del);
        Node * getMinMax(Node * n);
        void promotion(Node * del);

        void preOrder(Node *old_root);
        void inOrder(std::vector<int> &list, Node * n);
        void postOrder(Node * n);
    
    public:
        BSTree();
        BSTree(const BSTree &old_tree);
        ~BSTree();
        bool empty();
        bool insert(int val);
        bool find(int val);
        void sortedArray(std::vector<int> &list);
        bool remove(int num);
};

#endif
