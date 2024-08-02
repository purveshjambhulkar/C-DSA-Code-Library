//approach 2 - using trie - not good
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        childCount = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        for (char& c : word) {
            c = tolower(c);
        }
        insertUtil(root, word);
    }

    void lcp(string str, string& ans) {
        TrieNode* current = root;
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (current->childCount == 1 && !current->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'a';
                current = current->children[index];
            } else {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie();

    // adding all the strings in the trie
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    string str = arr[0];
    string ans = "";

    t->lcp(str, ans);
    return ans;
}

// APPROCH 1 - better

// string longestCommonPrefix(vector<string> &arr, int n) {
//   // Write your code here
//   string ans = "";

//   // traversing first string
//   for (int i = 0; i < arr[0].length(); i++) {
//     char ch = arr[0][i];

//     bool match = true;

//     // for comparing the ch with the other strings
//     for (int j = 1; j < n; j++) {
//       if (arr[j].length() < i || ch != arr[j][i]) {
//         match = false;
//         break;
//       }
//     }

//     if (match == false) {
//       break;
//     } else {
//       ans.push_back(ch);
//     }
//   }

//   return ans;
// }
