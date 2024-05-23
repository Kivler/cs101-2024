#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class myString
{
    private:
        string m_str;
    public:
        myString(string s) {
            m_str = s;
        }
};

class ReadClass
{
    public:
        void showClass() {
            int n = 0;
            ifstream in("main.cpp");
            if (in.fail()) {
                cout << "Error to open file." << endl;
                return;
            }

            string line;

            while (getline(in, line)) {
                if (line.rfind("class", 0) == 0) {
                    n++;
                }
            }

            in.clear();
            in.seekg(0, ios::beg);

            cout << n << " class in main.cpp" << endl;

            while (getline(in, line)) {
                if (line.rfind("class", 0) == 0) {
                    cout << line << endl;
                }
            }

            in.close();
        }
};

int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
