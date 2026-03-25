#pragma once
#include <vector>

class HashMap
{
private:
  static const int BUCKET_COUNT = 16;

  using Entry = std::pair<int, int>;
  using Bucket = std::vector<Entry>;

  std::vector<Bucket> buckets;
  size_t count;

  int hash(int key) const;

public:
  HashMap();

  void insert(int key, int value);
  int get(int key) const;
  void remove(int key);
  bool contains(int key) const;
  size_t size() const;
  bool isEmpty() const;
};