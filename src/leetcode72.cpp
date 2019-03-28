#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //todo
        size_t m = word1.size(),n=word2.size();
        vector<vector<size_t>> min_distance(m+1,vector<size_t>(n+1,1));
        iota(min_distance[0].begin(),min_distance[0].end(),0);        
        for(size_t i=1;i<=m;++i)
        {
            min_distance[i][0] = i;
            for(size_t j=1;j<=n;++j)
            {
                if(word1[i-1]== word2[j-1]) min_distance[i][j] = min_distance[i-1][j-1];
                else min_distance[i][j] = min(min_distance[i-1][j-1],min(min_distance[i-1][j],min_distance[i][j-1])) + 1;
            }
        }
        return min_distance[m][n];
    }
};

int main()
{
    Solution s;
    println(s.minDistance("plasma","altruism"));
    return 0;
}
