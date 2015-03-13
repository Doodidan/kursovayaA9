
// kursovayaA9.h : главный файл заголовка для приложения kursovayaA9
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CkursovayaA9App:
// О реализации данного класса см. kursovayaA9.cpp
//

class CkursovayaA9App : public CWinApp
{
public:
	CkursovayaA9App();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CkursovayaA9App theApp;
