#include<iostream>
#include<array>
#include"Bank.h"
using namespace std;

void operations(Bank Client)
{
    char ans;
    cout<<"@------Welcome to our Bank system ------@\n\n";
    cout<<"-----------\nEnter : (A)dd Account\n-----------\nEnter : (I)Display Client by Id\n-----------\nEnter : (D)isplayAccounts\n-----------\n"<<endl;
    cin>>ans;
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
    else
    {
        cout<<"Invalid value ! ";
    }
}
int main()
{
    char cont;int size;
    cout<<"How Many Account You want to add : ";cin>>size;
    Bank Client=Bank(size);
    while (true)
    {
        operations(Client);

        cout<<"Press any key to continue or (E/e) to exit : ";cin>>cont;
        if(cont=='e'||cont=='E')
        break;
    }
    

}