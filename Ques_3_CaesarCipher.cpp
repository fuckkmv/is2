#include <bits/stdc++.h>
using namespace std;

void encrypt(string s)
{
	int tmp;
	for(int i=0;i<s.length();i++)
	{
		tmp=s[i];
		if(tmp>=65 && tmp<=90)
		{
			s[i]+=3;
		}
		else if(tmp>=97 && tmp<=122)
		{
			s[i]+=3;
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
void decrypt(string s)
{
	int tmp;
	for(int i=0;i<s.length();i++)
	{
		tmp=s[i];
		if(tmp>=65 && tmp<=90)
		{
			s[i]-=3;
		}
		else if(tmp>=97 && tmp<=122)
		{
			s[i]-=3;
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
	int n;
	cout<<"1.) Get cipher text for plane text.\n\n";
	cout<<"2.) Get Plain text for cipher text.\n\n";
	cout<<"Enter your choice -> ";
	cin>>n;
	fflush(stdin);
	string s;
	if(n==1){
	
		cout<<"\nEnter plain text. ";
    	getline(cin,s);
    	encrypt(s);
	}
	else if(n==2)
	{
		cout<<"\nEnter cipher text. ";
		getline(cin,s);
    	decrypt(s);
	}
	
}

