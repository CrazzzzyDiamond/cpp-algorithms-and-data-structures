struct Node
{
  int value;
  Node *next;
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList();
  ~LinkedList();

  void push_front(int x);
  void push_back(int x);
  int pop_front();

  bool isEmpty() const;
};