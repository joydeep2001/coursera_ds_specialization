#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps(int parent) {


    int smallest;

    smallest = parent;
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;

    if(right < data_.size() && data_[right] < data_[smallest])
    {
        smallest = right;
    }

    if(left < data_.size() && data_[left] < data_[smallest])
    {
        smallest = left;
    }
    //std::cout << smallest << std::endl;

    if(smallest != parent)
    {
        std::swap(data_[parent], data_[smallest]);
        swaps_.push_back(make_pair(parent, smallest));

        GenerateSwaps(smallest);
    }



  }

 public:
  void Solve() {
    ReadData();
    int parent = data_.size() / 2 - 1;
    swaps_.clear();
    for(int i = parent;i >= 0;i--)
        GenerateSwaps(i);

    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
