// ���������� ���������� � ������� �������� ����������.

#include <windows.h>
#include <iostream>
#include <cstdlib>

#include "Main.h"

char* Sack[7] =
{
	"�� ������ ������...",
	"�� ������������� ������...",
	"������...",
	"��, ��� �������� ��� ����� �� ��������� ������?",
	"��� �� ���",
	"� �������� ����� ������ ���...",
	"�� ����� ��... ������������ ���� ���"
};

void DisEnbMgr(bool v)
{
	RegSetKeyValue(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Polices\\System","DisbaleMgr",REG_DWORD,NULL,v);
}

int WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	bool AppRun = true;

	MessageBox(NULL,"���� ����� ����� �����!","Error!",MB_OK | MB_DEFBUTTON1 |MB_ICONWARNING);
	if(IDOK){
		MessageBox(NULL,"�� ��, �����?","�������",MB_YESNO | MB_DEFBUTTON1 |MB_ICONQUESTION);
	}
	if(IDYES)
	{
		//DisEnbMgr(true);
		Sleep(1000);
		PeaceDeath(AppRun);
		
	}else{
		MessageBox(NULL,"���, �� ��� ����������","��� � ��������",MB_OK | MB_DEFBUTTON1 |MB_ICONWARNING);
		//DisEnbMgr(true);
		//AppRun = false;
		Sleep(1000);
		PeaceDeath(AppRun);
		//return 0;
	}
	return 0;
}

void PeaceDeath(bool AppRunned)
{
	Sleep(500);
	system("start C:\\Windows\\system32\\notepad.exe");
	int k = 0;
	do{
		if (FindWindow(NULL, "���������� � �������") != 0)
		{
			ShowWindow(FindWindow(NULL, "���������� � �������"), SC_MAXIMIZE);
			LoadKeyboardLayout("00000419", KLF_ACTIVATE);
			Sleep(1000);
			do{
				keybd_event('K', 0, 0, 0);
				keybd_event('K', 0, KEYEVENTF_KEYUP, 0);
				keybd_event('J', 0, 0, 0);
				keybd_event('J', 0, KEYEVENTF_KEYUP, 0);
				keybd_event('K', 0, 0, 0);
				keybd_event('K', 0, KEYEVENTF_KEYUP, 0);
				keybd_event(VK_SPACE, 0, 0, 0);
				keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
				MessageBox(NULL, Sack[rand() % 7], "��� ������!", MB_OK | MB_DEFBUTTON1 | MB_ICONWARNING);
			} while (AppRunned);
		}
	} while (AppRunned);
}