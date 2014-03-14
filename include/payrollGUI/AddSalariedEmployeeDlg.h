#pragma once


// CAddSalariedEmployeeDlg 对话框

class CAddSalariedEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddSalariedEmployeeDlg)

public:
	CAddSalariedEmployeeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddSalariedEmployeeDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDSALARIEDEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_ID;
public:
	CString m_Name;
public:
	CString m_Address;
public:
	double m_Salaried;
};
