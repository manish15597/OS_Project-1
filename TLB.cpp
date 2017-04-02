//Translation Look-Aside Buffer

#include <bits/stdc++.h>
using namespace std;

/*
TLB :-
	   Logical      Physical
ASID   PageNum      FrameNum      V/I     RWX
4bits   20bits       20bits       1 bit    3bits
ASID = 16     =>Max 16 processes
PageNum = 20  =>Max size of process is 4GB
FrameNum = 20 =>Max size of Main Memory is 4GB
V/I = 1       =>Valid Page 
Assumption - Only one user and he is the owner 
Page Size = 4KB
Total process size should not exceed 4GB
Frames are allocated continously
*/

struct entry
{
	int asid,pageNum,frameNum,VorI,RWX;
};

vector <pair<int, pair<int, int> > >process;

struct entry TLB[128],pageTable[1000000];
//Page Table Size = 4GB/4KB = 1000000

void createPageTable(int noOfProcesses)
{
	int i,j,temp,pageSize = 4,currPageNum=0,overallPageNum=0;

	for(i=1;i<=noOfProcesses;i++)
	{
		currPageNum = 0;
		temp = process[i-1].second.first;
		while(temp>0)
		{
			pageTable[overallPageNum].asid = process[i-1].first;
			pageTable[overallPageNum].pageNum = currPageNum;
			pageTable[overallPageNum].frameNum = overallPageNum;
			pageTable[overallPageNum].VorI = 1;
			pageTable[overallPageNum].RWX = process[i-1].second.second;
			temp/=pageSize;
			currPageNum++;
			overallPageNum++;
		}
	}
}

int getRequest(int processNum,int reqMemory,int noOfProcesses)
{
	//Process number checking
	if ( !(processNum>=0 && processNum<=noOfProcesses) )
		return -1;
	//Logical address checking
}

int main()
{
	int totalTLBSize,totalTLBEntries,oneTLBEntrySize,mainMemAccessTime,TLBAccessTime,noOfHits=0,noOfMiss=0,noOfProcesses,type,sizeOfProcess;

	oneTLBEntrySize = (4+20+20+1+3);
	totalTLBEntries = 128;
	totalTLBSize = (oneTLBEntrySize)*(totalTLBEntries);


	printf("Enter the amount of time it takes to access main memory and TLB\n");
	scanf("%d%d",&mainMemAccessTime,&TLBAccessTime);

	printf("Enter no of processes\n");
	scanf("%d",&noOfProcesses);

	printf("Enter Process Size (in KB) and Type(RWX)\n");
	for(i=0;i<noOfProcesses;i++)
	{
		scanf("%d%d",sizeOfProcess,type);
		process.push_back(make_pair(i+1,make_pair(sizeOfProcess,type)));
	}

	//Create Page Table
	createPageTable(noOfProcesses);

	int noOfRequests,processNum,reqMemory,result;
	printf("Enter no of requests\n");
	scanf("%d",&noOfRequests);

	printf("enter process number and required memory\n");
	for(i=0;i<noOfRequests;i++)
	{
		scanf("%d%d",&processNum,&reqMemory);
		result = getRequest(processNum,reqMemory,noOfProcesses);
		if(result==1){
			noOfHits++;
		}
		else if(result==0){
			noOfMiss++;
		}
		else if(result==-1){
			printf("TRAP\n");
		}
	
	}


	return 0;
}
