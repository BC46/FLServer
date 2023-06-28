// FLServerView.h : interface of the CFLServerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLSERVERVIEW_H__023FFB7A_F6BE_4E06_B6D0_147F3BA7D724__INCLUDED_)
#define AFX_FLSERVERVIEW_H__023FFB7A_F6BE_4E06_B6D0_147F3BA7D724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFLServerView : public CView
{
protected: // create from serialization only
	CFLServerView();
	DECLARE_DYNCREATE(CFLServerView)

// Attributes
public:
	CFLServerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFLServerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFLServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFLServerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FLServerView.cpp
inline CFLServerDoc* CFLServerView::GetDocument()
   { return (CFLServerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLSERVERVIEW_H__023FFB7A_F6BE_4E06_B6D0_147F3BA7D724__INCLUDED_)
