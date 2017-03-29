#include <bits/stdc++.h>
using namespace std;
int q[100], front=0, point=0,f;

void push(int value)
{
	q[front]=value;
	front++;
}

int check(int value)
{
	for (int i = 0; i < f; ++i)
	{
		if (q[i]==value)
			return 0;
		/* code */
	}
	return 1;
}

void replace(int value)
{
	q[point]=value;
	point=(point+1)%f;
}

int main()
{
	int n, p[100], h=0, m=0, flag=0;
	ofstream f1;
	f1.open("fifo.txt");
	printf("Enter the number of requests\n");
	scanf("%d", &n);
	printf("Enter the requests:\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &p[i]);
	}
	printf("Enter the number of frames:\n");
	scanf("%d", &f);
	for (int i = 0; i < f; ++i)
	{
		q[i]=-1;
	}

	for (int i = 0; i < f; ++i)
	{
		if (i<n)
		{
			if (check(p[i]))
			{
				push(p[i]);
				m++;
				flag=0;
			}
			else
			{
				h++;
				flag=1;
			}
		}
		for (int j = 0; j < f; ++j)
		{
			f1 << q[j];
			f1 << " ";
		}
		f1 << p[i] << " ";
		if (flag==0)
			f1<<"0";
		else
			f1<<"1";
		f1 << "\n";
	}

	for (int i = f; i < n; ++i)
	{
		if (check(p[i]))
		{
			replace(p[i]);
			m++;
			flag=0;
		}
		else
		{
			h++;
			flag=1;
		}
		for (int j = 0; j < f; ++j)
		{
			f1 << q[j];
			f1 << " ";
		}
		f1 << p[i] <<" ";
		if (flag==0)
			f1 << "0";
		else
			f1<<"1";
		f1 << "\n";
	}
	f1.close();
	printf("The number of hit=%d and miss=%d\n", h, m);
	return 0;
}