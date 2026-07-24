class TrieNode {
public:

    TrieNode* children[26];
    bool isEnd;

    TrieNode() {

        isEnd = false;

        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {

private:

    TrieNode* root;

public:

    Solution() {
        root = new TrieNode();
    }

    // Insert word into Trie
    void insert(string word) {

        TrieNode* current = root;

        for(char ch : word) {

            int idx = ch - 'a';

            if(current->children[idx] == nullptr) {
                current->children[idx] = new TrieNode();
            }

            current = current->children[idx];
        }

        current->isEnd = true;
    }

    // Count children of node
    int countChildren(TrieNode* node, int &index) {

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(node->children[i] != nullptr) {
                count++;
                index = i;
            }
        }

        return count;
    }

    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        // Build Trie
        for(string str : strs) {
            insert(str);
        }

        TrieNode* current = root;

        string ans = "";

        while(true) {

            int index = -1;

            int childCount = countChildren(current, index);

            // LCP condition
            if(childCount != 1 || current->isEnd) {
                break;
            }

            char ch = index + 'a';

            ans += ch;

            current = current->children[index];
        }

        return ans;
    }
};