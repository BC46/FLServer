// FLServer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FLServer.h"

#include "MainFrm.h"
#include "FLServerDoc.h"
#include "FLServerView.h"

#include "Dacom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFLServerApp

BEGIN_MESSAGE_MAP(CFLServerApp, CWinApp)
	//{{AFX_MSG_MAP(CFLServerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFLServerApp construction

CFLServerApp::CFLServerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFLServerApp object

CFLServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFLServerApp initialization

// EBUeula function definition
typedef bool (EBUEula)(LPCSTR flRegKeyName, LPCSTR eulaPath, DWORD hasWarrantyFile, bool assumeNotAlreadyAccepted);

DWORD g_VersionNumber;

BOOL CFLServerApp::InitInstance()
{
	// Try to load EBUEula.dll in the root Freelancer folder
	HMODULE ebueulaModule = LoadLibraryA("..\\EBUEula.dll");

	if (ebueulaModule == NULL)
	{
		// Try to load EBUEula.dll in the EXE folder if the root EBUEula.dll file cannot be loaded
		ebueulaModule = LoadLibraryA("EBUEula.dll");

		if (ebueulaModule == NULL)
		{
			// Show error and exit if the EXE EBUEula.dll file cannot be loaded either
			MessageBoxA(NULL, "FreeLancer failed to attach to EBUEula.dll.", "Notice", MB_ICONERROR);
			return FALSE;
		}
	}

	// Try to locate the EBUEula function from the EBUEula dll
	FARPROC ebueulaProc = GetProcAddress(ebueulaModule, "EBUEula");

	if (ebueulaProc == NULL)
	{
		// If the EBUEula function cannot be loaded, show error and exit
		MessageBoxA(NULL, "FreeLancer failed to find EBUEula entry point.", "Notice", MB_ICONERROR);
		return FALSE;
	}

	// Define EULA-related paths
	LPCSTR flRegKeyPath = "Software\\Microsoft\\Microsoft Games\\Freelancer\\1.0";
	LPCSTR eulaFilePath = "..\\EULA.rtf";
	LPCSTR warrantyFilePath = "..\\Warranty.rtf";

	// Get the file attributes of Warranty.rtf, which doesn't even exist
	DWORD warrantyFileAttributes = GetFileAttributesA(warrantyFilePath);

	// Wtf?
	DWORD hasWarrantyFile = -(int)(warrantyFileAttributes != -1) & (DWORD) warrantyFilePath;

	// Call the EBUEUla function and see whether the user has accepted the EULA
	EBUEula* EBUEulaFunction = (EBUEula*) *(ebueulaProc);
	bool eulaAccepted = (EBUEulaFunction)(flRegKeyPath, eulaFilePath, hasWarrantyFile, true);

	// Unload the EBUEula module
	FreeLibrary(ebueulaModule);

	// Exit if the user hasn't accepted the EULA
	if (!eulaAccepted)
		return FALSE;

	// TODO: Overwrite bool (__cdecl *CriticalWarningFn)(unsigned int, char const *), see 0x0040B90E

	char moduleFileName[MAX_PATH];
	ZeroMemory(&moduleFileName, MAX_PATH);

	GetModuleFileNameA(GetModuleHandleA(NULL), moduleFileName, MAX_PATH);

	DWORD major, minor, build;

	// Try to get the version info
	if (DACOM_GetDllVersion(moduleFileName, &major, &minor, &build) != 0)
	{
		// Set the version info manually if the GetDllVersion function failed
		major = 1;
		minor = 0;
		build = 11;
	}

	// Merge the major, minor, and build into one DWORD
	g_VersionNumber = (((minor & 0xFF) | (major << 8)) << 16) | (build & 0xFFFF);

	HMODULE serverResModule = LoadLibraryA("ServerResources.dll");

	if (serverResModule)
	{
		AFX_MODULE_STATE* moduleState = AfxGetModuleState();
		moduleState->m_hCurrentResourceHandle = serverResModule;
	}


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CFLServerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CFLServerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CFLServerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CFLServerApp message handlers

