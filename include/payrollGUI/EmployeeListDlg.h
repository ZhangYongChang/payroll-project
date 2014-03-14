#pragma once
#include "afxcmn.h"
#include "employee.h"
#include <map>

// CEmployeeListDlg �Ի���

class CEmployeeListDlg : public CDialog
{
	DECLARE_DYNAMIC(CEmployeeListDlg)

public:
	CEmployeeListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEmployeeListDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_EMPLOYEEINFORMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	void ChangeEmployeeSet( std::map<int, Employee*> employees );

private:
	CListCtrl m_InfoListCtrl;
	std::map<int, Employee*> itsEmployees;

	virtual BOOL OnInitDialog();
	
};
