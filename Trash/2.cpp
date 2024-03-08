#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubstring(const string& s1, const string& s2) {
    size_t found = s2.find(s1);
    return (found != string::npos);
}

int findLargestSetSize(const vector<string>& strings) {
    vector<string> sortedStrings = strings;
    sort(sortedStrings.begin(), sortedStrings.end(), [](const string& s1, const string& s2) {
        return s1.length() > s2.length();
    });

    int setSize = 0;
    vector<bool> isIncluded(strings.size(), false);

    for (const string& str : sortedStrings) {
        bool canInclude = true;
        for (int i = 0; i < setSize; ++i) {
            if (isSubstring(str, sortedStrings[i])) {
                canInclude = false;
                break;
            }
        }

        if (canInclude) {
            isIncluded[setSize] = true;
            ++setSize;
        }
    }

    return setSize;
}

int main() {
    // Example usage
    // vector<string> strings = {"b", "aab", "ab", "aabab", "ab", "ababa"};
    vector<string> strings = {"abaa","baab","b","bbb"};

    int maxSize = findLargestSetSize(strings);

    cout << "Size of the largest set: " << maxSize << endl;

    return 0;
}
