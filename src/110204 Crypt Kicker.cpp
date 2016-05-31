#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <functional>

#define DEBUG false
using namespace std;


class card {
public:
    int value;
    char suit;
    card(string in) : value(toValue(in[0])), suit(in[1]) {}
    card(char v, char s) : value(toValue(v)), suit(s) {}

    int toValue(char ch) {
        if (ch > '0' && ch <= '9')
            return int(ch - '0');
        else
            switch (ch) {
                case 'T':
                    return 10;
                case 'J':
                    return 11;
                case 'Q':
                    return 12;
                case 'K':
                    return 13;
                case 'A':
                    return 14;
            }
        return -1;
    }

    bool operator < (const card& rhs) { return (*this).value < rhs.value; }
    bool operator <= (const card& rhs) { return (*this).value <= rhs.value; }
    bool operator > (const card& rhs) { return (*this).value > rhs.value; }
    bool operator >= (const card& rhs) { return (*this).value >= rhs.value; }
    bool operator == (const card& rhs) { return (*this).value == rhs.value; }
};


int normal(int value) {
    if (value < 0) return -1;
    if (value > 0) return 1;
    return 0;
}

int toValue(vector<card> &p1) {
    int sum = 0;
    int digit = 1;
    for (int i = int(p1.size()) - 1; i >= 0; --i) {
        sum += p1[i].value * digit;
        digit *= 100;
    }
    return sum;
}

bool sameSuit(vector<card> &p1) {
    for (int i = 1; i < 5; ++i)
        if (p1[i].suit != p1[0].suit) return false;
    return true;
}

bool consecutiveValue(vector<card> &p1) {
    for (int i = 1; i < 5; ++i)
        if (p1[i-1].value - p1[i].value != 1) return false;
    return true;
}

int compareHighCard(vector<card> &p1, vector<card> &p2) {
    return normal(toValue(p1) - toValue(p2));
}

// Pair
int onePair(vector<card> &p1) {
    for (int i = 1; i < 5; ++i) {
        if (p1[i-1].value == p1[i].value) {

            int value = 0;
            value += p1[i].value;

            for (int j = 0; j < i -1; ++j) {
                value *= 100;
                value += p1[j].value;
            }
            for (int j = i+1; j < 5; ++j) {
                value *= 100;
                value += p1[j].value;
            }
            return value;
        }
    }
    return 0;
}

// two pairs
int twoPairs(vector<card> &p1) {
    if (p1[0].value == p1[1].value && p1[2].value == p1[3].value)
        return p1[0].value * 10000 + p1[2].value * 100 + p1[4].value;
    else if (p1[1].value == p1[2].value && p1[3].value == p1[4].value)
        return p1[1].value * 10000 + p1[3].value * 100 + p1[0].value;
    else
        return 0;
}

// three of a king
int threeOfAKing(vector<card> &p1) {
    if ( (p1[0].value == p1[2].value) ||
         (p1[1].value == p1[3].value) ||
         (p1[2].value == p1[4].value) )
        return p1[2].value;
    else
        return 0;
}

// straight
int straight(vector<card> &p1) {
    if (consecutiveValue(p1)) return p1[0].value;
    else return 0;
}

// cardFlush
int cardFlush(vector<card> &p1) {
    if (sameSuit(p1)) return toValue(p1);
    else return 0;
}

// full house
int fullHouse(vector<card> &p1) {
    if ( (p1[0].value == p1[1].value && p1[1].value == p1[2].value   && p1[3].value == p1[4].value) ||
         (p1[2].value == p1[3].value && p1[3].value == p1[4].value   && p1[0].value == p1[1].value) )
        return p1[2].value;
    else
        return 0;
}

// four of a king
int fourOfAKing(vector<card> &p1) {
    if ( (p1[0].value == p1[1].value && p1[0].value == p1[2].value && p1[0].value == p1[3].value) ||
         (p1[4].value == p1[1].value && p1[4].value == p1[2].value && p1[4].value == p1[3].value))
        return p1[2].value;
    else
        return 0;
}

// straight cardFlush
int straighFlush(vector<card> &p1) {
    if (sameSuit(p1) && consecutiveValue(p1))
        return p1[0].value;
    else
        return 0;
}

int elegantCompare(vector<card> &p1, vector<card> &p2) {

    vector<function<int(vector<card> &)>> f_compare = {straighFlush, fourOfAKing, fullHouse, cardFlush, straight, threeOfAKing, twoPairs, onePair};

//    if (straighFlush(p1) != straighFlush(p2)) return normal(straighFlush(p1) - straighFlush(p2));
//    if (fourOfAKing(p1) != fourOfAKing(p2)) return normal(fourOfAKing(p1) - fourOfAKing(p2));
//    if (fullHouse(p1) != fullHouse(p2)) return normal(fullHouse(p1) - fullHouse(p2));
//    if (cardFlush(p1) != cardFlush(p2)) return normal(cardFlush(p1) - cardFlush(p2));
//    if (straight(p1) != straight(p2)) return normal(straight(p1) - straight(p2));
//    if (threeOfAKing(p1) != threeOfAKing(p2)) return normal(threeOfAKing(p1) - threeOfAKing(p2));
//    if (twoPairs(p1) != twoPairs(p2)) return normal(twoPairs(p1) - twoPairs(p2));
//    if (onePair(p1) != onePair(p2)) return normal(onePair(p1) - onePair(p2));

     for (auto rule : f_compare) {
         int v1 = rule(p1), v2 = rule(p2);
         int res = normal(v1 - v2);
         if (res != 0)
             return res;
         // if (v1 && v2)
         //     return normal(v1 - v2);
         // else {
         //     if (v1 || v2)
         //         return v1 ? 1 : -1;
         //     else
         //         continue;
         // }
     }
    return compareHighCard(p1, p2);

}


bool compare(card lhs, card rhs) { return lhs.value > rhs.value; }

int main() {
    string line;
    while (getline(std::cin, line)) {
        if (DEBUG) cout << line << endl;
        istringstream iss(line);

        vector<card> person1, person2;
        string temp;

        if (DEBUG) cout << "Origin : ";
        for (int i = 0; i < 5; ++i) {
            iss >> temp;
            person1.push_back(card(temp[0], temp[1]));
            if (DEBUG) cout << person1[i].value << person1[i].suit << " ";
        }
        if (DEBUG) cout << endl << "Sorted : ";
        sort(person1.begin(), person1.end(), compare);

        for (int i = 0; i < 5; ++i)
            if (DEBUG) cout << person1[i].value << person1[i].suit << " ";
        if (DEBUG) cout << endl;

        if (DEBUG) cout << "Origin : ";
        for (int i = 0; i < 5; ++i) {
            iss >> temp;
            person2.push_back(card(temp[0], temp[1]));
            if (DEBUG) cout << person2[i].value << person2[i].suit << " ";
        }
        if (DEBUG) cout << endl << "Sorted : " ;
        sort(person2.begin(), person2.end(), compare);

        for (int i = 0; i < 5; ++i)
            if (DEBUG) cout << person2[i].value << person2[i].suit << " ";
        if (DEBUG) cout << endl ;


        int res = elegantCompare(person1, person2);
        if (res == 0)
            cout << "Tie." << endl;
        if (res == 1)
            cout << "Black wins." << endl;
        if (res == -1)
            cout << "White wins." << endl;

        if (DEBUG) cout << endl;

    }
}
