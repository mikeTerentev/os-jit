#include <iostream>
#include <sstream>
#include <vector>
#include "funcHandler.h"
#include "divMe.h"
#include <iterator>

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

const string HELP = R"BLOCK(run -- execute function
run -m [value] -- modity and execute function )BLOCK";

int main() {
    string line;
    //cout<< sizeof(funcComands);
    cout << APPINFO;
    while (getline(cin, line)) {
        vector<string> parsedLine = split_line(line);
        if (parsedLine.empty()) {
            cout << HELP << endl << APPINFO;
            continue;
        }
        if (parsedLine[0] == "run") {
            if (parsedLine.size() > 1) {
                if (parsedLine.size() == 3 && parsedLine[1] == "-m") {
                    try {
                        int x = 0;
                        x = strToInt(parsedLine[2]);
                        modify(x);
                    } catch (exception &e) {
                        cout << HELP << endl << APPINFO;
                        continue;
                    }
                } else {
                    cout << HELP << endl << APPINFO;
                    continue;
                }
            }
            string arg;
            funcHandler handler(asmCode, sizeof(asmCode));
            cout << "Print argument: ";
            cin >> arg;
            try {
                cout << handler.apply(strToInt(arg));
                return 0;
            } catch (exception &e) {
                cout << e.what() << endl;
                continue;
            }
        } else {
            cout << HELP << endl << APPINFO;
        }
    }
    return 0;
}