#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void encryption()
{
	int key1[50];
	int key,t,n=0,N=2;
	fflush(stdin);
	int ct[100];
	int A[100];
	string ch="yes";
	while(ch=="yes" || ch=="YES")
	{
		cout<<"\n\nEnter plain text in binary -> ";
		cin>>t;
		key = rand() % N;
		cout<<"\n\nRandomly generated key -> "<<key;
		key1[n]=key;
		ct[n];
		ct[n]=t^key;
		cout<<"\n\nCipher text at step - "<<n<<" -> "<<ct[n];
		cout<<"\n\nDO YOU WANT ENTER MORE TEXT ?\n\n\t\t\t\t YES or NO \n\n\t\t\t\t";
		cin>>ch;
		n++;
	}
	cout<<"\n\nFinal Cipher text is -> ";
	for(int i=0;i<n;i++)
		cout<<ct[i]<<" ";
	cout<<"\n\n\n";
	
	//Decryption
	cout<<"\n\nEnter encrypted text -> ";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	cout<<"\n\nDecrypted text is given by -> ";
	for(int j=0;j<n;j++)
	{
		if(key1[j]==0 && A[j]==0 || key1[j]==1 && A[j]==1)
		{
			cout<<"0"<<" ";
		}
		else
		{
			cout<<"1"<<" ";
		}
	}
	cout<<"\n\n\n";
}
int main(){
	encryption();
	return 0;	
}

