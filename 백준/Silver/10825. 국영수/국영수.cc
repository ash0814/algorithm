#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
		string name;
		int kor;
		int eng;
		int math;
};

bool comp(Student a, Student b)
{
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			} else
				return a.math > b.math;
		} else
			return a.eng < b.eng;
	} else
		return a.kor > b.kor;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Student> list;

	while (N--)
	{
		Student s;
		cin >> s.name >> s.kor >> s.eng >> s.math;
		list.push_back(s);
	}

	sort(list.begin(), list.end(), comp);

	for (auto s : list)
		cout << s.name << "\n";
}