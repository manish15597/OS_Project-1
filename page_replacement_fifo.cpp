#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,f;
	cout<<"Enter the nmber of frames:\n";
	cin>>f;
	printf("Enter the number of processes:\n");
	cin>>n;
	int a[n];
	cout<<"Enter the number of page number of each request:\n";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		/* code */
	}
	ofstream myfile;
	myfile.open("example.txt");
	for (int i = 0; i < n; ++i)
	{
		myfile << a[i];
		/* code */
	}
	myfile.close();
	return 0;
}