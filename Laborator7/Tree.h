#pragma once
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;


template < class T>
class Tree
{
private:
	struct nod
	{
		T value;
		nod* parent;
		nod* firstChild;
		nod* nextSibling;

		nod(const T& val);
	};

	nod* root = nullptr;
	void deleteSubtree(nod* node);
	int countNodes(nod* node) const;

public:
	Tree() : root(nullptr) {};
	~Tree();

	nod* add_node(nod* parent, const T& value);
	nod* get_node(nod* node);
	void delete_node(nod* node);
	nod* find(nod* node, const T& value, bool(*compare)(const T&, const T&));
	nod* insert(nod* parent, const T& value, int index);
	void  sort(nod* node, bool(*compare)(const T&, const T&) = nullptr);
	int count(nod* node = nullptr) const;
	void print(nod* node = nullptr, int depth = 0)const;
	nod* get_root()const;
};

template <class T>
Tree<T>::nod::nod(const T& val)
    : value(val), parent(nullptr), firstChild(nullptr), nextSibling(nullptr) {
}

template <class T>
Tree<T>::~Tree() {
    deleteSubtree(root);
}

template <class T>//functie ajutatoare
void Tree<T>::deleteSubtree(nod* node) {
    if (!node) return;

    nod* child = node->firstChild;
    while (child) {
        nod* next = child->nextSibling;
        deleteSubtree(child);
        child = next;
    }
    delete node;
}

template <class T>
typename Tree<T>::nod* Tree<T>::add_node(nod* parent, const T& value) {
    nod* newNode = new nod(value);
    newNode->parent = parent;

    if (!parent) {
        if (root) {
            newNode->firstChild = root;
            root->parent = newNode;
        }
        root = newNode;
    }
    else {
        if (!parent->firstChild) {
            parent->firstChild = newNode;
        }
        else {
            nod* sibling = parent->firstChild;
            while (sibling->nextSibling) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = newNode;
        }
    }

    return newNode;
}

template <class T>
typename Tree<T>::nod* Tree<T>::get_node(nod* parent) {
    return parent ? parent->firstChild : root;
}

template <class T>
void Tree<T>::delete_node(nod* node) {
    if (!node) return;

    if (node->parent) {
        nod* child = node->parent->firstChild;
        nod* prev = nullptr;

        while (child && child != node) {
            prev = child;
            child = child->nextSibling;
        }

        if (child) {
            if (prev) {
                prev->nextSibling = child->nextSibling;
            }
            else {
                node->parent->firstChild = child->nextSibling;
            }
        }
    }
    else {
        root = nullptr;
    }

    deleteSubtree(node);
}

template <class T>
typename Tree<T>::nod* Tree<T>::find(nod* node, const T& value, bool (*compare)(const T&, const T&)) {
    if (!node) node = root;
    if (!node) return nullptr;

    if (compare(node->value, value)) return node;

    nod* child = node->firstChild;
    while (child) {
        nod* found = find(child, value, compare);
        if (found) return found;
        child = child->nextSibling;
    }

    return nullptr;
}

template <class T>
typename Tree<T>::nod* Tree<T>::insert(nod* parent, const T& value, int index) {
    nod* newNode = new nod(value);
    newNode->parent = parent;

    if (!parent) {
        if (root) {
            newNode->firstChild = root;
            root->parent = newNode;
        }
        root = newNode;
        return newNode;
    }

    if (index == 0 || !parent->firstChild) {
        newNode->nextSibling = parent->firstChild;
        parent->firstChild = newNode;
    }
    else {
        nod* prev = parent->firstChild;
        for (int i = 1; i < index && prev->nextSibling; i++) {
            prev = prev->nextSibling;
        }
        newNode->nextSibling = prev->nextSibling;
        prev->nextSibling = newNode;
    }

    return newNode;
}

template <class T>//sort cu bubble sort
void Tree<T>::sort(nod* parent, bool (*compare)(const T&, const T&)) {
    if (!parent) parent = root;
    if (!parent || !parent->firstChild || !parent->firstChild->nextSibling) return;

    int count = 0;
    nod* temp = parent->firstChild;
    while (temp) {
        count++;
        temp = temp->nextSibling;
    }

    nod** children = new nod * [count];
    temp = parent->firstChild;
    for (int i = 0; i < count; ++i) {
        children[i] = temp;
        temp = temp->nextSibling;
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            bool shouldSwap = compare ?
                compare(children[j]->value, children[i]->value) :
                (children[j]->value < children[i]->value);

            if (shouldSwap) {
                nod* tmp = children[i];
                children[i] = children[j];
                children[j] = tmp;
            }
        }
    }

    parent->firstChild = children[0];
    for (int i = 0; i < count - 1; ++i) {
        children[i]->nextSibling = children[i + 1];
    }
    children[count - 1]->nextSibling = nullptr;

    delete[] children;
}

template <class T>
int Tree<T>::count(nod* node) const {
    if (!node) node = root;
    return countNodes(node);
}

template <class T>//functie ajutatoare
int Tree<T>::countNodes(nod* node) const {
    if (!node) return 0;
    int total = 1;
    nod* child = node->firstChild;
    while (child) {
        total += countNodes(child);
        child = child->nextSibling;
    }
    return total;
}

template <class T>
void Tree<T>::print(nod* node, int depth) const {
    if (!node) {
        if (depth == 0) node = root;
        else return;
    }

    for (int i = 0; i < depth; ++i)
        cout << "  ";
    cout << node->value << "\n";

    nod* child = node->firstChild;
    while (child) {
        print(child, depth + 1);
        child = child->nextSibling;
    }
}

template <class T>
typename Tree<T>::nod* Tree<T>::get_root() const {
    return root;
}

