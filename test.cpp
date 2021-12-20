#include <C:\Users\user\.vscode\Projects\Replacer.cpp>
using namespace std;

int main() {
    Replacer replacer("wordsaregreatare");
    cout << replacer.replace("are","arenot")<<endl;
    replacer.printAll();
}