// FLServer.h : main header file for the FLSERVER application
//

#if !defined(AFX_FLSERVER_H__F4D1C7DC_4B36_44D7_B087_C011C7E2DC7E__INCLUDED_)
#define AFX_FLSERVER_H__F4D1C7DC_4B36_44D7_B087_C011C7E2DC7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFLServerApp:
// See FLServer.cpp for the implementation of this class
//

class CFLServerApp : public CWinApp
{
public:
	CFLServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFLServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFLServerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLSERVER_H__F4D1C7DC_4B36_44D7_B087_C011C7E2DC7E__INCLUDED_)
