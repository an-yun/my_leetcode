#include "zuo/ioutils.hpp"
#include "zuo/treenode.hpp"
#include <algorithm>
#include <chrono>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    size_t word_length;
    size_t words_size;
    bool one_distinction(const string &word1, const string &word2)
    {
        bool changed = false;
        for (size_t i = 0; i < word_length; ++i)
        {
            if (word1[i] != word2[i])
            {
                if (changed)
                    return false;
                changed = true;
            }
        }
        return changed;
    }
    void add_path(vector<list<size_t>> &pre, list<size_t> &path, list<list<size_t>> &paths_index)
    {
        auto node = path.front();
        for (auto pre_node : pre[node])
        {
            if (pre_node == words_size)
                paths_index.push_back(path);
            else
            {
                path.push_front(pre_node);
                add_path(pre, path, paths_index);
                path.pop_front();
            }
        }
    }
    void collect_bfs_path(vector<vector<bool>> &graph, size_t from, size_t to, list<list<size_t>> &path_indexs)
    {
        vector<size_t> dis(words_size + 1, 0);
        vector<list<size_t>> pre(words_size);
        queue<size_t> next_visit;
        next_visit.push(from);
        while (!next_visit.empty())
        {
            auto node = next_visit.front();
            if (node == to)
                break;
            next_visit.pop();
            for (size_t i = 0; i < words_size; ++i)
            {
                if (graph[node][i])
                {
                    if (!dis[i])
                    {
                        pre[i].push_back(node);
                        dis[i] = dis[node] + 1;
                        next_visit.push(i);
                    }
                    else if (dis[node] + 1 <= dis[i])
                        pre[i].push_back(node);
                }
            }
        }
        list<size_t> path{to};
        add_path(pre, path, path_indexs);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        if (wordList.size() == 0)
            return {};
        word_length = beginWord.size();
        words_size = wordList.size();
        vector<vector<bool>> graph(words_size + 1, vector<bool>(words_size, false));
        size_t end_pos = words_size;
        for (size_t i = 0; i < words_size; ++i)
        {
            graph[words_size][i] = one_distinction(beginWord, wordList[i]);
            if (wordList[i] == endWord)
                end_pos = i;
            for (size_t j = i + 1; j < words_size; ++j)
                graph[i][j] = graph[j][i] = one_distinction(wordList[i], wordList[j]);
        }
        if (end_pos == words_size)
            return {};

        list<list<size_t>> path_indexs;
        collect_bfs_path(graph, words_size, end_pos, path_indexs);

        vector<vector<string>> paths;
        for (auto &path_index : path_indexs)
        {
            vector<string> path{beginWord};
            for (auto index : path_index)
                path.push_back(wordList[index]);
            paths.push_back(path);
        }
        return paths;
    }
};
int main()
{
    Solution s;
    // vector<string> word_list1{"hot", "dot", "dog", "lot", "log", "cog"};
    // println(s.findLadders("hit", "cog", word_list1));

    // vector<string> word_list2{"hot", "dot", "dog", "lot", "log"};
    // println(s.findLadders("hit", "cog", word_list2));

    // vector<string> word_list3{"a", "b", "c"};
    // println(s.findLadders("a", "c", word_list3));

    vector<string> word_list4{"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    println(s.findLadders("red", "tax", word_list4));
    return 0;
}
