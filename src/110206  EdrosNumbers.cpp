#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

void split(const string& s, string delim, vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);

    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i) + ".");
      //   i = ++pos;
      pos += delim.size() + 1;
      i = pos;
      pos = s.find(delim, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string line;
    for (size_t i = 0; i < n; i++) {
        int m, n;

        cin >> m >> n;
        getline(std::cin, line);

        map<string, list<string>> data;
        map<string, int> distance;

        for (size_t j = 0; j < m; j++) {

            getline(std::cin, line);

            // split line
            auto pos = line.find(":");
            string info = line.substr(0, pos);

            vector<string> v;
            split(info, ".,", v);

            // build graph
            for (size_t ii = 0; ii < v.size(); ii++) {
                for (size_t jj = 0; jj < v.size(); jj++) {
                    if (jj != ii)
                        data[v[ii]].push_back(v[jj]);
                }
            }
        }

        // set<string> myset;

        // for (auto each : data) {
        //     cout << each.first << ":" << endl;
        //     // myset.insert(each.first);
        //     for (auto it : each.second) {
        //         cout << "   " << it << endl;
        //         // myset.insert(it);
        //     }
        //     cout << endl;
        // }
        // for (auto each : myset)
        //     cout << each << "?" <<  endl;

        queue<string> bfs;
        bfs.push("Erdos, P.");
        distance["Erdos, P."] = 0;

        while(!bfs.empty()) {

            string name = bfs.front();
            for (auto other : data[name]) {
                if (distance.find(other) == distance.end()) {
                    distance[other] = distance[name] + 1;
                    bfs.push(other);
                }
                // else {
                //     distance[other] = min(distance[other] + 1, distance[other]);
                // }
            }
            bfs.pop();
        }
        
        cout << "Scenario " << (i + 1) << endl;

        for (size_t j = 0; j < n; j++) {
            getline(std::cin, line);
            auto pos = line.find(":");
            string info = line.substr(0, pos);

            cout << info << " ";

            if (distance.find(info) == distance.end()) {
                cout << "infinity";
            }
            else {
                cout << distance[info];
            }
            cout << endl;

        }
    }
    return 0;
}
