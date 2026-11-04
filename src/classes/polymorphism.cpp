#include <iostream>
#include <map>
#include <memory>
#include <string>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : next(n), prev(p), value(val), key(k) {}
  Node(int k, int val) : Node(nullptr, nullptr, k, val) {}
};

class Cache {
protected:
  map<int, Node *> mp;
  int cp;
  Node *tail;
  Node *head;
  virtual void set(int, int) = 0;
  virtual int get(int) = 0;

public:
  virtual ~Cache() = default;
};

class LRUCache : public Cache {
public:
  explicit LRUCache(int capacity) {
    cp = capacity;
    head = tail = nullptr;
  }

  LRUCache(const LRUCache &) = delete;
  LRUCache &operator=(const LRUCache &) = delete;

  ~LRUCache() {
    while (head) {
      Node *next = head->next;
      delete head;
      head = next;
    }
  }

  void set(int key, int value) override {
    auto found = mp.find(key);
    if (found != mp.end()) {
      found->second->value = value;
      move_to_front(found->second);
      return;
    }
    if (cp <= 0) {
      return;
    }

    unique_ptr<Node> node(new Node(nullptr, head, key, value));
    mp.emplace(key, node.get());
    if (head) {
      head->prev = node.get();
    } else {
      tail = node.get();
    }
    head = node.release();

    if (mp.size() > static_cast<map<int, Node *>::size_type>(cp)) {
      Node *old_tail = tail;
      tail = old_tail->prev;
      tail->next = nullptr;
      mp.erase(old_tail->key);
      delete old_tail;
    }
  }

  int get(int key) override {
    auto found = mp.find(key);
    if (found == mp.end()) {
      return -1;
    }
    move_to_front(found->second);
    return found->second->value;
  }

private:
  void move_to_front(Node *node) {
    if (node == head) {
      return;
    }

    node->prev->next = node->next;
    if (node->next) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }

    node->prev = nullptr;
    node->next = head;
    head->prev = node;
    head = node;
  }
};

int main() {
  int n, capacity;
  cin >> n >> capacity;
  LRUCache cache(capacity);
  for (int i = 0; i < n; i++) {
    string command;
    int key;
    cin >> command >> key;
    if (command == "get") {
      cout << cache.get(key) << '\n';
    } else if (command == "set") {
      int value;
      cin >> value;
      cache.set(key, value);
    }
  }
}
