#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // ifstream fin("kite.in");
    ifstream fin(argv[1]);
    if (!fin.good()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    ofstream fout("kite.out");

    int n, k;
    fin >> n >> k;

    vector<int> vals(n);
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i <= n; i++) {
        fin >> vals[i];
        prefix[i + 1] = prefix[i] + vals[i];
    }
    int minI = 0, minJ = n + 1;
    int start = 0;
    //bool foo = false;
    for (int i = 0; i < n; i++) {
        if (prefix[i] < k) continue;

        //foo = false;
        for (int j = start; j <= i; j++) {
            if (prefix[i] - prefix[j] < k) break;

            if (prefix[i] - prefix[j] == k) {
                // cout << "found: " << j << " to " << (i-1) << endl;
                if (i - j < minJ - minI) {
                    minI = j;
                    minJ = i;
                }
                start = j;
            }
        }
        // if (foo) start += 1;
        // cout << endl;
    }
    int result = minJ - minI;
    if (result == n + 1) result = 0;

    // cout << minI << " " << minJ << endl;
    cout << (result) << endl;
    fout << result << endl;

    return 0;
}
