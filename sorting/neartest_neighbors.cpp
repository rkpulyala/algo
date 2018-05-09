#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

double distance(vector<int> &point1, vector<int> &point2)
{
    return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
}

vector<vector<int>> find_nearest_neighbours(int px, int py, vector<vector<int>> points_in_2d_grid, int k) {
    vector<int> point {px, py};
    
    vector<pair<double,int>> distances;
    for(int i=0; i < points_in_2d_grid.size(); ++i) {
        distances.push_back({distance(point, points_in_2d_grid[i]), i});
    }

    for(auto a : distances)
    {
      cout << a.first<< " " << 
           points_in_2d_grid[a.second][0] << " " <<
           points_in_2d_grid[a.second][1] << endl;
    }

    cout << "===========" << endl;

    nth_element(distances.begin(), distances.begin()+k, distances.end(), [](pair<double,int> &left, pair<double,int> &right) {
        return left.first < right.first;
    });

    //partial_sort(distances.begin(), distances.begin()+k, distances.end(), [](pair<double,int> &left, pair<double,int> &right) {
    //    return left.first < right.first;
    //});

    for(auto a : distances)
    {
      cout << a.first<< " " << 
           points_in_2d_grid[a.second][0] << " " <<
           points_in_2d_grid[a.second][1] << endl;
    }
    cout << "===========" << endl;
    
    vector<vector<int>> v;
    
    transform(distances.begin(), distances.begin()+k, back_inserter(v), [&points_in_2d_grid](const pair<double,int> &it) { 
        return points_in_2d_grid[it.second]; 
    });
    
    //for(int i=0; i < k; ++i){ 
    //    v.push_back(points_in_2d_grid[distances[i].second]); 
    //};
    
    return v;

}

int main()
{
    int px;
    cin >> px;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int py;
    cin >> py;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int n_points_rows;
    cin >> n_points_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int n_points_columns;
    cin >> n_points_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> n_points(n_points_rows);
    for (int n_points_row_itr = 0; n_points_row_itr < n_points_rows; n_points_row_itr++) {
        n_points[n_points_row_itr].resize(n_points_columns);

        for (int n_points_column_itr = 0; n_points_column_itr < n_points_columns; n_points_column_itr++) {
            cin >> n_points[n_points_row_itr][n_points_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> res = find_nearest_neighbours(px, py, n_points, k);

    for (int res_row_itr = 0; res_row_itr < res.size(); res_row_itr++) {
        for (int res_column_itr = 0; res_column_itr < res[res_row_itr].size(); res_column_itr++) {
            cout << res[res_row_itr][res_column_itr];

            if (res_column_itr != res[res_row_itr].size() - 1) {
                cout << " ";
            }
        }

        if (res_row_itr != res.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}

