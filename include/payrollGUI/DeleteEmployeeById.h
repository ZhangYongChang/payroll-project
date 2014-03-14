#pragma once


// CDeleteEmployeeById 对话框

class CDeleteEmployeeByIdDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeleteEmployeeByIdDlg)

public:
	CDeleteEmployeeByIdDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeleteEmployeeByIdDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_DELETEEMPLOYEEBYID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int GetID() const { return m_ID; }
private:
	int m_ID;
};
