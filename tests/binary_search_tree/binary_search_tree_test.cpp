#include <cassert>
#include <iostream>
#include "../../data_structures/binary_search_tree/binary_search_tree.h"

int main()
{
  BinarySearchTree bst;

  // insert
  bst.insert(8);
  bst.insert(3);
  bst.insert(10);
  bst.insert(1);
  bst.insert(6);
  bst.insert(14);

  // search
  assert(bst.search(6) == true);
  assert(bst.search(99) == false);

  // inorder
  assert(bst.inorder() == std::vector<int>({1, 3, 6, 8, 10, 14}));

  // remove leaf
  bst.remove(1);
  assert(bst.search(1) == false);

  // remove node with two children
  bst.remove(3);
  assert(bst.search(3) == false);
  assert(bst.inorder() == std::vector<int>({6, 8, 10, 14}));

  std::cout << "All tests passed\n";
}