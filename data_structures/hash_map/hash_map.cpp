#include <stdexcept>
#include "hash_map.h"

HashMap::HashMap() : buckets(BUCKET_COUNT), count(0) {}

int HashMap::hash(int key) const
{
  return key % BUCKET_COUNT;
}

size_t HashMap::size() const
{
  return count;
}

bool HashMap::isEmpty() const
{
  return count == 0;
}

void HashMap::insert(int key, int value)
{
  int index = hash(key);

  for (auto &entry : buckets[index])
  {
    if (entry.first == key)
    {
      entry.second = value;
      return;
    }
  }

  buckets[index].push_back({key, value});
  count++;
}

int HashMap::get(int key) const
{
  int index = hash(key);

  for (const auto &entry : buckets[index])
  {
    if (entry.first == key)
    {
      return entry.second;
    }
  }

  throw std::runtime_error("Key not found");
}

bool HashMap::contains(int key) const
{
  int index = hash(key);

  for (const auto &entry : buckets[index])
  {
    if (entry.first == key)
    {
      return true;
    }
  }

  return false;
}

void HashMap::remove(int key)
{
  int index = hash(key);

  for (auto it = buckets[index].begin(); it != buckets[index].end(); it++)
  {
    if (it->first == key)
    {
      buckets[index].erase(it);
      count--;
      return;
    }
  }

  throw std::runtime_error("Key not found");
}