#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include <cmath>

using namespace std;
using point = pair<int,int>;

void sort_polygon(vector<point> &points)
{
  vector<pair<double, point>> angles(points.size());
  transform(points.begin(), points.end(), angles.begin(), [&](point &p) -> pair<double, point> {
      return { atan2(p.second, p.first), p };
  });
  for(auto p : angles) cout << p.first << " ( "<< p.second.first << ", " << p.second.second << ") "; cout << endl; 
  sort(angles.begin(), angles.end());
  for(auto p : angles) cout << p.first << " ( "<< p.second.first << ", " << p.second.second << ") "; cout << endl; 
  transform(angles.begin(), angles.end(), points.begin(), [&](pair<double, point> &p) {
      return p.second;
  });

}

int main() {
  vector<point> pts = { {5, 1}, {2, 5}, {2, 7}, {3, 8}, {1,10}, {11, 2}, {9, 10}, {1, 9}, {9, 3}  };
  //for(auto p : pts) cout << "( "<< p.first << ", " << p.second << ") "; cout << endl; 
  sort_polygon(pts);
  //for(auto p : pts) cout << "( "<< p.first << ", " << p.second << ") "; cout << endl; 
  return 0;
}
