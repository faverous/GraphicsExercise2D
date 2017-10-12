
// GraphicsExercise2DView.cpp : CGraphicsExercise2DView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GraphicsExercise2D.h"
#endif

#include "GraphicsExercise2DDoc.h"
#include "GraphicsExercise2DView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsExercise2DView

IMPLEMENT_DYNCREATE(CGraphicsExercise2DView, CView)

BEGIN_MESSAGE_MAP(CGraphicsExercise2DView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGraphicsExercise2DView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGraphicsExercise2DView ����/����

CGraphicsExercise2DView::CGraphicsExercise2DView()
{
	// TODO: �ڴ˴���ӹ������

	// -------------------- ��ʼ������ -------------------------

	// ���ù�ģ����
	SetScale(70);

	// ���û��Ƶĺ���
	SetDrawFunction(Sin);

	// �����Ա���x��Χ[startX, endX]��ȡ������step
	SetPlotSin((float)0.0, (float)6.3, (float)0.01);
}

CGraphicsExercise2DView::~CGraphicsExercise2DView()
{
}

BOOL CGraphicsExercise2DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// ���÷�Χ�Ͳ���
void CGraphicsExercise2DView::SetPlotSin(float startX, float endX, float step)
{
	this->startX = startX;
	this->endX = endX;
	this->step = step;
}

// ���û��Ƶĺ���
void CGraphicsExercise2DView::SetDrawFunction(Function fun)
{
	this->fun = fun;
}

// ���ù�ģ
void CGraphicsExercise2DView::SetScale(int scale)
{
	this->scale = scale;
}

// �任��ģ
float CGraphicsExercise2DView::TransformScale(float num)
{
	return num * scale;
}

// �任x������͹�ģ
float CGraphicsExercise2DView::TransformCoordinateScaleX(float x)
{
	return TransformScale(x + 2);
}

// �任y������͹�ģ
float CGraphicsExercise2DView::TransformCoordinateScaleY(float y)
{
	return TransformScale(y + 4);
}

// CGraphicsExercise2DView ����

void CGraphicsExercise2DView::OnDraw(CDC* pDC)
{
	CGraphicsExercise2DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	// -------------------- ��������ϵ -------------------------

	float endPointX = 2 + endX + 2;

	// ����y��
	pDC->MoveTo((int)TransformScale(2), (int)TransformScale(2));
	pDC->LineTo((int)TransformScale(2), (int)TransformScale(6));

	// ����x��
	pDC->MoveTo((int)TransformScale(2), (int)TransformScale(4));
	pDC->LineTo((int)TransformScale(endPointX), (int)TransformScale(4));

	// ����y��ļ�ͷ
	pDC->MoveTo((int)TransformScale((float)1.8), (int)TransformScale((float)2.2));
	pDC->LineTo((int)TransformScale(2), (int)TransformScale(2));
	pDC->LineTo((int)TransformScale((float)2.2), (int)TransformScale((float)2.2));

	// ����x��ļ�ͷ
	pDC->MoveTo((int)TransformScale(endPointX - (float)0.2), (int)TransformScale((float)3.8));
	pDC->LineTo((int)TransformScale(endPointX), (int)TransformScale(4));
	pDC->LineTo((int)TransformScale(endPointX - (float)0.2), (int)TransformScale((float)4.2));

	// -------------------- ���ƿ̶��� -------------------------

	// ����y��̶���
	for (float scaleY = 3; scaleY <= 5; scaleY += 0.2)
	{
		pDC->MoveTo((int)TransformScale(2), (int)TransformScale(scaleY));
		pDC->LineTo((int)TransformScale((float)2.1), (int)TransformScale(scaleY));
	}

	// ����x��̶���
	for (float scaleX = 2.2; scaleX < endPointX - 1; scaleX += 0.2)
	{
		pDC->MoveTo((int)TransformScale(scaleX), (int)TransformScale(4));
		pDC->LineTo((int)TransformScale(scaleX), (int)TransformScale(3.9));
	}


	// -------------------- �������� -------------------------

	// ����y���y
	pDC->TextOutW((int)TransformScale(1.8), (int)TransformScale(2.3), CString("y"));
	// ����x���x
	pDC->TextOutW((int)TransformScale(endPointX - (float)0.5), (int)TransformScale(4.1), CString("x"));

	CString s;
	// ����y��̶�����
	for (float ScaleTextY = 2.9, text = 1.0; ScaleTextY <= 4.9; ScaleTextY += 0.2, text -= 0.2)
	{
		s.Format(_T("%.1f"), text);
		pDC->TextOutW((int)TransformScale(1.6), (int)TransformScale(ScaleTextY), s);
	}

	// ����x��̶�����
	for (float ScaleTextX = 2.3; ScaleTextX < endPointX - 1; ScaleTextX += 0.4)
	{
		s.Format(_T("%.1f"), ScaleTextX - 1.9);
		pDC->TextOutW((int)TransformScale(ScaleTextX), (int)TransformScale(4.1), s);
	}

	// ���ƺ���ͼ��Title
	// �жϵ��õĺ���
	switch (fun)
	{
	case Sin:
		pDC->TextOutW((int)TransformScale(4), (int)TransformScale(6), CString("y = sin( x )"));
		break;
	case Cos:
		pDC->TextOutW((int)TransformScale(4), (int)TransformScale(6), CString("y = cos( x )"));
		break;
	default:
		break;
	}


	// -------------------- ���ƺ��� -------------------------

	// ���ı�����͹�ģ��xy
	float x, y;

	for (x = startX; x <= endX; x += step)
	{
		// �жϵ��õĺ���
		switch (fun)
		{
		case Sin:
			y = (float)sin(x);
			break;
		case Cos:
			y = (float)cos(x);
			break;
		default:
			break;
		}

		// ��xy�ı�����͹�ģ����ʾ��
		pDC->SetPixel((int)TransformCoordinateScaleX(x), (int)TransformCoordinateScaleY(y), 0);
	}
}


// CGraphicsExercise2DView ��ӡ


void CGraphicsExercise2DView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGraphicsExercise2DView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGraphicsExercise2DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGraphicsExercise2DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CGraphicsExercise2DView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGraphicsExercise2DView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGraphicsExercise2DView ���

#ifdef _DEBUG
void CGraphicsExercise2DView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsExercise2DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsExercise2DDoc* CGraphicsExercise2DView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsExercise2DDoc)));
	return (CGraphicsExercise2DDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsExercise2DView ��Ϣ�������
