#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	set<int> s;
	int n, val;

	cin >> n;
	while (n--) {
		cin >> val;
		s.insert(val);
	}

	set<int>::iterator i;
	for (i = s.begin(); i != s.end(); i++)
		cout << *i << "\n";

	return 0;
}
