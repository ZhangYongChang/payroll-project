#pragma once


// CChangAsCommisionedDlg �Ի���

class CChangAsCommisionedDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsCommisionedDlg)

public:
	CChangAsCommisionedDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangAsCommisionedDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGEASCOMMISIONEDEMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
