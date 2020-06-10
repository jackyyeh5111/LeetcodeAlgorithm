#include <vector>
vector<int> generate_gray_code(int n)
{
    vector<int> result;
    for (int i=0; i<n; ++i) result.push_back(i^(i>>1));
}
