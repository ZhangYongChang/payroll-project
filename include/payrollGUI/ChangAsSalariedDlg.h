#pragma once


// CChangAsSalariedDlg 对话框

class CChangAsSalariedDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsSalariedDlg)

public:
	CChangAsSalariedDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangAsSalariedDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANGEASSALARIED };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	double m_Salaried;
public:
	int GetID() const { return m_ID; }
	double GetSalaried() const { return m_Salaried; }
};
