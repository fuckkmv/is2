#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void encrypt(string s,int key)
{
	int tmp;
	for(int i=0;i<s.length();i++)
	{
		tmp=s[i];
		if(tmp>=65 && tmp<=90)
		{
			s[i]=(tmp+key-65)%26+65;
		}
		else if(tmp>=97 && tmp<=122)
		{
			s[i]=(tmp+key-97)%26+97;
		}
		else
		{
			s[i]=s[i];
		}
	}
	cout<<"\nCipher text is ";
	for(int i=0;i<s.length();i++)
	{
		cout<<s[i];
	}
}
void decrypt(string s,int key)
{
	int tmp;
	for(int i=0;i<s.length();i++)
	{
		tmp=s[i];
		if(tmp>=65 && tmp<=90)
		{
			s[i]=(tmp-key-65+26)%26+65;
		}
		else if(tmp>=97 &&tmp<=122)
		{
			s[i]=(tmp-key-97+26)%26+97;
		}
		else
		{
			s[i]=s[i];
		}
	}
	cout<<"\nPlain text is ";
	for(int i=0;i<s.length();i++)
	{
		cout<<s[i];
	}
}
int main(){
	int n,key;
	cout<<"1.) Get cipher text for plane text.\n\n";
	cout<<"2.) Get Plain text for cipher text.\n\n";
	cout<<"Enter your choice -> ";
	cin>>n;
	cout<<"\nEnter key value ";
	cin>>key;
	fflush(stdin);
	string s;
	if(n==1){
		cout<<"\nEnter plain text. ";
	    getline(cin,s);
		encrypt(s,key);
	}
	else if(n==2)
	{
		cout<<"\nEnter cipher text. ";
        getline(cin,s);
    	decrypt(s,key);
	}
	return 0;
	
}
