#pragma once


// CChangeNameDlg 对话框

class CChangeNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeNameDlg)

public:
	CChangeNameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeNameDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANGENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString GetName() const { return m_Name; }
	int GetID() const { return m_ID; }
private:
	int m_ID;
private:
	CString m_Name;
};
