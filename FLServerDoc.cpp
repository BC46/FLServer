// FLServerDoc.cpp : implementation of the CFLServerDoc class
//

#include "stdafx.h"
#include "FLServer.h"

#include "FLServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFLServerDoc

IMPLEMENT_DYNCREATE(CFLServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CFLServerDoc, CDocument)
	//{{AFX_MSG_MAP(CFLServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFLServerDoc construction/destruction

CFLServerDoc::CFLServerDoc()
{
	// TODO: add one-time construction code here

}

CFLServerDoc::~CFLServerDoc()
{
}

BOOL CFLServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFLServerDoc serialization

void CFLServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFLServerDoc diagnostics

#ifdef _DEBUG
void CFLServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFLServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFLServerDoc commands
