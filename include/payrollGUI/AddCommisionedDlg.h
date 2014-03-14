#pragma once


// CAddCommisionedDlg �Ի���

class CAddCommisionedEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddCommisionedEmployeeDlg)

public:
	CAddCommisionedEmployeeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddCommisionedEmployeeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDCOMMISIONEDEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	int GetId() const { return m_ID; }
	CString GetName() const { return m_Name; }
	CString GetAddress() const { return m_Address; }
	double GetSalaried() const { return m_Salaried; }
	double GetRate() const { return m_Rate; }

private:
	int m_ID;
	CString m_Name;
	CString m_Address;
	double m_Salaried;
	double m_Rate;
};
