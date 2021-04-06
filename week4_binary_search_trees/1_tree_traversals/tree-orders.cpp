#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <long long> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_searcher(int i, vector<long long>& result)
  {

      if(i == -1)
          return;

      in_order_searcher(left[i], result);
      result.push_back(key[i]);
      in_order_searcher(right[i], result);


  }
  vector <long long> in_order() {
    vector<long long> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_searcher(0, result);

    return result;
  }
  void pre_order_searcher(int i, vector<long long>& result)
  {

      if(i == -1)
          return;
      result.push_back(key[i]);
      pre_order_searcher(left[i], result);
      pre_order_searcher(right[i], result);


  }
  vector <long long> pre_order() {
    vector<long long> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    pre_order_searcher(0, result);
    return result;
  }
  void post_order_searcher(int i, vector<long long>& result)
  {

      if(i == -1)
          return;

      post_order_searcher(left[i], result);
      post_order_searcher(right[i], result);
      result.push_back(key[i]);


  }
  vector <long long> post_order() {
    vector<long long> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    post_order_searcher(0, result);
    return result;
  }
};

void print(vector <long long> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

