#pragma once


// CChangAsHourlyEmployeeDlg 对话框

class CChangAsHourlyEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsHourlyEmployeeDlg)

public:
	CChangAsHourlyEmployeeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangAsHourlyEmployeeDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHANGEASHOURLY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
private:
	double m_Salaried;

public:
	int GetID() const { return m_ID; }
	double GetSalaried() const { return m_Salaried; }
};
