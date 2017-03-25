#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <random> 
#include <cmath>  

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> p;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		a /= 1024;
		p.push_back(a);
	}
	int sum=0;
	for (int i = 0; i < n; i++){
		sum += p[i];
	}
	int best;
	if (sum % 2 == 0)
		best = sum / 2;
	else
		best = (sum + 1) / 2; 
	int nb=4096;
	vector<int> c;
	set<int> s;
	c.push_back(0); 
	s.insert(0);
	int flag = 0;
	for (int i = n - 1; i >= 0; i--){
		if (flag == 1)
			break;
		for (int j = 0; j < c.size(); j++){
			int b = c[j] + p[i];
			if (b == best){
				nb = best;
				flag = 1;
				break;
			}
			if (b > best){
				if (b < nb)
					nb = b;
				continue;
			}
			if (b<best){
				set<int>::iterator iter = s.find(b);
				if (iter != s.end())
					continue;
				else{
					c.push_back(b);
					s.insert(b);
				}
			}

		}
	}
	
	cout << (long) (nb * 1024) << endl;
	getchar();
	getchar();
	return 0;
}
