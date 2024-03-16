/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode.cn/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (72.00%)
 * Likes:    1597
 * Dislikes: 0
 * Total Accepted:    305.4K
 * Total Submissions: 424.1K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Trie（发音类似 "try"）或者说 前缀树
 * 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
 *
 * 请你实现 Trie 类：
 *
 *
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回
 true（即，在检索之前已经插入）；否则，返回
 * false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为
 prefix ，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 *
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
 *
 *
 */

// @lc code=start
class TrieNode {
public:
  bool is_end_;
  TrieNode *letters_[26];

  TrieNode() {
    is_end_ = false;
    for (size_t i = 0; i < 26; ++i) {
      letters_[i] = nullptr;
    }
  }

  ~TrieNode() {
    for (size_t i = 0; i < 26; ++i) {
      if (letters_[i] != nullptr) {
        delete letters_[i];
      }
    }
  }
};

class Trie {
private:
  TrieNode *root_;

public:
  Trie() { root_ = new TrieNode(); }

  void insert(string word) {
    TrieNode *cur_node = root_;
    for (const char c : word) {
      if (cur_node->letters_[c - 'a'] == nullptr) {
        cur_node->letters_[c - 'a'] = new TrieNode();
      }
      cur_node = cur_node->letters_[c - 'a'];
    }
    cur_node->is_end_ = true;
  }

  bool search(string word) {
    TrieNode *cur_node = root_;
    for (const char c : word) {
      if (cur_node->letters_[c - 'a'] != nullptr) {
        cur_node = cur_node->letters_[c - 'a'];
      } else {
        return false;
      }
    }
    return cur_node->is_end_;
  }

  bool startsWith(string prefix) {
    TrieNode *cur_node = root_;
    for (const char c : prefix) {
      if (cur_node->letters_[c - 'a'] != nullptr) {
        cur_node = cur_node->letters_[c - 'a'];
      } else {
        return false;
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
