
// PhoneExtractorUI.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPhoneExtractorUIApp:
// �йش����ʵ�֣������ PhoneExtractorUI.cpp
//

class CPhoneExtractorUIApp : public CWinAppEx
{
public:
	CPhoneExtractorUIApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPhoneExtractorUIApp theApp;