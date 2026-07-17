class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(),wordList.end(),endWord)==wordList.end()
            || beginWord == endWord){
                return 0;
        }

        unordered_map<string,vector<string>> nei;
        wordList.push_back(beginWord);
        for(auto s:wordList){
            for(int i=0;i<s.length();i++){
                string pattern=s.substr(0,i)+"*"+s.substr(i+1);
                nei[pattern].push_back(s);
            }
        }

        set<string> visit;
        visit.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int res=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=1;i<=size;i++){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return res;
                }
                for(int j=0;j<word.length();j++){
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for(auto s:nei[pattern]){
                        if(!visit.count(s)){
                            visit.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            res++;
        }
        return 0;

    }
};
