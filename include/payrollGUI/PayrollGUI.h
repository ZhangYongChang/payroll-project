// PayrollGUI.h : PayrollGUI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CPayrollGUIApp:
// �йش����ʵ�֣������ PayrollGUI.cpp
//

class CPayrollGUIApp : public CWinApp
{
public:
	CPayrollGUIApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPayrollGUIApp theApp;