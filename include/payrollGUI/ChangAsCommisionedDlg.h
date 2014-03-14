#pragma once


// CChangAsCommisionedDlg 对话框

class CChangAsCommisionedDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsCommisionedDlg)

public:
	CChangAsCommisionedDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangAsCommisionedDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANGEASCOMMISIONEDEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	double m_Salaried;
private:
	double m_Rate;

public:
	int GetID() const { return m_ID; }
	double GetSalaried() const { return m_Salaried; }
	double GetRate() const { return m_Rate; }
};
