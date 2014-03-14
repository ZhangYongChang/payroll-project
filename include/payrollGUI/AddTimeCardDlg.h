#pragma once


// CAddTimeCardDlg �Ի���

class CAddTimeCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddTimeCardDlg)

public:
	CAddTimeCardDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddTimeCardDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDTIMECARD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
	COleDateTime m_Date;
	int m_Hours;
public:
	int GetID() const { return m_ID; }
	COleDateTime GetTime() const { return m_Date; }
	int GetHour() const { return m_Hours; }
};
