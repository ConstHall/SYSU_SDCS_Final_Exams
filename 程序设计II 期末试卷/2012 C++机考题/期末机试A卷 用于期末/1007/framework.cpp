#include <iostream>
#include "source.cpp"
using namespace std;

int main(){
	//freopen("a.out", "w", stdout);
	Dir DASDir("Documents and Settings"), allUsersDir("All Users"), administratorDir("Administrator");

	//Documents and Settings�ļ��е����� All Users �Լ� Administrator�ļ���
	DASDir.addFileSymItem(&allUsersDir);
	DASDir.addFileSymItem(&administratorDir);
	
	cout << DASDir.getSize() << endl;//�ļ��д�С��0
	
	//��All Users���һ��20���ֽڵ��ļ�"MS.exe"
	File msExeFile("MS.exe", 20);
	allUsersDir.addFileSymItem(&msExeFile);
	cout << msExeFile.getSize() << endl;//msExeFile�ļ���С��20
	cout << allUsersDir.getSize() << endl;//allUsersDir�ļ��д�С��20
	cout << DASDir.getSize() << endl;//DASDir�ļ��д�С��20
	

	//��Administrator���һ��110���ֽڵ��ļ�"QQ.exe"
	File qqExeFile("MS.exe", 110);
	administratorDir.addFileSymItem(&qqExeFile);
	cout << qqExeFile.getSize() << endl;//msExeFile�ļ���С��110
	cout << administratorDir.getSize() << endl;//allUsersDir�ļ��д�С��110
	cout << DASDir.getSize() << endl;//DASDir�ļ��д�С��130

	qqExeFile.setSize(130);
	cout << allUsersDir.getSize() << endl;
	cout << administratorDir.getSize() << endl;
	cout << DASDir.getSize() << endl;

	DASDir.delFileSymItem(&administratorDir);
	cout << allUsersDir.getSize() << endl;
	cout << administratorDir.getSize() << endl;
	cout << DASDir.getSize() << endl;
	
	File xxxExeFile("xxx.exe", 210);
	allUsersDir.delFileSymItem(&xxxExeFile);
	administratorDir.addFileSymItem(&xxxExeFile);
	DASDir.addFileSymItem(&administratorDir);
	cout << allUsersDir.getSize() << endl;
	cout << administratorDir.getSize() << endl;
	cout << DASDir.getSize() << endl;

	Dir *testDir = new Dir("TEST");
	testDir->rename("RENAME_TEST");
	delete testDir;
	File *testFile = new File("testFile");
	testFile->rename("RENAME_testFile");
	delete testFile;
	//system("pause");
	return 0;
}