// MainFrm.h : CMainFrame 类的接口
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
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


