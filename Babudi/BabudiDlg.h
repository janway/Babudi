
// BabudiDlg.h : header file
//

#pragma once


// CBabudiDlg dialog
class CBabudiDlg : public CDialogEx
{
// Construction
public:
	CBabudiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BABUDI_DIALOG };

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
	afx_msg void OnBnClickedBtnPlay();

	//
	void GetRandom(size_t i);
	afx_msg void OnBnClickedBtnRun();
	afx_msg void OnBnClickedBtnThread();
	afx_msg void OnBnClickedBtnMisc();
};
