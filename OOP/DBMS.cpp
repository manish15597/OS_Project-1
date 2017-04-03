#include <bits/stdc++.h>
using namespace std;

class Fields
{
	char *name;
	int type; //0 = int, 1 = float, 2 = string, 3 = char	
	int index;
};

template <class T>
class Cells
{
protected:	
	T data;
public:
	void storeData(int x)
	{
		data = x;
	}
	void storeData(float x)
	{
		data = x;
	}
	void storeData(string x)
	{
		data = x;
	}
};

class Records
{
protected:	
	class Cells<int> *cell1;
	class Cells<float> *cell2;
	class Cells<string> *cell3;
	static int no_int, no_float, no_string;
public:
	Records()
	{
		cell1 = new Cells <int> [10];
		cell2 = new Cells <float> [10];
		cell3 = new Cells <string> [10];

	}
	void getData(int type, int index)
	{
		switch (type)
		{
			case 0:
				int x;
				cin>>x;
				cell1[index].storeData(x);
				break;
			case 1:
				float y;
				cin>>y;
				cell2[index].storeData(y);
				break;
			case 2:
				char *s1;
				s1 = new char[50];
				cin.getline(s1, 50);
				cell3[index].storeData(s1);			
		}
	}

	void getallData(class Fields f, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			getData(f.type, f.index);
		}
	}

	static int increment(int type)
	{
		switch(type)
		{
			case 0:
				return ++no_int;
				break;
			case 1:
				return ++no_float;
				break;
			case 2:
				return ++no_string;
				break;		
		}
	}
};

int Records::no_int = 0;
int Records::no_float = 0;
int Records::no_string = 0;

class Table
{
	class Fields *field1;
	class Records *record1;
	int no_fields;
public:
	Table()
	{
		field1 = new class Fields[10];
		no_fields = 0;
	}
	void addColumn(int type)
	{
		cin>>field1.name;
		field1.type = type;
		Records::increment(type);
	}
};

class Database
{
	class Table *table1;
}; 

int main(int argc, char const *argv[])
{


	return 0;
}