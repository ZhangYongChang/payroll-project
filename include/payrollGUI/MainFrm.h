// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnRead();
	afx_msg void OnSave();
	afx_msg void OnAddSalariedEmployee();
	afx_msg void OnAddcommisionedemployee();
	afx_msg void OnAddhourlyemployee();
	afx_msg void OnDeleteEmployeeById();
	afx_msg void OnBrowerInfomation();
	afx_msg void OnChangName();
	afx_msg void OnChangAddress();
	afx_msg void OnChangAsHourlyEmployee();
	afx_msg void OnChangassalariedemployee();
	afx_msg void OnChangasCommisionedEmployee();
	afx_msg void OnAddTimeCard();
	afx_msg void OnAddsalesreceipt();
};


