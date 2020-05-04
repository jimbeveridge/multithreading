/*
 * CancView.cpp
 *
 * Sample code for "Multithreading Applications in Win32"
 * This is from Chapter 11. This sample is discussed in
 * the text, but there is no associated listing.
 *
 * Launch a dialog in another thread using both
 * MFC and Win32. Demonstrate the related problems.
 */

#include "stdafx.h"
#include "Cancel.h"

#include "CancDoc.h"
#include "CancView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

DWORD WINAPI ThreadFunc(LPVOID);

/////////////////////////////////////////////////////////////////////////////
// CCancelView

IMPLEMENT_DYNCREATE(CCancelView, CView)

BEGIN_MESSAGE_MAP(CCancelView, CView)
	//{{AFX_MSG_MAP(CCancelView)
	ON_COMMAND(ID_LAUNCH, OnLaunch)
	ON_COMMAND(ID_BOOM, OnBoom)
	ON_COMMAND(ID_LAUNCH_WIN32, OnLaunchWin32)
	ON_COMMAND(ID_VIEW_TIGHT_LOOP, OnViewTightLoop)
	ON_COMMAND(ID_VIEW_NOPARENT, OnViewNoparent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCancelView construction/destruction

CCancelView::CCancelView()
{
	// TODO: add construction code here

}

CCancelView::~CCancelView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CCancelView drawing

void CCancelView::OnDraw(CDC* pDC)
{
	CCancelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCancelView diagnostics

#ifdef _DEBUG
void CCancelView::AssertValid() const
{
	CView::AssertValid();
}

void CCancelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCancelDoc* CCancelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCancelDoc)));
	return (CCancelDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCancelView message handlers

#include "OutpThrd.h"
#include "OutDlg.h"

CProgressDlg gCanDlg;

void CCancelView::OnViewTightLoop() 
{
	for (int i=0;i<200000000; i++);
}

//
// MFC Dialog handling code
//

void CCancelView::OnLaunch() 
{
	AfxMessageBox(_T("About to launch the progress dialog")
		_T(" in another thread using CWinThread.  The program will appear")
		_T(" to hang while a busy loop in the main thread runs.  The dialog")
		_T(" will not appear until the busy loop finishes.")
		_T("\n\nOnce the dialog is up, the slider control works.  However, if you")
		_T(" select View/Tight Loop, the slider control stops working.")
		_T("\n\nChoose View/Destroy to close the dialog."));

	gCanDlg.StartDialog();
	for (int i=0;i<200000000; i++);
}

void CCancelView::OnBoom() 
{
	gCanDlg.CloseDialog();
}

//
// Win32 Dialog handling code
//
void CCancelView::OnLaunchWin32() 
{
	AfxMessageBox(_T("About to launch the progress dialog")
		_T(" in another thread using CreateThread().  The dialog's parent is the mainframe.")
		_T("\n\nThe program will appear")
		_T(" to hang while a busy loop in the main thread runs.  The dialog")
		_T(" will not appear until the busy loop finishes.")
		_T("\n\nChoose File/Exit to close the dialog."));

	LaunchHelper( AfxGetMainWnd()->GetSafeHwnd() );
}

void CCancelView::OnViewNoparent() 
{
	AfxMessageBox(_T("About to launch the progress dialog")
		_T(" in another thread using CreateThread().  The dialog has no parent.")
		_T(" Notice that minimizing and the taskbar will not set be setup properly.")
		_T("\n\nThe PARENT WINDOW will appear")
		_T(" to hang while a busy loop in the main thread runs, but the dialog")
		_T(" will appear immediately and be fully functional.")
		_T("\n\nChoose File/Exit to close the dialog."));

	LaunchHelper( NULL );
}

void CCancelView::LaunchHelper(HWND hParent)
{
    HANDLE hThrd;
    DWORD threadId;
    
	hThrd = CreateThread(NULL,
         0,
         ThreadFunc,
         (LPVOID)hParent,
         0,
         &threadId );
	if (hThrd)
		CloseHandle(hThrd);
	for (int i=0;i<200000000; i++);
}

DWORD WINAPI ThreadFunc(LPVOID n)
{
	MSG msg;
	HWND hWnd = ::CreateDialog(AfxGetInstanceHandle(),
					MAKEINTRESOURCE(IDD_OUTPUT_MSGDLG),
					(HWND)n,
					NULL);		// No dialog proc
	while (::GetMessage(&msg, hWnd, 0, 0))
	{
		::DispatchMessage(&msg);
	}
	return 0;
}
