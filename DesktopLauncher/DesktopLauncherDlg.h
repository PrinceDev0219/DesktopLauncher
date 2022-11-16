
// DesktopLauncherDlg.h : header file
//

#pragma once


// CDesktopLauncherDlg dialog
class CDesktopLauncherDlg : public CDialogEx
{
// Construction
public:
	CDesktopLauncherDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DESKTOPLAUNCHER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCLinkCtrl m_ctlLinkBooks;
	CMFCLinkCtrl m_ctlLinkBills;
	CMFCLinkCtrl m_ctlLinkExcel;
	CMFCLinkCtrl m_ctlLinkWord;
	afx_msg void OnDoubleclickedMfclinkExcel();
	CMFCLinkCtrl m_ctlLinkHtml;
	afx_msg void OnBnClickedBtn7z();
};
