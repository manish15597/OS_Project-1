#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
//template <class T>
class A
{
	string s;
public:
	void setVar(string i)
	{
		s = i;
	}
	void display()
	{
		cout<<s<<endl;
	}
};

istream& operator>> (istream &input, A &o)
{
	char *s1;
	s1 = new char[100];
	cin.getline(s1, 100);
	o.setVar(s1);
}

int main(int argc, char const *argv[])
{
	A a;
	cin>>a;
	a.display();
	/* code */
	return 0;
}