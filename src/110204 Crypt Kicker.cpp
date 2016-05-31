#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>
#include <string.h>
#include <stdio.h>
#include <numeric>
#include <float.h>

using namespace std;

struct Poker {
    char suite;
    int value;
};
bool operator<(Poker p1, Poker p2) {
    return p1.value < p2.value;
}

bool sameSuite(vector<Poker> v) {
    for (int i = 1; i < v.size(); i++)
        if (v[i].suite != v[0].suite) return false;
    return true;
}

int maxPoker(vector<Poker> v1, vector<Poker> v2) {
    for (int i = v1.size() - 1; i >= 0; i--) {
        if (v1[i].value > v2[i].value) return -1;
        else if (v1[i].value < v2[i].value) return 1;
    }
    
    return 0;
}

int f8(vector<Poker> v1, vector<Poker> v2) {
    int i1 = -1, i2 = -1;
    
    if (sameSuite(v1)) {
        if (v1[4].value - v1[0].value == 4) {
            i1 = v1[4].value;
        }
    }
    
    if (sameSuite(v2)) {
        if (v2[4].value - v2[0].value == 4) {
            i2 = v2[4].value;
        }
    }
    
    if (i1 > i2) return -1;
    else if (i1 < i2) return 1;
    
    
    return 0;
}

int f7(vector<Poker> v1, vector<Poker> v2) {
    int i1 = -1, i2 = -1;
    
    if (v1[3].value == v1[0].value) i1 = v1[3].value;
    if (v2[3].value == v2[0].value) i2 = v2[3].value;
    
    if (i1 > i2) return -1;
    else if (i1 < i2) return 1;
    
    return 0;
}

int f6(vector<Poker> v1, vector<Poker> v2) {
    int i1 = -1, i2 = -1;
    
    if (v1[1].value == v1[0].value && v1[4].value == v1[2].value) i1 = v1[2].value;
    if (v1[2].value == v1[0].value && v1[4].value == v1[3].value) i1 = v1[0].value;
    
    if (v2[1].value == v2[0].value && v2[4].value == v2[2].value) i2 = v2[2].value;
    if (v2[2].value == v2[0].value && v2[4].value == v2[3].value) i2 = v2[0].value;
    
    if (i1 > i2) return -1;
    else if (i1 < i2) return 1;
    
    return 0;
}

int f5(vector<Poker> v1, vector<Poker> v2) {
    if (sameSuite(v1) && sameSuite(v2)) {
        return maxPoker(v1, v2);
    }
    else if (sameSuite(v1)) return -1;
    else if (sameSuite(v2)) return 1;
    return 0;
}

int f4(vector<Poker> v1, vector<Poker> v2) {
    int i1 = -1, i2 = -1;
    
    if (v1[4].value - v1[0].value == 4) i1 = v1[0].value;
    if (v2[4].value - v2[0].value == 4) i2 = v2[0].value;
    
    if (i1 > i2) return -1;
    else if (i1 < i2) return 1;
    return 0;
}

int f3(vector<Poker> v1, vector<Poker> v2) {
    int i1 = -1, i2 = -1;
    
    if (v1[2].value == v1[0].value) i1 = v1[0].value;
    if (v1[2].value == v1[4].value) i1 = v1[2].value;
    if (v2[2].value == v2[0].value) i2 = v2[0].value;
    if (v2[2].value == v2[4].value) i2 = v2[2].value;
    
    if (i1 > i2) return -1;
    else if (i1 < i2) return 1;
    
    return 0;
}

int f2(vector<Poker> v1, vector<Poker> v2) {
    int pos = 0;
    vector<Poker> tv1, tv2, val1, val2;
    
    while (pos < v1.size()) {
        if (pos == v1.size() - 1) {
            tv1.push_back(v1[pos]); pos += 1;
        }
        else if (v1[pos].value != v1[pos + 1].value) {
            tv1.push_back(v1[pos]); pos += 1;
        }
        else {
            val1.push_back(v1[pos]);
            pos += 2;
        }
    }
    
    pos = 0;
    while (pos < v2.size()) {
        if (pos == v2.size() - 1) {
            tv2.push_back(v2[pos]); pos += 1;
        }
        else if (v2[pos].value != v2[pos + 1].value) {
            tv2.push_back(v2[pos]); pos += 1;
        }
        else {
            val2.push_back(v2[pos]);
            pos += 2;
        }
    }
    
    int r = 0;
    if (val1.size() == 2 && val2.size() == 2) {
        r = maxPoker(val1, val2);
        if (r == 0)
            r = maxPoker(tv1, tv2);
        return r;
    }
    else if (val1.size() == 2) {
        return -1;
    }
    else if (val2.size() == 2) {
        return 1;
    }
    
    return 0;
}

int f1(vector<Poker> v1, vector<Poker> v2) {
    int pos = 0;
    vector<Poker> tv1, tv2, val1, val2;
    
    while (pos < v1.size()) {
        if (pos == v1.size() - 1) {
            tv1.push_back(v1[pos]); pos += 1;
        }
        else if (v1[pos].value != v1[pos + 1].value) {
            tv1.push_back(v1[pos]); pos += 1;
        }
        else {
            val1.push_back(v1[pos]);
            pos += 2;
        }
    }
    
    pos = 0;
    while (pos < v2.size()) {
        if (pos == v2.size() - 1) {
            tv2.push_back(v2[pos]); pos += 1;
        }
        else if (v2[pos].value != v2[pos + 1].value) {
            tv2.push_back(v2[pos]); pos += 1;
        }
        else {
            val2.push_back(v2[pos]);
            pos += 2;
        }
    }
    
    int r = 0;
    if (val1.size() == 1 && val2.size() == 1) {
        r = maxPoker(val1, val2);
        if (r == 0)
            r = maxPoker(tv1, tv2);
        return r;
    }
    else if (val1.size() == 1) {
        return -1;
    }
    else if (val2.size() == 1) {
        return 1;
    }
    
    return 0;
}

Poker parse(string s) {
    Poker result;
    result.suite = s[1];
    if (s[0] == 'T') result.value = 10;
    else if (s[0] == 'J') result.value = 11;
    else if (s[0] == 'Q') result.value = 12;
    else if (s[0] == 'K') result.value = 13;
    else if (s[0] == 'A') result.value = 14;
    else result.value = s[0] - '0';
    
    return result;
}

int check(vector<Poker> v1, vector<Poker> v2) {
    if (f8(v1, v2) != 0) return f8(v1, v2);
    if (f7(v1, v2) != 0) return f7(v1, v2);
    if (f6(v1, v2) != 0) return f6(v1, v2);
    if (f5(v1, v2) != 0) return f5(v1, v2);
    if (f4(v1, v2) != 0) return f4(v1, v2);
    if (f3(v1, v2) != 0) return f3(v1, v2);
    if (f2(v1, v2) != 0) return f2(v1, v2);
    if (f1(v1, v2) != 0) return f1(v1, v2);
    return maxPoker(v1, v2);
}

int main() {
    string s;
    
    while (cin >> s) {
        vector<Poker> v1, v2;
        v1.push_back(parse(s));
        
        for (int i = 1; i <= 4; i++) {
            cin >> s; v1.push_back(parse(s));
        }
        
        for (int i = 0; i <= 4; i++) {
            cin >> s; v2.push_back(parse(s));
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        int r = check(v1, v2);
        if (r == -1) cout << "Black wins." << endl;
        else if (r == 1) cout << "White wins." << endl;
        else cout << "Tie." << endl;
    }
    
    return 0;
}
