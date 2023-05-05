#include <iostream>
using namespace std;
	
void encryption(){
	string pt;
	cout<<"\nEnter Plain Text -> ";
    getline(cin,pt);
	int key;
	cout<<"\n\nEnter a key -> ";
    cin>>key;
    int size = pt.length();
    string arr[key][size];
    for(int i=0;i<key;i++)
	{
		for(int j=0;j<size;j++)
		{
			arr[i][j]=" ";
		}
	}
	int k=0;
	int flag=0;     //down
	for(int i=0;i<size;)
	{
		if(flag==0)
		{
			arr[k][i]=pt[i];
			k++;
			i++;
			if(k==(key))
			{
				flag=1;
				k--;
			}
		}
		if(flag==1)
		{
			k--;
			arr[k][i]=pt[i];
			i++;
			k--;
			if(k==0) flag=0;
		}
	}
	string et[size];
	static int a=0;
	for(int i=0;i<key;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(arr[i][j]==" "){
				continue;
			}
			else
			{
				et[a]=arr[i][j];
				a++;
			}
		}
	}
	cout<<"\n\n";
	cout<<"-------------------------------------------------------\n\n";
	for(int i=0;i<key;i++)
	{
		for(int m=0;m<size;m++)
		{
			cout<<arr[i][m];
			cout<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n\nEncrypted text is given by -> ";
	for(int j=0;j<a;j++)
	{
		cout<<et[j];	
	}
	
}
void decryption(){
	string dt;
	cout<<"\nEnter decrypted Text -> ";
    getline(cin,dt);
	int key;
	cout<<"\n\nEnter a key -> ";
    cin>>key;
    int size = dt.length();
    string arr1[key][size];
	int k=0;
	int flag=0;     //down
	for(int i=0;i<size;)
	{
		if(flag==0)
		{
			arr1[k][i]="0";
			k++;
			i++;
			if(k==(key))
			{
				flag=1;
				k--;
			}
		}
		if(flag==1)
		{
			k--;
			arr1[k][i]="0";
			
			i++;
			k--;
			if(k==0) flag=0;
		}
	}
	int l=0;
	for(int i=0;i<key;i++)
		for(int j=0;j<size;j++)
			if(arr1[i][j]=="0")
				arr1[i][j]=dt[l++];
				
    for(int i=0;i<key;i++)
	{
		for(int m=0;m<size;m++)
		{
			cout<<arr1[i][m];
			cout<<"\t";
		}
		cout<<"\n";
	}
    int a=0;
    string Dt[size];
	for(int i=0;i<size;i++)
		for(int j=0;j<key;j++)
			if(arr1[j][i]!="")
				Dt[a++]=arr1[j][i];
				
	cout<<"\n\nDecrypted text is given by -> ";
	for(int j=0;j<a;j++)
	{
		cout<<Dt[j];	
	}	
}
int main()
{
	cout<<"\n\n\n\t\t\t<<<<<<<----------------------------RAIL FENCE CIPHER----------------------------->>>>>>>>>>";
	cout<<"\n\n\n-----------------> 1.) Get encrypted text for given Plain Text........"
	  	<<"\n\n-----------------> 2.) Get decrypted text for given Encrypted Text........";
	int n;
	cout<<"\n\nEnter your choice -> ";
	cin>>n;
	fflush(stdin);
	if(n==1)
	{
		encryption();
		cout<<"\n\n\n";
	}	
	else if(n==2)
	{
		decryption();
		cout<<"\n\n\n";	
	}
	return 0;
}

