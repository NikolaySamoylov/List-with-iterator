#include "list.h"

using namespace std;

// Слияние двух отсортированных списков
template <class T>
void merge(List<T>& l1, List<T>& l2, List<T>& res)
{
	if (l1.empty())
		res = l2;
	if (l2.empty())
		res = l1;
	if (l1.empty() && l2.empty())
		throw "Lists are empty!";
	List<T>::Iterator i = l1.begin();
	List<T>::Iterator j = l2.begin();
	while (i != l1.end() && j != l2.end())
		if (i->data < j->data)
			res.push_back((i++)->data);
		else
			res.push_back((j++)->data);
	while (i != l1.end())
		res.push_back((i++)->data);
	while (j != l2.end())
		res.push_back((j++)->data);
}

int main()
{
  List<int> l1;
  l1.push_back(3);
  l1.push_back(5);
  List<int> l2;
  l2.push_back(2);
  l2.push_back(8);
  l2.push_back(8);
  List<int> l3;
  merge(l1, l2, l3);
  for (List<int>::Iterator i = l3.begin(); i != l3.end(); i++)
      cout << i->data;
  return 0;
}