
// DesktopLauncherDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DesktopLauncher.h"
#include "DesktopLauncherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDesktopLauncherDlg dialog



CDesktopLauncherDlg::CDesktopLauncherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DESKTOPLAUNCHER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDesktopLauncherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_MFCLINK_Books, m_ctlLinkBooks);
	DDX_Control(pDX, IDC_MFCLINKBills, m_ctlLinkBills);
	DDX_Control(pDX, IDC_MFCLINK_Excel, m_ctlLinkExcel);
	DDX_Control(pDX, IDC_MFCLINK_Word, m_ctlLinkWord);
	DDX_Control(pDX, IDC_MFCLINK_HTML, m_ctlLinkHtml);
}

BEGIN_MESSAGE_MAP(CDesktopLauncherDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_DOUBLECLICKED(IDC_MFCLINK_Excel, &CDesktopLauncherDlg::OnDoubleclickedMfclinkExcel)
	ON_BN_CLICKED(IDC_Btn_7z, &CDesktopLauncherDlg::OnBnClickedBtn7z)
END_MESSAGE_MAP()


// CDesktopLauncherDlg message handlers

BOOL CDesktopLauncherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_ctlLinkBooks.SetURL(L"CMD.EXE");
	m_ctlLinkBills.SetURL(L"http:\\google.com");
	m_ctlLinkExcel.SetURL(L"EXCEL.EXE");
	m_ctlLinkWord.SetURL(L"WINWORD.EXE");
	m_ctlLinkHtml.SetURL(L"chrome.exe");

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDesktopLauncherDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDesktopLauncherDlg::OnPaint()
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
HCURSOR CDesktopLauncherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDesktopLauncherDlg::OnDoubleclickedMfclinkExcel()
{
	// TODO: Add your control notification handler code here
	
}


void CDesktopLauncherDlg::OnBnClickedBtn7z()
{
	// TODO: Add your control notification handler code here
	
}
