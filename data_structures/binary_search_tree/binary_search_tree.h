#pragma once
#include <vector>

struct Node
{
  int value;
  Node *left;
  Node *right;
};

class BinarySearchTree
{
private:
  Node *root;

  Node *insert(Node *node, int value);
  Node *remove(Node *node, int value);
  Node *findMin(Node *node) const;
  bool search(Node *node, int value) const;
  void inorder(Node *node, std::vector<int> &result) const;
  void destroy(Node *node);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  void insert(int value);
  void remove(int value);
  bool search(int value) const;
  std::vector<int> inorder() const;
};