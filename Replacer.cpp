#include <iostream>
#include <vector>
using namespace std;
class Replacer{
    private:
        // #TODO:turn into list
        vector<int> start,end;
        string word;

        string wordReplace(string find,string replace,int n){
            for(int i = 0;i<word.size();i++){
                if(word.at(i)==find.at(0)){
                    start.push_back(i);
                    string temp = word.substr(i);
                    if(check(temp, find)){
                        word.erase(i,find.length());
                        word.insert(i,replace);
                        i+=replace.length()-find.length();
                    }
                }
            }
            return word;
        }

        bool check(string temp,string find){
            int i = 0;
            for(;i<find.length();i++){
                if( temp.length()<find.length() || temp.at(i)!=find.at(i)){
                    start.pop_back();
                    return false;
                }
            }
            end.push_back(i+start.back());
            return true;
        }
    public:
        Replacer(){
            word = "";
        }
        Replacer(string str){
            word = str;
        }
        string getWord(){
            return word;
        }

        string replace(string find,string replace){
            return wordReplace(find,replace,0);
        }

        void printAll(){
            string str{"ReplaceHelper["};
            for(int i = 0;i<start.size();i++)
            {
                str.append(" Start:"+to_string(start.at(i))+" End:"+to_string(end.at(i)));
            }
            cout << str+"]";
        }
};