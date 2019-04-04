#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Trie
{
  public:
    int index;
    bool is_leave;
    shared_ptr<Trie> nodes[26];
    Trie(int index = -1) : index(index), is_leave(true) {}
};
void insert_word(shared_ptr<Trie> trie, const string &word, size_t p, int index = -1)
{
    if (p >= word.size())
    {
        trie->index = index;
        return;
    }
    int i = word[p] - 'a';
    if (trie->nodes[i] == nullptr)
    {
        trie->is_leave = false;
        trie->nodes[i] = make_shared<Trie>();
    }
    insert_word(trie->nodes[i], word, p + 1, index);
}
class Solution
{
  private:
    int m;
    int n;

  public:
    void dfs(vector<vector<char>> &board, int x, int y, shared_ptr<Trie> trie, set<int> &match_set)
    {
        if (trie->index != -1)
            match_set.insert(trie->index);
        if (trie->is_leave)
            return;
        if (x < 0 || x >= m || y < 0 || y >= n) // edge case
            return;
        char temp = board[x][y]; // for save memory
        if (temp == '\0')
            return;
        board[x][y] = '\0';
        auto sub_trie = trie->nodes[temp - 'a'];
        if (sub_trie)
        {
            dfs(board, x - 1, y, sub_trie, match_set);
            dfs(board, x + 1, y, sub_trie, match_set);
            dfs(board, x, y - 1, sub_trie, match_set);
            dfs(board, x, y + 1, sub_trie, match_set);
        }
        board[x][y] = temp;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        size_t words_size = words.size();
        if (words_size == 0)
            return {};
        m = board.size();
        if (m == 0)
            return {};
        n = board[0].size();
        if (n == 0)
            return {};
        // build trie
        auto trie = make_shared<Trie>();
        for (size_t i = 0; i < words_size; ++i)
            insert_word(trie, words[i], 0, i);
        // dfs search
        set<int> match_set;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (match_set.size() == words_size)
                    return words;
                dfs(board, i, j, trie, match_set); //try every position
            }
        }
        vector<string> result;
        for (auto i : match_set)
            result.push_back(words[i]);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board{
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 't'},
        {'i', 'f', 'l', 'v'}},
        board1{
            {'a'}};
    vector<string> words{
        "oath", "pea", "eat", "rain", "eate", "eak", "eaklvte", "eaklvt", "etv", "etp"},
        words1{"a"};
    println(s.findWords(board, words));
    return 0;
}
