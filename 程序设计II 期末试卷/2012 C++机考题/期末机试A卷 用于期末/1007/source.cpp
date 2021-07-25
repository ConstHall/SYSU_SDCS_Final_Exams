#include <iostream>
#include <string>
using namespace std;

//�����࣬�ļ�ϵͳ����
class FileSymItem{
protected:
    //�ļ�ϵͳ�������
    string name;
public:
    FileSymItem(const string& name){
        this->name = name;
    }

    //������
    void rename(const string& name){
        this->name = name;
    }

    /**
     * ������ռ�õĴ��̿ռ�
     */
    virtual int getSize() = 0;
};

/**
 * �ļ� ��һ���ļ�ϵͳ��ߵ��� �̳�FileSymItem
 */
class File: public FileSymItem{
public:
    File(const string& name, const int& s = 0):FileSymItem(name),size(s){}

    virtual int getSize(){
        return size;
    }

    //�޸����ļ���Ĵ�С
    void setSize(const int& size){
        this->size = size;
    }

    ~File(){
        cout << "Del File : " << name << endl;
    };
private:
    
    //�ļ�ռ�õĴ��̿ռ�
    int size;
};

/**
 * �ļ��� ��һ���ļ�ϵͳ��ߵ��� �̳�FileSymItem
 */
class Dir: public FileSymItem{
private:
    //�����ļ���������ֻ����20����
    static const int MAX_ITEM_COUNT = 20;

    FileSymItem* children[MAX_ITEM_COUNT];
    int count;
public:
    Dir(const string& name):FileSymItem(name){
        count = 0;
    }

    /**
     * ���ļ������FileSymItem ������˵ ������� �ļ���/�ļ���
     * @param newItem ������
     * @return ��
     */
    void addFileSymItem(FileSymItem* newItem){
        children[count++] = newItem;
    }

    /**
     * ���ļ���ɾ��FileSymItem ������˵ ����ɾ�� �ļ���/�ļ���
     * @param delItem ɾ����
     * @return ��
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