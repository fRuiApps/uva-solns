#include <vector>
using namespace std;
 

template<typename T> vector<int> find_lis(vector<T> &a)
{
	vector<int> b, p(a.size());
	int u, v;
 
	if (a.size() < 1) return b;
 
	b.push_back(0);
 
	for (int i = 1; i < (int)a.size(); i++) {
		if (a[b.back()] < a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}
 

#include <cstdio>
int main()
{
	int a[] = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> lis = find_lis(seq);
 
	for (unsigned i = 0; i < lis.size(); i++)
		printf(i+1 < lis.size() ? "%d " : "%d\n", seq[lis[i]]);
 
	return 0;
}
