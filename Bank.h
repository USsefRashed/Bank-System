#include<iostream>
#include<array>
#include<string>
#include<ctime>
using namespace std;
class Bank
{
protected:
int Id,*Ids;
    string *Names;
    double *Balance;
    int Size;
    string *Date;
public:
    //Implemntation
Bank(int size)
{
    try
    {
        if(size<=0)
        {
            throw"Sorry the Accounts number should be larger than 0";
        }
    }
    catch(const char* msg)
    {
        while (true)
        {
        cerr << msg <<endl;
        cout<<"Renter the number of accounts : "<<endl;
        cin>>size;
        if(!(size<=0)){break;}       
        }
    }
    Size=size;
        Names=new string[Size];
        Balance=new double[Size];
        Date=new string[Size];
        Id=-1;
        Ids=new int[Size];
}
string getDateTime()
{
    time_t now = time(0);
    char* dt = ctime(&now);
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   return dt;
}
void setAccounts(){
    for (int i = 0; i < Size; i++)
    {
        Ids[i]=++Id;
        Date[i]=getDateTime();
        cout<<"Date of process : "<<getDateTime();
        cout<<"Enter the Client name : ";cin>>Names[i];
        cout<<"Enter the Client Balance : ";cin>>Balance[i];
    }
    
}
void getAccounts(){
    cout<<"\n*--------------------ACCOUNTS--------------------*\n";
    for (int i = 0; i < Size; i++)
    {
        cout<<"\n==============================\n\n";
        cout<<"Client Id : "<<Ids[i];
        cout<<"Client : "<<Names[i]<<endl;
        cout<<"Balance : "<<Balance[i]<<endl;
        cout<<"Process Date"<<Date[i];
        cout<<"\n==============================\n\n";
    }
}
void getById(int id)
{
if(id<=0 || id<Size)
{
    cout<<"out of range !\n\n";
    while (true)
    {
        cout<<"Renter the client id : ";cin>>id;
        if(!(id<=0 || id<Size))
        break;
    }
    
}
cout<<"ID : "<<Ids[id];
    cout<<"Client : "<<Names[id];
    cout<<"Balance :"<<Names[id];
    cout<<"Date of process"<<Date[id];
}
~Bank(){
    delete[]Names;
    delete[]Date;
    delete[]Balance;
    delete[]Ids;
    cout<<"The program is ended successfully !"<<endl;
}
};


