#include <iostream>
#include <string>
using namespace std;

//抽象类，文件系统的项
class FileSymItem{
protected:
    //文件系统项的名字
    string name;
public:
    FileSymItem(const string& name){
        this->name = name;
    }

    //重命名
    void rename(const string& name){
        this->name = name;
    }

    /**
     * 返回项占用的磁盘空间
     */
    virtual int getSize() = 0;
};

/**
 * 文件 是一个文件系统里边的项 继承FileSymItem
 */
class File: public FileSymItem{
public:
    File(const string& name, const int& s = 0):FileSymItem(name),size(s){}

    virtual int getSize(){
        return size;
    }

    //修改了文件项的大小
    void setSize(const int& size){
        this->size = size;
    }

    ~File(){
        cout << "Del File : " << name << endl;
    };
private:
    
    //文件占用的磁盘空间
    int size;
};

/**
 * 文件夹 是一个文件系统里边的项 继承FileSymItem
 */
class Dir: public FileSymItem{
private:
    //假设文件夹里边最多只会有20个项
    static const int MAX_ITEM_COUNT = 20;

    FileSymItem* children[MAX_ITEM_COUNT];
    int count;
public:
    Dir(const string& name):FileSymItem(name){
        count = 0;
    }

    /**
     * 往文件夹添加FileSymItem （即是说 可以添加 文件夹/文件）
     * @param newItem 新增项
     * @return 无
     */
    void addFileSymItem(FileSymItem* newItem){
        children[count++] = newItem;
    }

    /**
     * 往文件夹删除FileSymItem （即是说 可以删除 文件夹/文件）
     * @param delItem 删除项
     * @return 无
     */
    void delFileSymItem(FileSymItem* delItem){
        int i;
        for (i = 0; i < count; ++i){
            if (children[i] == delItem){
                break;
            }
        }
        if (i != count){
            for (;i < count-1; ++i){
                children[i] = children[i+1];
            }
            count--;
        }
    }

    virtual int getSize(){
        int size = 0;
        for (int i = 0; i < count; ++i){
            size += (children[i])->getSize();
        }
        return size;
    }

    ~Dir(){
        cout << "Del Dir : " << name << endl;
    };
};                                 