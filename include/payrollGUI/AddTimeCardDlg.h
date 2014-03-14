#pragma once


// CAddTimeCardDlg 对话框

class CAddTimeCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddTimeCardDlg)

public:
	CAddTimeCardDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddTimeCardDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADDTIMECARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	COleDateTime m_Date;
	int m_Hours;
public:
	int GetID() const { return m_ID; }
	COleDateTime GetTime() const { return m_Date; }
	int GetHour() const { return m_Hours; }
};
