
// PhoneExtractorUIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PhoneExtractorUI.h"
#include "PhoneExtractorUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CPhoneExtractorUIDlg �Ի���




CPhoneExtractorUIDlg::CPhoneExtractorUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoneExtractorUIDlg::IDD, pParent)
	, m_strFilePath(_T(""))
	, m_strPhoneContent(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPhoneExtractorUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PHONE, m_lbPhoneList);
}

BEGIN_MESSAGE_MAP(CPhoneExtractorUIDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_FILE, &CPhoneExtractorUIDlg::OnBnClickedBtnFile)
	ON_BN_CLICKED(IDC_BTN_DIR, &CPhoneExtractorUIDlg::OnBnClickedBtnDir)
	ON_BN_CLICKED(IDOK, &CPhoneExtractorUIDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CPhoneExtractorUIDlg::OnBnClickedBtnSave)
END_MESSAGE_MAP()


// CPhoneExtractorUIDlg ��Ϣ�������

BOOL CPhoneExtractorUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPhoneExtractorUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPhoneExtractorUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPhoneExtractorUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CPhoneExtractorUIDlg::OnBnClickedBtnFile()
{
	// ѡ���ļ�
	m_strPhoneContent = "";
	CFileDialog fileDlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST,TEXT("Office Files(*.doc, *.docx, *.xls, *.xlsx)|*.doc; *.docx; *.xls; *.xlsx|TXT Files(*.txt)|*.txt|All Files(*.*)|*.*||"),NULL); 
	if (IDOK == fileDlg.DoModal()) {
		m_strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_FILEPATH,m_strFilePath);
	}

}

void CPhoneExtractorUIDlg::OnBnClickedBtnDir()
{
	// ѡ���ļ���
	m_strPhoneContent = "";
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = m_hWnd;
	bi.ulFlags   = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	BOOL bRet = FALSE;
	TCHAR szFolder[MAX_PATH*2];
	szFolder[0] = _T('\0');
	if (pidl)
	{
		if (SHGetPathFromIDList(pidl, szFolder))  
			bRet = TRUE;
		IMalloc *pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)
		{ 
			pMalloc->Free(pidl); 
			pMalloc->Release();
		}
	}

	m_strFilePath = szFolder;
	SetDlgItemText(IDC_EDIT_FILEPATH, m_strFilePath);

}

// Redirect the console to the Ctrl
// Redirect Console ->Tmpfile->readTo Ctrl->Delete Tmpfile

void CPhoneExtractorUIDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (m_strFilePath.IsEmpty()) {
		MessageBox(TEXT("��ѡ���ļ����ļ���"), TEXT("����"));
		return;
	}

	m_lbPhoneList.ResetContent();

	STARTUPINFO si;   

	PROCESS_INFORMATION pi;   

	ZeroMemory( &si, sizeof(si) );   

	si.cb = sizeof(si);   

	ZeroMemory( &pi, sizeof(pi) );

	SECURITY_ATTRIBUTES sa={sizeof ( sa ),NULL,TRUE};  
	SECURITY_ATTRIBUTES *psa=NULL;  
	DWORD dwShareMode=FILE_SHARE_READ|FILE_SHARE_WRITE;  
	OSVERSIONINFO osVersion={0};  
	osVersion.dwOSVersionInfoSize =sizeof ( osVersion );  
	if ( GetVersionEx ( &osVersion ) )  
	{  
		if ( osVersion.dwPlatformId ==VER_PLATFORM_WIN32_NT )  
		{  
			psa=&sa;  
			dwShareMode|=FILE_SHARE_DELETE;  
		}  
	}  

	HANDLE hConsoleRedirect=CreateFile (  
		TEXT("tmp.txt"),  
		GENERIC_WRITE,  
		dwShareMode,  
		psa,  
		OPEN_ALWAYS,  
		FILE_ATTRIBUTE_NORMAL,  
		NULL );  
	ASSERT ( hConsoleRedirect!=INVALID_HANDLE_VALUE ); 
	
    si.dwFlags =STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
	si.hStdOutput =hConsoleRedirect;//
	si.wShowWindow =SW_HIDE;//���ؿ���̨����   

	CString cmdLine;
	cmdLine.Format(TEXT("PhoneExtractor.exe %s"), m_strFilePath);

	if(!CreateProcess(NULL, (LPSTR)(LPCTSTR)cmdLine, NULL, NULL,TRUE,0, NULL,  NULL, &si,  &pi))   

	{   

		MessageBox(TEXT("PhoneExtractor.exe û���ҵ�"),TEXT("����"),MB_OK);

	}  

	WaitForSingleObject( pi.hProcess, INFINITE );     

	CloseHandle( pi.hProcess );   

	CloseHandle( pi.hThread );  
	
	CloseHandle ( hConsoleRedirect );  


	//::MessageBox(NULL,TEXT("�ص���������"),TEXT("��������"),MB_OK);
	CFile tmpFile(TEXT("tmp.txt"), CFile::modeRead);
	int len = tmpFile.GetLength();
	TCHAR *pszPhoneContent = new TCHAR[len+1];
	ZeroMemory(pszPhoneContent, len+1);
	tmpFile.Read(pszPhoneContent, len);
	tmpFile.Close();
	DeleteFile(TEXT("tmp.txt"));
	m_strPhoneContent = pszPhoneContent;
	int i=0;
	int j;
	while ((j=m_strPhoneContent.Find('\n', i)) > 0) {
		m_lbPhoneList.AddString(m_strPhoneContent.Mid(i, j-i));
		i = j+1;
	}

	delete[] pszPhoneContent;

}

void CPhoneExtractorUIDlg::OnBnClickedBtnSave()
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(FALSE, TEXT("txt"), TEXT("default"), 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, TEXT("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"), NULL);
	CString fileOut;
	if (IDOK == fileDlg.DoModal()) {
		fileOut = fileDlg.GetPathName();
		CFile file(fileOut, CFile::modeCreate | CFile::modeWrite);
		file.Write(m_strPhoneContent, m_strPhoneContent.GetLength());
		file.Close();
	}
}
