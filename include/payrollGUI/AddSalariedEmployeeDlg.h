#pragma once


// CAddSalariedEmployeeDlg �Ի���

class CAddSalariedEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddSalariedEmployeeDlg)

public:
	CAddSalariedEmployeeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddSalariedEmployeeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDSALARIEDEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
