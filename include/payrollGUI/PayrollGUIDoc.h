// PayrollGUIDoc.h : CPayrollGUIDoc ��Ľӿ�
//


#pragma once


class CPayrollGUIDoc : public CDocument
{
protected: // �������л�����
	CPayrollGUIDoc();
	DECLARE_DYNCREATE(CPayrollGUIDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CPayrollGUIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

