#include <bits/stdc++.h>

using namespace std;

struct node {
  node *l{}, *r{};
  int v{};
  node(int v) : v(v) {}
  node(node *l, node *r) : l(l), r(r) {
    if (l) v += l->v;
    if (r) v += r->v;
  }
};
vector<node*> st;
node* build(int l, int r) {
  if (l == r) return new node(0);
  int m = l + r >> 1;
  return new node(build(l, m), build(m + 1, r));
}
node* add(node* n, int l, int r, int x) {
  if (l == r) return new node(n->v + 1);
  int m = l + r >> 1;
  if (x <= m) return new node(add(n->l, l, m, x), n->r);
  else        return new node(n->l, add(n->r, m + 1, r, x));
}
int sum(node* n, int l, int r, int s, int e) {
  if (e < l || r < s || !n) return 0;
  if (s <= l && r <= e) return n->v;
  int m = l + r >> 1;
  return sum(n->l, l, m, s, e) + sum(n->r, m + 1, r, s, e);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> mp;
  for(int & i : a) {
    cin >> i;
    i = mp.count(i) ? mp[i] : mp[i] = mp.size();
  }

  vector<vector<int>> last(mp.size());
  for(int i =n-1; ~i; --i) last[a[i]].push_back(i);
  node* init = build(0, n);
  for(auto & v : last) init = add(init, 0, n, v.back()), v.pop_back();
  st.push_back(init);

  for(int i =1; i<n; ++i) {
    if (last[a[i - 1]].size()) {
      st.push_back(add(st.back(), 0, n, last[a[i - 1]].back()));
      last[a[i - 1]].pop_back();
    } else {
      st.push_back(st.back());
    }
  }
  
  int m, q = 0;
  cin >> m;
  while(m--) {
    int l, r;
    cin >> l >> r;
    l += q - 1;
    cout << (q = sum(st[l], 0, n, l, r - 1)) << '\n';
  }
}