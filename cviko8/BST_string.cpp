//
// Created by Štěpán Kudláček on 19.04.2023.
//

#include "BST_string.h"


BST_string::BST_string() {
    root = nullptr;
}

BST_string::~BST_string() {
    Clear(root);
}

void BST_string::Clear(node* nod)
{
    if (nod != nullptr)
    {
        Clear(nod->left);
        Clear(nod->right);
        delete nod;
    }
}




bool BST_string::Search(string value) {
    return Search(value,root);
}

bool BST_string::Search(string value, node *nod) {

    return true;
}

void BST_string::Insert(string value, node*& nod)
{
    if (nod == nullptr)
    {
        node* newnode = new node;
        newnode->count++;
        newnode->key = value;
        newnode->left = newnode->right = nullptr;
        nod = newnode;
    }
    else
    {
        if (value > nod->key)
            Insert(value, nod->right);
        else
        if (value < nod->key)
            Insert(value, nod->left);
    }
}
