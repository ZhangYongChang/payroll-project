#pragma once


// CChangAsHourlyEmployeeDlg �Ի���

class CChangAsHourlyEmployeeDlg : public CDialog
{
	DECLARE_DYNAMIC(CChangAsHourlyEmployeeDlg)

public:
	CChangAsHourlyEmployeeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangAsHourlyEmployeeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHANGEASHOURLY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
private:
	double m_Salaried;

public:
	int GetID() const { return m_ID; }
	double GetSalaried() const { return m_Salaried; }
};
