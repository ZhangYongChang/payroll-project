#pragma once


// CDeleteEmployeeById �Ի���

class CDeleteEmployeeByIdDlg : public CDialog
{
	DECLARE_DYNAMIC(CDeleteEmployeeByIdDlg)

public:
	CDeleteEmployeeByIdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteEmployeeByIdDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_DELETEEMPLOYEEBYID };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	int GetID() const { return m_ID; }
private:
	int m_ID;
};
