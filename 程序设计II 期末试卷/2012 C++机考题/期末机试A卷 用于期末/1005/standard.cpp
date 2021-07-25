
class Exception
{
public:
    Exception(){}
    virtual ~Exception(){}
    virtual void PrintError() = 0;
};

class OutOfMemory : public Exception
{
public:
    OutOfMemory(){}
    ~OutOfMemory(){}
    virtual void PrintError();
};

void OutOfMemory::PrintError()
{
cout << "Out of Memory!!\n";
}

class RangeError : public Exception
{
public:
    RangeError(unsigned long number){BadNum = number;}
    ~RangeError(){}
    virtual void PrintError();
    virtual unsigned long GetNumber() { return BadNum; }
    virtual void SetNumber(unsigned long number) {BadNum = number;}
private:
    unsigned long BadNum;
};

void RangeError::PrintError()
{
   cout << "Number out of range. You used " << GetNumber() << " !\n";
}
