#include "linked_list.h"
#include <stdexcept>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
  while (head != nullptr)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

void LinkedList::push_front(int x)
{
  Node *newNode = new Node{x, head};
  head = newNode;
}

void LinkedList::push_back(int x)
{
  Node *newNode = new Node{x, nullptr};

  if (head == nullptr)
  {
    head = newNode;
    return;
  }

  Node *current = head;

  while (current->next != nullptr)
  {
    current = current->next;
  }

  current->next = newNode;
}

int LinkedList::pop_front()
{
  if (head == nullptr)
  {
    throw std::out_of_range("List is empty");
  }

  Node *temp = head;
  int val = head->value;

  head = head->next;
  delete temp;

  return val;
}

bool LinkedList::isEmpty() const
{
  return head == nullptr;
}