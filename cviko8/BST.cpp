#include "BST.h"

void BST::Clear(node* nod)
{
    if (nod != nullptr)
    {
        Clear(nod->left);
        Clear(nod->right);
        cout << "Mazu uzel s klicem: " << nod->key << endl;
        delete nod;
    }
}

void BST::Insert(int value, node*& nod)
{
    if (nod == nullptr)
    {
        node* newnode = new node;
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

void BST::InOrder(node* nod)
{
    if (nod != nullptr)
    {
        InOrder(nod->left);
        cout << "Uzel s klicem: " << nod->key << endl;
        InOrder(nod->right);
    }
}

bool BST::Search(int value, node* nod)
{
    if (nod == nullptr)
        return false;
    else
    {
        if (nod->key == value)
            return true;
        else
        {
            if (value > nod->key)
                return Search(value, nod->right);
            else
                return Search(value, nod->left);
        }
    }
}

int BST::MinKey(node* nod)
{
    if (nod->key < nod->left->key && nod->key < nod->right->key){
        return nod->key;
    } else if (nod->left->key < nod->key && nod->left->key < nod->right->key) {
        return nod->left->key;
    } else if (nod->right->key < nod->key && nod->right->key < nod->left->key){
        return nod->right->key;
    }
    return 0;
}

int BST::MaxKey(node* nod)
{
    if (nod->key > nod->left->key && nod->key > nod->right->key){
        return nod->key;
    } else if (nod->left->key > nod->key && nod->left->key > nod->right->key) {
        return nod->left->key;
    } else if (nod->right->key > nod->key && nod->right->key > nod->left->key){
        return nod->right->key;
    }
    return 0;
}

vector<int> BST::ToVector(node* nod)
{
    vector<int> result;

    if (nod != nullptr)
    {
        // Recursively add the keys from the left subtree
        vector<int> left = ToVector(nod->left);
        result.insert(result.end(), left.begin(), left.end());

        // Add the current key
        result.push_back(nod->key);

        // Recursively add the keys from the right subtree
        vector<int> right = ToVector(nod->right);
        result.insert(result.end(), right.begin(), right.end());
    }

    return result;
}

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    Clear(root);
}

void BST::Insert(int value)
{
    Insert(value, root);
}

void BST::InOrder()
{
    cout << "In order pruchod!" << endl;
    InOrder(root);
}

bool BST::Search(int value)
{
    return Search(value, root);
}

int BST::MinKey()
{
    return MinKey(root);
}

int BST::MaxKey()
{
    return MaxKey(root);
}

vector<int> BST::ToVector()
{
    return ToVector(root);
}