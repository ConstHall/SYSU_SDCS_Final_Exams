class Account
{
public:
    Account();
    Account(string,double); //set name and balance
    static int getCount( ); //get count of accounts
    void setName(string); //set account name
    void setBalance(double); //set balance
    string getName() const; //const function, get account name 
    double getBalance() const; // const function, get account balance 
    ~Account();
private:
    string name;
    double balance;
    static int count;
};
int Account::count=0;

Account::Account(string name,double balance)
{
    this->name=name;
    this->balance=balance;
    count++;
}
int Account::getCount()
{
    return count;
}
void Account::setName(string name)
{
    this->name=name;
}
void Account::setBalance(double balance)
{
    this->balance=balance;
}
string Account::getName() const
{
    return name;
}
double Account::getBalance() const
{
    return balance;
}
Account::~Account()
{
    count--;
}
