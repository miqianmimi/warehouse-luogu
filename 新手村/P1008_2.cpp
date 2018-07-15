#include <cstdio>
#include <cstring>
bool ft[10];
void work(int i) {
	while (i) ft[i % 10] = true, i /= 10;
}
int main() {
	for (int i = 100; i <= 999; i++) {
		int j = i * 2;
		int k = i * 3;
		if (k > 999) continue;
		memset(ft, false, sizeof(ft));
		work(i);
		work(j);
		work(k);
		bool flag = true;
		for (int l = 1; l <= 9; l++)
			if (!ft[l]) flag = false;
		if (flag)
			printf("%d %d %d\n", i, j, k);
	}
	return 0;
}
