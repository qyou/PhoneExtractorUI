
// PhoneExtractorUIDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CPhoneExtractorUIDlg �Ի���
class CPhoneExtractorUIDlg : public CDialog
{
// ����
public:
	CPhoneExtractorUIDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PHONEEXTRACTORUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnFile();
	afx_msg void OnBnClickedBtnDir();
	afx_msg void OnBnClickedOk();
private:
	CString m_strFilePath;
	CListBox m_lbPhoneList;
public:
	afx_msg void OnBnClickedBtnSave();
private:
	CString m_strPhoneContent;
};
