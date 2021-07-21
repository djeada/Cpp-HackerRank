#include <bits/stdc++.h>

using namespace std;

struct Workshop {
  int start_time;
  int duration;
  int end_time;
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
    AW->Workshops[i].end_time = start_time[i] + duration[i] - 1;
  }

  return AW;
}

bool CompareWorkshops(Workshop w1, Workshop w2) {
  return w1.end_time < w2.end_time;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
  vector<Workshop> W;
  for (int i = 0; i < ptr->n; i++)
    W.push_back(ptr->Workshops[i]);
  sort(W.begin(), W.end(), CompareWorkshops);
  int result = 0, end_time = 0;
  for (auto w : W) {
    if (w.start_time > end_time) {
      end_time = w.end_time;
      result++;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  int n; // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int *start_time = new int[n];
  int *duration = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  Available_Workshops *ptr;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return 0;
}
