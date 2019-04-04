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
    shared_ptr<Trie> nodes[26];
    Trie(int index = -1) : index(index) {}
};
void insert_word(shared_ptr<Trie> trie, const string &word, int index = -1)
{
    for (auto ch : word)
    {
        int i = ch - 'a';
        if (trie->nodes[i] == nullptr)
            trie->nodes[i] = make_shared<Trie>();
        trie = trie->nodes[i];
    }
    trie->index = index;
}
class Solution
{
  private:
    int m;
    int n;

  public:
    void dfs(vector<vector<char>> &board, vector<string> &words, int x, int y, shared_ptr<Trie> trie, vector<string> &result)
    {

        if (x < 0 || x >= m || y < 0 || y >= n) // edge case
            return;
        if (board[x][y] == '\0')
            return;
        auto sub_trie = trie->nodes[board[x][y] - 'a'];
        if (sub_trie)
        {
            if (sub_trie->index != -1)
            {
                result.push_back(words[sub_trie->index]);
                sub_trie->index = -1;
            }
            char temp = board[x][y]; // for save memory
            board[x][y] = '\0';
            dfs(board, words, x - 1, y, sub_trie, result);
            dfs(board, words, x + 1, y, sub_trie, result);
            dfs(board, words, x, y - 1, sub_trie, result);
            dfs(board, words, x, y + 1, sub_trie, result);
            board[x][y] = temp;
        }
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
            insert_word(trie, words[i], i);
        // dfs search
        vector<string> result;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (result.size() == words_size)
                    return words;
                dfs(board, words, i, j, trie, result); //try every position
            }
        }
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
