#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    string name = "Tachera Sasi";
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << name ;
    cout << endl;

    return 0;
}
