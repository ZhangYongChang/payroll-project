#pragma once
#include "afxcmn.h"
#include "employee.h"
#include <map>

// CEmployeeListDlg 对话框

class CEmployeeListDlg : public CDialog
{
	DECLARE_DYNAMIC(CEmployeeListDlg)

public:
	CEmployeeListDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEmployeeListDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_EMPLOYEEINFORMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	void ChangeEmployeeSet( std::map<int, Employee*> employees );

private:
	CListCtrl m_InfoListCtrl;
	std::map<int, Employee*> itsEmployees;

	virtual BOOL OnInitDialog();
	
};
