#include <iostream>
#include <map>
#include <queue>
using namespace std;


struct route {
    int depart_time, arrive_time, from, to;
};

struct status {
    int city; // where he is
    int arrive_time;
    int literals;

    bool operator < (const status &t) const {
        return literals > t.literals;
    }
};

int dijstra(int from, int to, vector<route> *edges) {
    priority_queue <status> q;

    q.push((status){from, 18, 0});

    while(!q.empty()) {
        status cur = q.top();
        q.pop();

        if (cur.city == to)
            return cur.literals;

        for (size_t i = 0; i < edges[cur.city].size(); i++) {
            route temp = edges[cur.city][i];

            if (cur.arrive_time > temp.depart_time) {
                q.push((status){temp.to, temp.arrive_time, cur.literals + 1});
            }

            if (cur.arrive_time <= temp.depart_time) {
                q.push((status){temp.to, temp.arrive_time, cur.literals});
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (size_t cnt = 0; cnt < n; cnt++) {
        int m;
        cin >> m;
        string c1, c2;

        map<string, int> cities;
        vector<route> edges[1010];

        int depart_time, travel_time, arrive_time;
        // cout << "--------------------------------" << endl << "cnt : " << cnt << " m : " << m << endl;

        for (size_t i = 0; i < m; i++) {
            cin >> c1 >> c2 >> depart_time >> travel_time;

            // change 18:00 - 06:00 to 18:00 - 30:00
            depart_time = depart_time < 6 ? depart_time + 24 : depart_time;
            arrive_time = depart_time + travel_time;

            if ((depart_time > 30 ||  depart_time < 18) ||
                (arrive_time > 30 ||  arrive_time < 18))
                continue;

            // cout << "depart : " << depart_time % 24 << endl
            //      << "arrive : " << arrive_time % 24 << endl;
            //
            // cout << c1 << " " << c2 << endl << depart_time << " "<< travel_time << endl << endl;

            int from, to;
            if (cities.find(c1) == cities.end()) {
                cities[c1] = from = cities.size();
            }
            else {
                from = cities[c1];
            }

            if (cities.find(c2) == cities.end()) {
                cities[c2] = to = cities.size();
            }
            else {
                to = cities[c2];
            }

            edges[from].push_back((route){depart_time, arrive_time, from, to});
        }

        cin >> c1 >> c2;

        cout << "Test Case " << cnt + 1 << "." << endl;

        if (cities.find(c1) == cities.end() || cities.find(c2) == cities.end()) {
            cout << "There is no route Vladimir can take." << endl;
            continue;
        }

        int from = cities[c1], to = cities[c2];
        int literals = dijstra(from, to, edges);
        if (literals == -1)
            cout << "There is no route Vladimir can take." << endl;
        else
            cout << "Vladimir needs " << literals << " litre(s) of blood." << endl;
    }
    return 0;
}
