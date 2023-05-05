#include <bits/stdc++.h>

using namespace std;

map<int, int> keymap;

string getInput()
{
    string s, s1 = "";
    cout << "\nEnter the text -> ";
    getline(cin >> ws, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
            continue;
        else
            s1 += s.at(i);
    }
    return s1;
}

void displayMatrix(char **a, int r, int n)
{
    for (int i = 0; i < r; i++)
    {
        cout << "   " << i << " ";
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}

string encrypt(string msg, char **a, int r, string key, int n)
{

    string ct = "";

    int l = 0, temp = msg.length() % n;
    if (temp != 0)
        temp = n - temp;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < n; j++)
        {
            if (l < msg.length())
                a[i][j] = msg.at(l++);
            else
                a[i][j] = (char)(123 - temp--);
        }

    map<int, int>::iterator it = keymap.begin();
    while (it != keymap.end())
    {
        int j = it->second;
        for (int i = 0; i < r; i++)
        {
            ct += a[i][j];
        }
        ++it;
    }
    cout << endl
         << "Key = " << key<< endl;
    displayMatrix(a, r, n);
    return ct;
}

string decrypt(string ct, char **a, int r, string key, int n)
{
    int l = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            a[j][i] = ct.at(l++);

    int index = 0;
    map<int, int>::iterator it = keymap.begin();
    while (it != keymap.end())
    {
        it->second = index++;
        ++it;
    }

    char decCipher[r][n];
    for (int k = 0; k < n; k++)
    {
        int j = keymap[key[k]];
        for (int i = 0; i < r; i++)
        {
            decCipher[i][k] = a[i][j];
        }
    }

    string pt = "";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pt += decCipher[i][j];
        }
    }
    return pt;
}

int main()
{
	cout<<"\n\n\n\t\t\t<<<<<-------------------------PRODUCT CIPHER TRANSPOSITION----------------------------->>>>>>>>";
    string choice;
    do
    {
        string key, ct;
        int t, ch;
        cout<<"\n\n1.) Get encrypted text for plane text.\n\n";
	    cout<<"2.) Get Plain text for encrypted text.\n\n";
		cout<<"Enter your choice -> ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string msg = getInput();
            cout << "\nEnter the key -> ";
            getline(cin >> ws, key);
            cout << "\nEnter the number of transpositions -> ";
            cin >> t;
            int n = key.length();
            int row = ((msg.length() % n) == 0) ? msg.length() / n : (msg.length() / n) + 1;
            char **a = new char *[row];
            for (int i = 0; i < row; i++)
                a[i] = new char[n];
            for (int i = 0; i < key.length(); i++)
            {
                keymap[key.at(i)] = i;
            }
            ct = msg;
            for (int i = 0; i < t; i++)
            {
                ct = encrypt(ct, a, row, key, n);
                cout << "\nEncrypted Text is given by -> " << ct << endl;
            }
            
            break;
        }
        case 2:
        {
            string msg = getInput();
            cout << "\nEnter the key -> ";
            getline(cin >> ws, key);
            cout << "\nEnter the number of transpositions -> ";
            cin >> t;
            int n = key.length();
            int row = ((msg.length() % n) == 0) ? msg.length() / n : (msg.length() / n) + 1;
            char **a = new char *[row];
            for (int i = 0; i < row; i++)
                a[i] = new char[n];
            for (int i = 0; i < key.length(); i++)
            {
                keymap[key.at(i)] = i;
            }
            ct = msg;
            for (int i = 0; i < t; i++)
            {
                ct = decrypt(ct, a, row, key, n);
            }
            cout << "\nDecrypted Text is given by -> " << ct;
            break;
        }
        default:
            cout << "\nWrong Choice entered by User!....." << endl;
            break;
        }
        cout<<"\n\nDO YOU WANT TO PROCEED FURTHER ?\n\n\t\t\t\t YES or NO \n\n\t\t\t\t";
        cin >> choice;
    } while (choice == "yes" || choice == "YES");
    return 1;
}
