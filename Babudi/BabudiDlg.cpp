
// BabudiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Babudi.h"
#include "BabudiDlg.h"
#include "afxdialogex.h"
#include "Emitter.h"
#include <ppl.h>
#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <deque>
#include <algorithm>
#include <time.h>
#include "Greeting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/*
using namespace concurrency;
using namespace std;*/

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBabudiDlg dialog



CBabudiDlg::CBabudiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBabudiDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBabudiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBabudiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_PLAY, &CBabudiDlg::OnBnClickedBtnPlay)
	ON_BN_CLICKED(IDC_BTN_RUN, &CBabudiDlg::OnBnClickedBtnRun)
	ON_BN_CLICKED(IDC_BTN_THREAD, &CBabudiDlg::OnBnClickedBtnThread)
	ON_BN_CLICKED(IDC_BTN_MISC, &CBabudiDlg::OnBnClickedBtnMisc)
	ON_BN_CLICKED(IDC_BTN_GREET, &CBabudiDlg::OnBnClickedBtnGreet)
END_MESSAGE_MAP()


// CBabudiDlg message handlers

BOOL CBabudiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBabudiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBabudiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBabudiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBabudiDlg::OnBnClickedBtnPlay()
{
	// TODO: Add your control notification handler code here
	//main();
	/*
	const size_t N = 10;
	int* a = new int[N];

	for (size_t n = 0; n < N; ++n)
		a[n] = n;
	for (size_t n = N; n-- > 0;) // Reverse cycles are tricky for unsigned types.
		TRACE(_T("%d \n"),a[n]);
	delete[] a;*/
	//
	concurrency::parallel_for(size_t(0), size_t(50), [&](size_t i)
	{
		TRACE(_T("%d\n"),i);
		GetRandom(i);
	});
	//cout << endl;
	TRACE("end");
}

void CBabudiDlg::GetRandom(size_t i)
{
	for (size_t j=0;j<100000;j++)
	{
		//(void)0;
		//Sleep(1);
		//TRACE(_T("i=%d,j=%d\n"),i,j);
	}
}


void CBabudiDlg::OnBnClickedBtnRun()
{
	for (size_t i=0;i<50;i++)
	{
		GetRandom(i);
	}
}
void CBabudiDlg::OnBnClickedBtnThread()
{
	
	//CEmitter emitter;

	//
	std::thread t((CEmitter())); //double parenthesis to avoid returning an object instead of a thread
	//std::thread t = std::thread(CEmitter());
	//std::thread t{CEmitter}; //compile error

	t.detach();
	TRACE(_T("stop at main thread"));



}
void CBabudiDlg::OnBnClickedBtnGreet()
{
	// TODO: Add your control notification handler code here
	//CGreeting *g = new CGreeting(4);
	//std::thread t(CGreeting("goodbye"));
	//std::thread t(*g);


	//std::thread t = std::thread(CGreeting(313));
	//t.join();


	//delete g;

	CGreeting obj;
	int x = 100;
	std::thread t(&CGreeting::Call,&obj,x);
	t.join();


	//_crtBreakAlloc;
	//_CrtDumpMemoryLeaks();
	///TRACE(_T("exit at main thread"));

}

void CBabudiDlg::OnBnClickedBtnMisc()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox(_T("test"),0);
	TRACE("test\n");
	std::vector<std::string> vec;
	vec.push_back("test222");
	vec.push_back("test223");
	vec.push_back("test224");
	for (auto s : vec) {
		TRACE(CString(s.c_str()));
		TRACE("test\n");
	}
	std::vector<int> vecI(10);
	generate(vecI.begin(),vecI.end(),[] {
		return std::rand()*100;
	});
	for (auto i : vecI) {
		TRACE(_T("%d\n"),i);
	}

	time_t timer;
	struct tm y2k = {0};
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	//time(&timer);  /* get current time; same as: timer = time(NULL)  */
	timer = time(NULL);

	seconds = difftime(timer,mktime(&y2k));

	TRACE("%.f seconds since January 1, 2000 in the current timezone", seconds);

	/**/
	// just test 22224999 


}

