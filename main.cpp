#include <iostream>
#include <sstream>
#include <vector>
#include "funcHandler.h"
#include "divMe.h"

using namespace std;

int strToInt(const string &text) {
    int number;
    istringstream iss(text);
    if (iss >> number) {
        if (!iss.good()) {
            return number;
        } else {
            throw runtime_error("Can't convert string to int");
        }
    } else {
        throw runtime_error("Can't convert string to int");
    }
}

vector<string> split_line(const string &line) {
    istringstream iss(line);
    vector<string> results(istream_iterator<string>{iss},
                           istream_iterator<string>());
    return results;
};

const string APPINFO = "my-jit: ";

const string HELP = R"BLOCK(exec -- execute function
modify [value] -- changes value in function)BLOCK";

int main() {
    string line;
    //cout<< sizeof(funcComands);
    cout << APPINFO;
    while (getline(cin, line)) {
        vector<string> parsedLine = split_line(line);
        if (parsedLine.empty()) {
            cout << HELP<<endl;
            continue;
        }
        if (parsedLine[0] == "run") {
            if(parsedLine.size() > 1 ){
                if(parsedLine.size() == 3 && parsedLine[1] == "-m"){
                    modify(strToInt(parsedLine[2]));
                } else{
                    cout << HELP << endl;
                    continue;
                }
            }
            int arg;
            funcHandler handler(asmCode, sizeof(asmCode));
            cout<< "Print argument: ";
            cin >> arg;
            cout << handler.apply(arg);
            return 0;
        } else {
            cout << HELP<<endl;
        }
        cout << APPINFO;
    }
    return 0;
}