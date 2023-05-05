#include <bits/stdc++.h>
using namespace std;
void encryption()
{
	string pt;
	int n;
	fflush(stdin);
	cout<<"\n\nEnter plain text -> ";
	getline(cin,pt);
	cout<<"\nEnter size of key -> ";
	cin>>n;
	int key[n];
	string arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]="x";
		}
	}
	cout<<"\n\nEnter value of Key -> ";
	for(int i=0;i<n;i++)
	{
		cin>>key[i];
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=pt[k++];
			if(k==pt.length())
			break;
		}
		if(k==pt.length())
			break;
	}
	cout<<"\n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\n\n";
	string A[n],B[n][n];
	for(int i=0;i<n;i++)
	{
		int l=0;
		for(int j=0;j<n;j++)
		{
			A[l] = arr[j][key[i]];
			B[j][i]=A[l];
			l++;
	   }
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<B[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\nEncrypted text is given by -> ";
	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<B[i][j];
		}
	}
	cout<<"\n\n";
	//Decryption
	sort(key,key+n);
	for(int i=0;i<n;i++)
	{
		int l=0;
		for(int j=0;j<n;j++)
		{
			A[l] = arr[j][key[i]];
			B[j][i]=A[l];
			l++;
	   }
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<B[i][j]<<"\t";
		}
		cout<<"\n";
	}
    cout<<"\n\nDecrypted text is given by -> ";
	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<B[i][j];
		}
	}
	cout<<"\n\n";
}
int main()
{
	cout<<"\n\n\n\t\t\t<<<<<<<----------------------------ROW TRANSPOSITION CIPHER----------------------------->>>>>>>>>>";
	encryption();
	cout<<"\n\n\n";	
	return 0;
}
