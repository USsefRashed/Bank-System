#include<iostream>
#include<array>
#include<string>
#include<ctime>
using namespace std;
class Bank
{
protected:

    int Id,*Ids,Size;
    double *Balance;
    string *FirstName;
    string *LastName;
    string *Date;

public:

Bank(int size);
bool isExist(int id);
string getDateTime();
void setAccounts();
void getAccounts();
void getById(int id);
};

Bank::Bank(int size)
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
        if(!(size<=0))
        {break;}       
        }
    }
    Size=size;
    Id=-1;
    Ids=new int[Size];
    FirstName=new string[Size];
    LastName=new string[Size];
    Balance=new double[Size];
    Date=new string[Size];
}

bool Bank::isExist(int id)
{
    for (int i = 0; i < Size; i++)
    {
        if(Ids[i]==id)
        return 1;
    }
    return 0;
}

string Bank::getDateTime()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    return dt;
}

void Bank::setAccounts(){
    string name;
    for (int i = 0; i < Size; i++)
    {
        Ids[i]=++Id;
        Date[i]=getDateTime();
        cout<<"Date of process : "<<Date[i];
        cout<<"Enter the Client First name : ";cin>>FirstName[i];
        cout<<"Enter the Client Last name : ";cin>>LastName[i];
        cout<<"Enter the Client Balance : ";cin>>Balance[i];
    }
    
}
void Bank::getAccounts(){
    if(Id==-1)
    {
        cout<<"There is not accounts added yet !"<<endl;
    }
    else
    {
    cout<<"\n*--------------------ACCOUNTS--------------------*\n";
        for (int i = 0; i < Size; i++)
        {
            if (FirstName[i].empty()==true)
            {
                continue;
            }
            else
            {
            cout<<"\n==============================\n\n";
            cout<<"Client Id : "<<Ids[i];
            cout<<"Client : "<<FirstName[i]<<" "<<LastName[i]<<endl;
            cout<<"Balance : "<<Balance[i]<<endl;
            cout<<"Process Date"<<Date[i];
            cout<<"\n==============================\n\n";
            }
            
        }
    }
    
}
void Bank::getById(int id)
{
    if(id<0 || id>Size)
    {
        cout<<"out of range !\n\n";
        while (true)
        {
            cout<<"Renter the client id : ";cin>>id;
            if(!(id<=0 || id<Size))
            break;
        }
    
    }
    cout<<"ID : "<<Ids[id]<<endl;
    cout<<"Client : "<<FirstName[id]<<endl;
    cout<<"Balance :"<<Balance[id]<<endl;
    cout<<"Date of process"<<Date[id]<<endl;
}


