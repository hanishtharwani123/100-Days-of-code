// 44. Word Search
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countModifiedFiles(const vector<int>& ignored, const vector<int>& tracked) {
    unordered_set<int> ignoredSet(ignored.begin(), ignored.end());
    unordered_set<int> trackedSet(tracked.begin(), tracked.end());
    int modifiedCount = 0;

    for (int file : ignoredSet) {
        if (trackedSet.count(file)) {
            modifiedCount++;
        }
    }

    return modifiedCount;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> ignored(K);
        vector<int> tracked(K);

        for (int i = 0; i < K; ++i) {
            cin >> ignored[i];
        }

        for (int i = 0; i < K; ++i) {
            cin >> tracked[i];
        }

        int modifiedFiles = countModifiedFiles(ignored, tracked);
        int unmodifiedFiles = K - modifiedFiles;
        int ignoredUnmodified = N - K + modifiedFiles;
        int trackedUnmodified = M - K + modifiedFiles;

        cout << unmodifiedFiles << " " << ignoredUnmodified << " " << trackedUnmodified << endl;
    }

    return 0;
}
