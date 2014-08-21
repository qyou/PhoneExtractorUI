
// PhoneExtractorUIDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CPhoneExtractorUIDlg 对话框
class CPhoneExtractorUIDlg : public CDialog
{
// 构造
public:
	CPhoneExtractorUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PHONEEXTRACTORUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
