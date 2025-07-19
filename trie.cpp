#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long 

class Node{
private: 
    vector<Node*> arr;
    bool flag;

public: 
    Node(){
        arr.resize(26,NULL);
        flag=false;
    }

    // Manage End flag
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }

    bool exists(char c){
        return (arr[c-'a'] != NULL);
    }

    // Make a new link
    void set(Node* n, char c){
        arr[c-'a']=n;
    }

    Node* get(char c){
        return arr[c-'a'];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node* iter = root;

        for(int i=0; i<n; i++){
            // Doesnt Exist? Create new
            if(!iter->exists(word[i])){
                Node* tmp = new Node();
                iter->set(tmp, word[i]);
            }

            // Move iter
            iter = iter->get(word[i]);
            
        }
        iter->setEnd();
    }
    
    bool search(string word) {
        int n = word.length();
        Node* iter = root;

        for(int i=0; i<n; i++){
            if(!iter->exists(word[i]))  return false;
            else iter = iter->get(word[i]);
        }
        return iter->isEnd();
    }       
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* iter = root;

        for(int i=0; i<n; i++){
            if(!iter->exists(prefix[i]))  return false;
            else iter = iter->get(prefix[i]);
        }
        return true;
    }

    // Search for the longest prefix of the word w in the trie
    int longestPrefix(string w) {
        int n = w.length(), ans=0;
        Node* iter = root;

        for(int i=0; i<n; i++){
            if(!iter->exists(w[i]))  return ans;

            ans++;
            iter = iter->get(w[i]);
        }
        return ans;
    }
};

void solve()
{
    Trie t; 
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

