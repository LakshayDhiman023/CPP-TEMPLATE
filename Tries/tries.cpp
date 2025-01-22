#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node * links[26];
    bool flag = 0;
};

class Trie {
    private:
        Node * root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->links[word[i] - 'a'] == NULL){
                node->links[word[i] - 'a'] = new Node();

            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root;

        for(int i = 0; i < word.size(); i++){
            if(node->links[word[i] - 'a'] == NULL) return 0;
            else{
                node = node->links[word[i] - 'a'];
            }
        }
        if(node->flag) return 1;
        return 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node = root;

        for(int i = 0; i < prefix.size(); i++){
            if(node->links[prefix[i] - 'a'] == NULL) return 0;
            else{
                node = node->links[prefix[i] - 'a'];
            }
        }
        return 1;
    }
};