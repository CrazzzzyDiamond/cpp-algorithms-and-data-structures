#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

Node *BinarySearchTree::findMin(Node *node) const
{
  while (node->left != nullptr)
    node = node->left;
  return node;
}

Node *BinarySearchTree::insert(Node *node, int value)
{
  if (node == nullptr)
    return new Node{value, nullptr, nullptr};

  if (value < node->value)
    node->left = insert(node->left, value);
  else if (value > node->value)
    node->right = insert(node->right, value);

  return node;
}

void BinarySearchTree::insert(int value)
{
  root = insert(root, value);
}

Node *BinarySearchTree::remove(Node *node, int value)
{
  if (node == nullptr)
    return nullptr;

  if (value < node->value)
    node->left = remove(node->left, value);
  else if (value > node->value)
    node->right = remove(node->right, value);
  else
  {
    if (node->left == nullptr)
    {
      Node *temp = node->right;
      delete node;
      return temp;
    }
    if (node->right == nullptr)
    {
      Node *temp = node->left;
      delete node;
      return temp;
    }

    Node *successor = findMin(node->right);
    node->value = successor->value;
    node->right = remove(node->right, successor->value);
  }

  return node;
}

void BinarySearchTree::remove(int value)
{
  root = remove(root, value);
}

bool BinarySearchTree::search(Node *node, int value) const
{
  if (node == nullptr)
    return false;

  if (value == node->value)
    return true;

  if (value < node->value)
    return search(node->left, value);
  else
    return search(node->right, value);
}

bool BinarySearchTree::search(int value) const
{
  return search(root, value);
}

void BinarySearchTree::inorder(Node *node, std::vector<int> &result) const
{
  if (node == nullptr)
    return;

  inorder(node->left, result);
  result.push_back(node->value);
  inorder(node->right, result);
}

std::vector<int> BinarySearchTree::inorder() const
{
  std::vector<int> result;
  inorder(root, result);
  return result;
}

void BinarySearchTree::destroy(Node *node)
{
  if (node == nullptr)
    return;

  destroy(node->left);
  destroy(node->right);
  delete node;
}

BinarySearchTree::~BinarySearchTree()
{
  destroy(root);
}