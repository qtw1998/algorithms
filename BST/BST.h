//
// Created by qtw1998 on 23-5-29.
//

#ifndef DATASTRUCTURE_BST_H
#define DATASTRUCTURE_BST_H

#include <iostream>
#include <stack>
#include <queue>

template<typename T>
class BST {
private:
    struct Node {
        T e;
        Node *left, *right;

        Node(T e) : e(e), left(nullptr), right(nullptr) {}
    };

    Node *root;
    int size;
public:
    BST() : root(nullptr), size(0) {}

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add(T e) {
        root = add(root, e);
//        if (root == nullptr) {
//            root = new Node(e);
//            ++size;
//        } else {
//            add(root, e);
//        }
    }

private:
    /**
     * // 向以node为根的二分搜索树中插入元素e，递归算法
     * @param node
     * @param e
     */
//    void add(Node *node, T e) {
//        if (e == node->e)
//            return;
//        else if (e < node->e && node->left == nullptr) {
//            node->left = new Node(e);
//            ++size;
//            return;
//        } else if (e > node->e && node->right == nullptr) {
//            node->right = new Node(e);
//            ++size;
//            return;
//        }
//
//        if (e < node->e) {
//            add(node->left, e);
//        } else {
//            add(node->right, e);
//        }
//    }
    /**
     * 返回插入新节点后二分搜索树的根
     * @param node
     * @param e
     * @return
     */
//    Node *add(Node *node, T e) {
//        if (node == nullptr) {
//            ++size;
//            return new Node(e);
//        }
//
//        if (e < node->e)
//            node->left = add(node->left, e);
//        else if (e > node->e)
//            node->right = add(node->right, e);
//
//        return node;
//    }

    Node *add(Node *node, T e) {
        std::cout << "Adding " << e << " to the tree." << std::endl;
        if (node == nullptr) {
            std::cout << "Creating a new node for " << e << std::endl;
            ++size;
            return new Node(e);
        }

        if (e < node->e) {
            std::cout << "Going left from " << node->e << std::endl;
            node->left = add(node->left, e);
        } else if (e > node->e) {
            std::cout << "Going right from " << node->e << std::endl;
            node->right = add(node->right, e);
        }

        return node;
    }


public:
    bool contains(T e) {
        return contains(root, e);
    }

private:
    /**
     * 看以node为根的二分搜索树中是否包含元素e, 递归算法
     * @param node
     * @param e
     * @return
     */
    bool contains(Node *node, T e) {
        if (node == nullptr)
            return false;

        if (e < node->e)
            return contains(node->left, e);
        else if (e > node->e)
            return contains(node->right, e);
        else if (node->e == e)
            return true;
    }

public:
    void preOrder() {
        preOrder(root);
    }

    void preOrderNR() {
        if (root == nullptr)
            return;

        std::stack<Node *> stack;
        stack.push(root);

        while (!stack.empty()) {
            Node *node = stack.top();
            stack.pop();

            std::cout << node->e << std::endl;
            if (node->right != nullptr)
                stack.push(node->right);
            if (node->left != nullptr)
                stack.push(node->left);
        }
    }

private:
    void preOrder(Node *node) {
        if (node == nullptr)
            return;

        std::cout << node->e << std::endl;
        preOrder(node->left);
        preOrder(node->right);
    }

public:
    void inOrder() {
        inOrder(root);
    }

private:
    void inOrder(Node *node) {
        if (node == nullptr)
            return;

        inOrder(node->left);
        std::cout << node->e << std::endl;
        inOrder(node->right);
    }

public:
    void postOrder() {
        postOrder(root);
    }

private:
    void postOrder(Node *node) {
        if (node == nullptr)
            return;

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->e << std::endl;
    }

public:
    void levelOrder() {
        if (root == nullptr)
            return;
        std::queue<Node *> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node *curNode = queue.front();
            queue.pop();
            std::cout << curNode->e << std::endl;

            if (curNode->left != nullptr)
                queue.push(curNode->left);
            if (curNode->right != nullptr)
                queue.push(curNode->right);
        }
    }

public:
    T minimum() {
        if (size == 0)
            throw std::invalid_argument("BST is empty.");
        return minimum(root);
    }

private:
    T minimum(Node *node) {
        if (node->left == nullptr)
            return node->e;

        return minimum(node->left);
    }

public:
    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, const BST<U> &bst) {
        bst.generateBSTString(bst.root, 0, output);
        return output;
    }

private:
    void generateBSTString(Node *node, int depth, std::ostream &output) const {
        if (node == nullptr)
            return;

        output << "Depth: " << depth << " " << node->e << std::endl;

        generateBSTString(node->left, depth + 1, output);
        generateBSTString(node->right, depth + 1, output);
    }
};

#endif //DATASTRUCTURE_BST_H
