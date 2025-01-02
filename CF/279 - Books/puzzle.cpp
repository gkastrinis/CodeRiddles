#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b ? a : b); }

int main(void) {
    int n, t;
    cin >> n >> t;
    vector<int> prefix(n);
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        prev = prefix[i] = prev + tmp;
    }

    int max_span = 0;
    int start = 0;
    for (int stop = 0; stop < n; stop++) {
        if (prefix[stop] < t) {
            max_span++;
            continue;
        }

        for (int current = start; current <= stop; current++) {
            int diff = prefix[stop] - (current == 0 ? 0 : prefix[current - 1]);
            int span = stop - current + 1;

            if (diff <= t) {
                max_span = max(max_span, span);
                start = (diff == t ? current + 1 : current);
                break;
            }

            // a, b, ..., c, d
            // Check if either [a,c] or [b,d] has a score less than t
            /*else if (diff > t)*/
            int ac = prefix[stop - 1] - prefix[current];
            int bd = prefix[stop] - prefix[current + 1];
            if ((ac < t || bd < t) && span - 1 > max_span)
                max_span = span - 1;
            start = current + 1;
        }
    }
    cout << max_span << endl;
    return 0;
}
