#pragma once


// CChangeEmployeeAddressDlg �Ի���

class CChangeEmployeeAddressDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeEmployeeAddressDlg)

public:
	CChangeEmployeeAddressDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeEmployeeAddressDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGEADDRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	CString m_Address;

public:
	int GetID() const { return m_ID; }
	CString GetAddress() const { return m_Address; }
};
