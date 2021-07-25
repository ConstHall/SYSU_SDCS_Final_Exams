#include <iostream>
#include "source.cpp"
using namespace std;

int main(){
	//freopen("a.out", "w", stdout);
	Dir DASDir("Documents and Settings"), allUsersDir("All Users"), administratorDir("Administrator");

	//Documents and Settings文件夹底下有 All Users 以及 Administrator文件夹
	DASDir.addFileSymItem(&allUsersDir);
	DASDir.addFileSymItem(&administratorDir);
	
	cout << DASDir.getSize() << endl;//文件夹大小是0
	
	//往All Users添加一个20个字节的文件"MS.exe"
	File msExeFile("MS.exe", 20);
	allUsersDir.addFileSymItem(&msExeFile);
	cout << msExeFile.getSize() << endl;//msExeFile文件大小是20
	cout << allUsersDir.getSize() << endl;//allUsersDir文件夹大小是20
	cout << DASDir.getSize() << endl;//DASDir文件夹大小是20
	

	//往Administrator添加一个110个字节的文件"QQ.exe"
	File qqExeFile("MS.exe", 110);
	administratorDir.addFileSymItem(&qqExeFile);
	cout << qqExeFile.getSize() << endl;//msExeFile文件大小是110
	cout << administratorDir.getSize() << endl;//allUsersDir文件夹大小是110
	cout << DASDir.getSize() << endl;//DASDir文件夹大小是130

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