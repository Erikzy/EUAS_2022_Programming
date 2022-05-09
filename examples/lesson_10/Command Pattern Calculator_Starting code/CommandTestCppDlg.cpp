// CommandTestCppDlg.cpp : implementation file
//

#include "CommandTestCpp.h"
#include "CommandTestCppDlg.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandTestCppDlg dialog




CCommandTestCppDlg::CCommandTestCppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCommandTestCppDlg::IDD, pParent),
	calculator(30,20),
	command(0),
	addCmd(&calculator),
	subCmd(&calculator),
	mulCmd(&calculator)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommandTestCppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCommandTestCppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RADIO1, &CCommandTestCppDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CCommandTestCppDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CCommandTestCppDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON1, &CCommandTestCppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCommandTestCppDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCommandTestCppDlg message handlers

BOOL CCommandTestCppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	pButton->SetCheck(true);
	command = &addCmd;




	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCommandTestCppDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCommandTestCppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCommandTestCppDlg::OnBnClickedRadio1()
{
	command = &addCmd;
}

void CCommandTestCppDlg::OnBnClickedRadio2()
{	
	command = &subCmd;
}

void CCommandTestCppDlg::OnBnClickedRadio3()
{
	command = &mulCmd;
}

void CCommandTestCppDlg::OnBnClickedButton1()
{
	CString str;
	str.Format(_T("Result: %d"), command->Execute());
	SetDlgItemText(IDC_STATIC3, str);
}

void CCommandTestCppDlg::OnBnClickedButton2()
{
	exit(0);
}
