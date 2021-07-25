void student::reg(int id,string s)
{
    stu[id]=s;
}
bool student::graduate(int id,string s)
{
    map<int,string>::iterator it;
    it=stu.find(id);
    if(it!=stu.end()&&stu[id]==s) {
        stu.erase(it);
        return true;
    }
    return false;
}

string student::findName(int id)
{
    if(stu.count(id)!=0) return stu[id];
    return "";
}
