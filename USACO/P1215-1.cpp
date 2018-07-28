#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 21;
int a[3];
bool state[maxn][maxn];
vector<int> ans;
#define COPY(dst, src) memcpy(dst, src, sizeof(dst))
void dfs(int *b) {
  if (state[b[0]][b[2]])
    return;
  state[b[0]][b[2]] = true;
  int c[3];
  COPY(c, b);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (i != j) {
        // pour i to j
        if (b[i] > a[j] - b[j]) {
          c[i] = b[i] - (a[j] - b[j]);
          c[j] = a[j];
          dfs(c);
        } else {
          c[i] = 0;
          c[j] += b[i];
          dfs(c);
        }
        // 还原状态,以便下一次搜索
        COPY(c, b);
      }
}
int main() {
  while (cin >> a[0] >> a[1] >> a[2]) {
    memset(state, false, sizeof(state));
    int cur[3]={0, 0, a[2]};
    dfs(cur);
    // output ans
    ans.clear();
    for (int i = 0; i <= a[2]; i++)
      if (state[0][i])
        ans.push_back(i);
    for (size_t i = 0; i + 1 < ans.size(); i++)
      cout << ans[i] << " ";
    cout << *ans.rbegin() << std::endl;
  }
  return 0;
}