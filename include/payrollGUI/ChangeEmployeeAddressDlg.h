#pragma once


// CChangeEmployeeAddressDlg 对话框

class CChangeEmployeeAddressDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeEmployeeAddressDlg)

public:
	CChangeEmployeeAddressDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeEmployeeAddressDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANGEADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	CString m_Address;

public:
	int GetID() const { return m_ID; }
	CString GetAddress() const { return m_Address; }
};
