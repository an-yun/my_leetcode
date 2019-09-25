#include <map>
#include <vector>
#include <iostream>
using namespace std;

int find_most_word(const vector<int> &nums)
{
    map<int,int> word_count;
    for(auto num:nums)
        ++word_count[num];
    int max_num,count =0;
    for(auto &p:word_count)
    {
        if(p.second > count )
        {
            max_num = p.first;
            count = p.second;
        }
    }
}

int main() {
    vector<int> nums{1,2,4,89,4,4,4,5,4};
    cout<< find_most_word(nums)<<endl;
    return 0;
}