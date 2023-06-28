// FLServerView.cpp : implementation of the CFLServerView class
//

#include "stdafx.h"
#include "FLServer.h"

#include "FLServerDoc.h"
#include "FLServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFLServerView

IMPLEMENT_DYNCREATE(CFLServerView, CView)

BEGIN_MESSAGE_MAP(CFLServerView, CView)
	//{{AFX_MSG_MAP(CFLServerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFLServerView construction/destruction

CFLServerView::CFLServerView()
{
	// TODO: add construction code here

}

CFLServerView::~CFLServerView()
{
}

BOOL CFLServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFLServerView drawing

void CFLServerView::OnDraw(CDC* pDC)
{
	CFLServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFLServerView diagnostics

#ifdef _DEBUG
void CFLServerView::AssertValid() const
{
	CView::AssertValid();
}

void CFLServerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFLServerDoc* CFLServerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFLServerDoc)));
	return (CFLServerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFLServerView message handlers
