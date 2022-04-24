#include<iostream>
#include <bits\stdc++.h>
#include<array>
#include<conio.h>
#include<string.h>
#include"Bank.h"
using namespace std;

void operations(Bank &Client)
{
    //act as the interface of our system
    char ans;
    cout<<"@------Welcome to our Bank system ------@\n\n";
    cout<<"-----------\nEnter : (A)dd Account\n-----------\nEnter : (I)Display Client by Id\n-----------\nEnter : (D)isplay Accounts\n-----------\n(M)odify Account\n-----------\n"<<endl;
    cout<<"(R)emove Client\n-----------\n";
    ans = getche();
    if(ans=='d'||ans=='D')
    {
        Client.getAccounts();
    }
    else if(ans=='a'||ans=='A')
    {
        Client.setAccounts();
    }
    else if(ans=='I'||ans=='i')
    {
        int id;
        cout<<"Enter the Client Id : ";cin>>id;
        Client.getById(id);
    }
    else if(ans=='m'||ans=='M')
    {
        int id;
        cout<<"Enter Client ID : ";cin>>id;
        Client.ModifyById(id);
    }
    else if(ans=='r'||ans=='R')
    {
        int id;
        cout<<"Enter id to remove : ";cin>>id;
        Client.DeleteById(id);
    }
    else
    {
        cout<<"Invalid value ! ";
    }
}
int main()
{
    char cont;int size;
    cout<<"How Many Account You want to add : ";cin>>size;
    Bank Client(size);
    while (true)
    {
        operations(Client);

        cout<<"Press any key to continue or (E/e) to exit : ";

        
        cont = getche();
        system("cls");
        if(cont=='e'||cont=='E'){
            
            cout << "you  want write accounts information in .txt file (y/n) ? ";
            cont = tolower(getche());
            if (cont == 'y' ){
                Client.Writetxtfile();
            }
            
            break;
        }
        
    }
    
return 0;
}