
// kursovayaA9.h : ������� ���� ��������� ��� ���������� kursovayaA9
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CkursovayaA9App:
// � ���������� ������� ������ ��. kursovayaA9.cpp
//

class CkursovayaA9App : public CWinApp
{
public:
	CkursovayaA9App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CkursovayaA9App theApp;
