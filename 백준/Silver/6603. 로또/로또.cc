#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Combination(vector<int> arr, vector<int> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for(int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";
        cout << endl;
    }
    else if (depth == arr.size())  // depth == n // 계속 안뽑다가 r 개를 채우지 못한 경우는 이 곳에 걸려야 한다.
    {
        return;
    }
    else
    {
        // arr[depth] 를 뽑은 경우
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        // arr[depth] 를 뽑지 않은 경우
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
	while(1)
	{
		int k;
		cin >> k;
		if (k == 0)
			return 0;
		vector<int> list;
		while (k--)
		{
			int num;
			cin >> num;
			list.push_back(num);
		}
		vector<int> comb(6);
		Combination(list, comb, 6, 0, 0);
		cout << endl;
	}
}