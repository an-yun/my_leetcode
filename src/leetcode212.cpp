#include "zuo/ioutils.hpp"
#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <memory>

using namespace std;
class Trie
{
    bool leave;
    shared_ptr<Trie> nodes[26];
    Trie(bool leave = false):leave(leave){}
};
class Solution
{
  public:
    void dfs(vector<vector<char>> &board, vector<string> &words, size_t start, int x, int y, int m, int n, size_t words_size, vector<bool> &continue_matched, vector<bool> &matched_words)
    {
        if(find(continue_matched.begin(), continue_matched.end(), true) == continue_matched.end()) // no word can match
            return;
        for (size_t i = 0; i < words_size; ++i)
        {
            if (continue_matched[i] && start >= words[i].size()) // for match case
            {
                matched_words[i] = true;
                continue_matched[i] = false;
            }
        }
        if (x < 0 || x >= m || y < 0 || y >= n) // edge case
            return;
        char temp_char = board[x][y]; // for save memory
        vector<bool> temp_continue_matched = continue_matched;
        for (size_t i = 0; i < words_size; ++i)
        {
            if (continue_matched[i] && temp_char == words[i][start]) // for match case
                board[x][y] = '\0';
            else
                continue_matched[i] = false;
        }
        if(find(continue_matched.begin(), continue_matched.end(), true) != continue_matched.end())
        {
            dfs(board, words, start + 1, x - 1, y, m, n, words_size, continue_matched, matched_words);
            dfs(board, words, start + 1, x + 1, y, m, n, words_size, continue_matched, matched_words);
            dfs(board, words, start + 1, x, y - 1, m, n, words_size, continue_matched, matched_words);
            dfs(board, words, start + 1, x, y + 1, m, n, words_size, continue_matched, matched_words);
        }

        board[x][y] = temp_char; // restore board[x][y]
        continue_matched = temp_continue_matched;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        size_t words_size = words.size();
        if (words_size == 0)
            return {};
        int m = board.size();
        if (m == 0)
            return {};
        int n = board[0].size();
        if (n == 0)
            return {};
        // dfs search
        vector<bool> continue_matched(words_size, true), matched_words(words_size, false);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (find(matched_words.begin(), matched_words.end(), false) != matched_words.end()) // if not all words are matched, continue to try
                {
                    dfs(board, words, 0, i, j, m, n, words_size, continue_matched, matched_words); //try every position
                }
                else
                    return words;
            }
        }
        vector<string> result;
        for (size_t i = 0; i < words_size; ++i)
        {
            if (matched_words[i])
                result.push_back(words[i]);
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
        {'i', 'f', 'l', 'v'}};
    vector<string> wrods{"oath", "pea", "eat", "rain","eate","eak","eaklvte","eaklvt","etv","etp"};
    println(s.findWords(board, wrods));
    return 0;
}
