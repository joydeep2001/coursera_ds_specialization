#include<iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pi;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    long long cur_time = 0, job_count = 0;

    priority_queue<pi, vector<pi>, greater<pi> > pq;

    for(int thread = 0;thread < num_workers_;thread++)
    {

        long long temp = cur_time + jobs_[job_count++];

        pq.push(make_pair(temp, thread));
        assigned_workers_.push_back(thread);
        start_times_.push_back(cur_time);


    }

    while(!pq.empty())
    {
        //extract min
        pi min_ = pq.top();
        pq.pop();
        //first -> time second->thread
        if(cur_time < min_.first)
            cur_time = min_.first;
        if(job_count < jobs_.size())
        {
            long long temp = cur_time + jobs_[job_count++];
            int thread = min_.second;
            pq.push(make_pair(temp, thread));
            assigned_workers_.push_back(thread);
            start_times_.push_back(cur_time);
        }


    }



  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
