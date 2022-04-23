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
void ModifyById(int id);
void DeleteById(int id);
void ModifyFName(int id);
void ModifyLName(int id);
void ModifBalance(int id);

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
        if(Ids[i]==id &&Ids[id]!=-1 && FirstName[id].empty()==false)
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
    for (int i = 0; i < Size; i++)
    {
        Ids[i]=++Id;
        Date[i]=getDateTime();
        cout<<"Date of process : "<<Date[i];
        cout<<"Enter the Client First name : ";cin>>FirstName[i];
        cout<<"Enter the Client Last name : ";cin>>LastName[i];
        cout<<"Enter the Client Balance : ";cin>>Balance[i];
    }
    Id++;
    
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
            if(!(id<0 || id<Size))
            break;
        }
    
    }
    if (FirstName[id].empty()==true)
    {
        cout<<"There is no data for this id !"<<endl;
    }
    else
    {
        cout<<"ID : "<<Ids[id]<<endl;
        cout<<"Client : "<<FirstName[id]<<endl;
        cout<<"Balance :"<<Balance[id]<<endl;
        cout<<"Date of process"<<Date[id]<<endl;
    }
    
}
void Bank::ModifyById(int id)
{
    char cho;
    cout<<"\n============================================"<<endl;
    cout<<"Which U want to modify ? \n (F)irstName\n(L)astName\n(B)alance\n";
    cout<<"============================================"<<endl;
    cin>>cho;
    if (cho=='B'||cho=='b')
    {
        ModifBalance(id);
        cout<<"Client is modified sucessfully !"<<endl;

    }
    else if(cho=='F'||cho=='f')
    {
        ModifyFName(id);
        cout<<"Client is modified sucessfully !"<<endl;
    }
    else if(cho=='L'||cho=='l')
    {
        ModifyLName(id);
        cout<<"Client is modified sucessfully !"<<endl;
    
    }
    else{
        cout<<"Invalid choice !"<<endl;
    }
    
}
void Bank::DeleteById(int id)
{
    if (isExist(id)==false)
    {
        cout<<"the client is not exist !"<<endl;
    }
    else
    {
        Ids[id]=-1;
        FirstName[id].clear();
        LastName[id].clear();
        Balance[id]=-1;
        cout<<"Client is deleted sucessfully !"<<endl;
    }
    
}

void Bank::ModifyFName(int id)
{
    try
    {
        if(isExist(id)==false)
        {
        throw "Sorry  this Client is not exist !";
        }
        else
        {
            string name;
            cout<<"Enter the new First name of user : ";cin>>name;
            FirstName[id]=name;
        }

    }
    catch(const char*msg)
    {
        std::cerr <<msg<< '\n';
    }
    

}
void Bank::ModifyLName(int id)
{
        try
    {
        if(isExist(id)==false)
        {
        throw "Sorry  this Client is not exist !";
        }
        else
        {
            string name;
            cout<<"Enter the new Last name of user : ";cin>>name;
            LastName[id]=name;
        }

    }
    catch(const char*msg)
    {
        std::cerr <<msg<< '\n';
    }
}
void Bank::ModifBalance(int id)
{
        try
    {
        if(isExist(id)==false)
        {
        throw "Sorry  this Client is not exist !";
        }
        else
        {
            int balance;
            cout<<"Enter the new balance of user : ";cin>>balance;
            Balance[id]=balance;
        }

    }
    catch(const char*msg)
    {
        std::cerr <<msg<< '\n';
    }
}