#include <bits/stdc++.h>
using namespace std;
int q[1000000], front=0, point=0,f, vis[30]={0};

void push(int value)
{
	q[front]=value;
	front++;
	vis[value]=1;
}

int check(int value)
{
	return (vis[value]+1)%2;
}

void replace(int value)
{
	vis[q[point]]=0;
	q[point]=value;
	point=(point+1)%f;
	vis[value]=1;
}

int main()
{
	int n, p[1000000], h=0, m=0, flag=0;
	ofstream f1;
	f1.open("fifo1.txt");
	printf("Enter the number of requests\n");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		p[i] = rand()%30;
	}
	for (f = 1; f<=n;f++)
	{
		h=0;
		m=0;
	for (int i = 0; i < f; ++i)
	{
		q[i]=-1;
	}

	for (int i = 0; i < f; ++i)
	{
		for (int al=0;al<30;al++)
			vis[al]=0;
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
	}
	f1 << h << " " << m << "\n";
	}
	f1.close();
	return 0;
}