#pragma once


// CChangeNameDlg �Ի���

class CChangeNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangeNameDlg)

public:
	CChangeNameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeNameDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGENAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CString GetName() const { return m_Name; }
	int GetID() const { return m_ID; }
private:
	int m_ID;
private:
	CString m_Name;
};
