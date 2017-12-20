#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int un = 1;
	int deux = 2;

	vector<int *> vect_int;

	vect_int.push_back(&un);
	vect_int.push_back(&deux);

	for (int i = 0; i < vect_int.size(); i++)
	{
		cout << *vect_int[i];
	}


	return 1;
}