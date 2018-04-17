#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <random>

using namespace std;

vector<int> getRandomVector(int range_low, int range_high, int size)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(range_low, range_high);

    vector<int> v;
 
    for (int n=0; n<size; ++n)
        v.push_back(dis(gen));

    return v;
}


int findMissingNumber1(const std::vector<int> &nums)
{
  int sum = 0, len = nums.size()+1;
  for(int i=1; i <= len; ++i)
    sum += i;
  for(int n : nums)
    sum -= n;
  return sum;
}

int findMissingNumber(const std::vector<int> &nums)
{
  int sum = 0, len = nums.size()+1;
  for(int i=1; i <= len; ++i)
    sum ^= i;
  for(int n : nums)
    sum ^= n;
  return sum;
}

int main()
{
  std::vector<int> v = getRandomVector(-10000, 10000, 1000);
  std::cout << findMissingNumber1(v) << std::endl;
  return 0;
}
