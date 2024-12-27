#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);

    int n, k, prev = 0, t;
    fin >> n >> k;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) {
        fin >> t;
        prev = prefix[i] = prev + t;
    }

    int min_solution = n + 1;
    int start = 0;
    for (int stop = 0; stop < n; stop++) {
        if (prefix[stop] < k) continue;

        int step = (stop - start) / 2;
        int current = start + step;
        int prev_start = current;

        while (true) {
            if (prefix[stop] - prefix[current] == k) {
                if (min_solution > stop - current)
                    min_solution = stop - current;
                start = current;
            }

            if (current == start) break;

            step = (step == 1 ? 1 : step / 2);

            t = (prefix[stop] - prefix[current] < k) ? current - step : current + step;
            if (t == prev_start) break;
            prev_start = current;
            current = t;
        }
    }
    if (min_solution == n + 1) min_solution = 0;
    ofstream fout("kite.out");
    fout << min_solution << endl;
    return 0;
}
