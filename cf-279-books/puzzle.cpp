#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, t, prev = 0, tmp;
    cin >> n >> t;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        prev = prefix[i+1] = prev + tmp;
    }

    int max_span = -1;
    int start = 0;
    for (int stop = 1; stop <= n; stop++) {
        if (prefix[stop] < t) continue;

        // int step = (stop - start) / 2;
        // int current = start + step;
        // int prev_start = current;

        for (int current = start; current < stop; current++) {
        // while (true) {
            int diff = prefix[stop] - prefix[current];
            int span = stop - current;
            if (diff == t) {
                if (span > max_span)
                    max_span = span;
                // start = current;
            }
            // a, b, ..., c, d
            // Check if either [a,c] or [b,d] has a score less than t
            else if (diff > t) {
                int ac = prefix[stop - 1] - prefix[current];
                int bd = prefix[stop] - prefix[current + 1];
                if (ac < t || bd < t) {
                    if (span - 1 > max_span)
                        max_span = span - 1;
                }
            }

            // if (current == start) break;

            // step = (step == 1 ? 1 : step / 2);

            // t = (prefix[stop] - prefix[current] < k) ? current - step : current + step;
            // if (t == prev_start) break;
            // prev_start = current;
            // current = t;
        }
    }
    cout << ((max_span == -1) ? n : max_span) << endl;
    return 0;
}
