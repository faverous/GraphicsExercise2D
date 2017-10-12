
// GraphicsExercise2DView.h : CGraphicsExercise2DView ��Ľӿ�
//

#pragma once

// ֧�ֻ��Ƶĺ�������
enum Function { Sin, Cos };

class CGraphicsExercise2DView : public CView
{
protected: // �������л�����
	CGraphicsExercise2DView();
	DECLARE_DYNCREATE(CGraphicsExercise2DView)

// ����
public:
	CGraphicsExercise2DDoc* GetDocument() const;

// ����
public:
	void SetPlotSin(float startX, float endX, float step);
	void SetDrawFunction(Function fun);
	void SetScale(int scale);

	float TransformScale(float num);
	float TransformCoordinateScaleX(float x);
	float TransformCoordinateScaleY(float y);

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CGraphicsExercise2DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	int scale;
	float startX, endX, step;
	Function fun;
};

#ifndef _DEBUG  // GraphicsExercise2DView.cpp �еĵ��԰汾
inline CGraphicsExercise2DDoc* CGraphicsExercise2DView::GetDocument() const
   { return reinterpret_cast<CGraphicsExercise2DDoc*>(m_pDocument); }
#endif

