#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int> mp;
vector<int> in;
void inorder(int inl, int inr, int index) {
	if (inl > inr) return;
	int p = min_element(in.begin()+inl, in.begin()+inr+1) - (in.begin()+inl);
	int minn = in[inl+p];
	mp[minn] = index;
	inorder(inl, inl+p-1, 2*index);
	inorder(inl+p+1, inr, 2*index+1);
}
bool cmp(int a, int b) { return mp[a] < mp[b]; }
int main() {
	int n;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	inorder(0, n-1, 1);
	sort(in.begin(), in.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (i != 0) printf(" ");
		printf("%d", in[i]);
	}
	return 0;
}
