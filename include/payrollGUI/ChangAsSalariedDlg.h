#pragma once


// CChangAsSalariedDlg �Ի���

class CChangAsSalariedDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsSalariedDlg)

public:
	CChangAsSalariedDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangAsSalariedDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGEASSALARIED };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	double m_Salaried;
public:
	int GetID() const { return m_ID; }
	double GetSalaried() const { return m_Salaried; }
};
