// CommandTestCppDlg.h : header file
//

#pragma once
#include "Calculator.h"
#include "Commands.h"

// CCommandTestCppDlg dialog
class CCommandTestCppDlg : public CDialog
{
// Construction
public:
	CCommandTestCppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_COMMANDTESTCPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()




private:	
	Calculator calculator;   
	ACommand *command; //This will be used to invoke commands

	AddCommand addCmd;
	SubtractCommand subCmd;
	MultiplyCommand mulCmd;

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
