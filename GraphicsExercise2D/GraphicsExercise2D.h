
// GraphicsExercise2D.h : GraphicsExercise2D Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CGraphicsExercise2DApp:
// �йش����ʵ�֣������ GraphicsExercise2D.cpp
//

class CGraphicsExercise2DApp : public CWinAppEx
{
public:
	CGraphicsExercise2DApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGraphicsExercise2DApp theApp;
