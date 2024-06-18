#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> void print(T arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}

#define it(a) begin(a), end(a) 

template <typename T>
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> getOrderedSet() {
  return tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>();
}

// TC: O(N * (log N + 2 * (log n))) = O(N log N); N = no of unique values; n = size of power vector;
// SC: O(N);
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = power.size();
        sort(it(power));

        long long res = 0ll;

        vector<long long> mem(5);

        auto os = getOrderedSet<int>();

        for(auto i: power) {
            os.insert(i);
        }

        long long ans = 0;

        for(int i=os.size()-1; i>=0; i--) {
            long long nt = mem[1];

            int damage = *os.find_by_order(i);
            auto nextDamagePossible = os.order_of_key(damage+3);

            long long freq = upper_bound(it(power), damage) - lower_bound(it(power), damage);

            long long t = freq * (long long)damage + mem[nextDamagePossible-i];

            long long ans = max(nt, t);

            res = max(ans, res);

            mem[0] = ans;
            mem.insert(begin(mem), 0);
            mem.pop_back();
        }

        return mem[1];
    }
};
