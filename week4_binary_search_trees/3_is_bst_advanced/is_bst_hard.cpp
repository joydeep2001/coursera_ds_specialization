#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN -9223372036854775808

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


bool isBetween(int key, long long upper_bound_, long long lower_bound_)
{
    return (key < upper_bound_ && key >= lower_bound_);
}



bool isBst(const vector<Node>& tree,int i, long long upper_bound_, long long lower_bound_)
{

    bool l, r;
    if(i == -1)
        return true;

    if(!isBetween(tree[i].key, upper_bound_, lower_bound_))
    {

        //cout << "i:" << i << endl;
        //cout << lower_bound_ << " " << upper_bound_ << endl;
        return false;
    }


    l = isBst(tree, tree[i].left, tree[i].key, lower_bound_);

    r = isBst(tree, tree[i].right, upper_bound_, tree[i].key);

    //cout << ">" << i << " "<< l << " " << r << std::endl;
    return l && r;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if(tree.size() == 0)
    return true;

  return isBst(tree, 0, LLONG_MAX, LLONG_MIN);



}

int main() {

  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
