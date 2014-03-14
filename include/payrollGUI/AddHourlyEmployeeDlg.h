#pragma once


// CAddHourlyEmployeeDlg 对话框

class CAddHourlyEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddHourlyEmployeeDlg)

public:
	CAddHourlyEmployeeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddHourlyEmployeeDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDHOURLYEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int GetId() const { return m_ID; }
	CString GetName() const { return m_Name; }
	CString GetAddress() const { return m_Address; }
	double GetSalaried() const { return m_Salaried; }
private:
	int m_ID;
	CString m_Name;
	CString m_Address;
	double m_Salaried;
};
