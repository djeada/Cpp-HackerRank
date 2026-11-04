#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Workshop {
  int start_time;
  int duration;
  long long end_time;
};

struct Available_Workshops {
  int n;
  Workshop *Workshops;

  Available_Workshops(int _n, Workshop *workshops)
      : n(_n), Workshops(workshops) {}
};

Available_Workshops *initialize(int start_time[], int duration[], int n) {
  auto AW = new Available_Workshops(n, new Workshop[n]);

  for (int i = 0; i < n; i++) {
    AW->Workshops[i].start_time = start_time[i];
    AW->Workshops[i].duration = duration[i];
    AW->Workshops[i].end_time =
        static_cast<long long>(start_time[i]) + duration[i];
  }

  return AW;
}

bool CompareWorkshops(Workshop w1, Workshop w2) {
  return w1.end_time < w2.end_time;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
  vector<Workshop> workshops(ptr->Workshops, ptr->Workshops + ptr->n);
  sort(workshops.begin(), workshops.end(), CompareWorkshops);
  int result = 0;
  long long end_time = numeric_limits<long long>::lowest();
  for (const auto &w : workshops) {
    if (w.start_time >= end_time) {
      end_time = w.end_time;
      result++;
    }
  }
  return result;
}

int main() {
  int n; // number of workshops
  cin >> n;
  vector<int> start_time(n);
  vector<int> duration(n);

  for (int i = 0; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  auto *ptr = initialize(start_time.data(), duration.data(), n);
  cout << CalculateMaxWorkshops(ptr) << '\n';
  delete[] ptr->Workshops;
  delete ptr;
  return 0;
}
