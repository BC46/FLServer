// FLServerDoc.h : interface of the CFLServerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLSERVERDOC_H__4AB6418A_9089_42F4_BFC7_57377C2BB9F1__INCLUDED_)
#define AFX_FLSERVERDOC_H__4AB6418A_9089_42F4_BFC7_57377C2BB9F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFLServerDoc : public CDocument
{
protected: // create from serialization only
	CFLServerDoc();
	DECLARE_DYNCREATE(CFLServerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFLServerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFLServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFLServerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLSERVERDOC_H__4AB6418A_9089_42F4_BFC7_57377C2BB9F1__INCLUDED_)
