#pragma once


// CAddSalesReceiptsDlg �Ի���

class CAddSalesReceiptsDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddSalesReceiptsDlg)

public:
	CAddSalesReceiptsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddSalesReceiptsDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADDSALESRECEIPTS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int m_ID;
private:
	COleDateTime m_Date;
private:
	double m_Sales;

public:
	int GetID() const { return m_ID; }
	COleDateTime GetTime() const { return m_Date; }
	double GetSales() const { return m_Sales; }
};
