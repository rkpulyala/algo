#include <iostream>
#include <algorithm>

vector<vector<int>> find_nearest_neighbors(vector<vector<int>> grid, pair<int,int> point, int k)
{
    vector<pair<int,int>> distances = getdistances(grid, point);
    partial_sort(distances.begin(), distances.end(), k);
    transform(distances.begin(), distances.begin() + k, [])
}
