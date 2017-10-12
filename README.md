# ʹ��MFC��CDC����ƶ�ά����ϵ�������Һ���

## ϵ������

* [ʹ��MFC��CDC����ƶ�ά����ϵ�������Һ���]() / [Դ��]()

* [ʹ��MFC��CDC�������ά����ϵ�����溯��]() / [Դ��]()

## ����

����ʹ��MFC��CDC����ƶ�ά����ϵ�������Һ��������Խ�������任����ģ�任���������û��Ƶĺ�����ͨ�������Ա����ķ�Χ�����������Ƴ���Ӧ�ĺ���ͼ�Ρ�

## �½���Ŀ

`Visual Studio`- `�½���Ŀ` - `MFCӦ�ó���` - ����Ϊ`CGraphicsExercise2D` - `ȷ��` - `��һ��` - Ӧ�ó�������ѡ��`�����ĵ�` - `���`

## ���ƺ���

Visual StudioΪ���Ǵ����˺ܶ����õĴ��룬�����ǵĻ��ƺ�������`CGraphicsExercise2DView.cpp`��

    void CGraphicsExercise2DView::OnDraw(CDC* /*pDC*/)
    {
      CGraphicsExercise2DDoc* pDoc = GetDocument();
      ASSERT_VALID(pDoc);
      if (!pDoc)
      return;

      // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
    }

ȡ��`pDC`��ע�ͣ����

    void CGraphicsExercise2DView::OnDraw(CDC* pDC)

��

    // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

�����д���Լ��ĳ����续һ���ߣ�

    pDC->MoveTo(20, 30);    // �����Ƶ������Ͻ�����20���ء�����30����
    pDC->LineTo(100, 100);    // ��һ���ߵ���100����100��λ��

�����¿���Ч���ɣ�

����ɾ���������������ߣ���ʼ��ʽ��д��ά����ϵ�ˡ�

## ��ģ�任����

�����`MoveTo(20, 30)`�е�20��30������ʾ���ϵ����ص㣬������Ƶ�����ϵ��������Ϊ��С�Ļ�����1��2����С�ĵ�λ����ʾ���Ͼ����Կ����������Ҫ��ģ�任��ͨ���ǰ�С��λ���ϷŴ��ģ���������Ϳ����ˡ�

��`CGraphicsExercise2DView.h`

    public:
      void SetScale(int scale);
      float TransformScale(float num);

    private:
  	  int scale;

��`CGraphicsExercise2DView.cpp`


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

����`CGraphicsExercise2DView()`�������

    // ���ù�ģ����
    SetScale(70);

## �任����͹�ģ

��`CGraphicsExercise2DView.h`

    public:
      float TransformCoordinateScaleX(float x);
      float TransformCoordinateScaleY(float y);

��`CGraphicsExercise2DView.cpp`

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

## ���û��Ƶĺ�������

��`CGraphicsExercise2DView.h`

�����涨��

    // ֧�ֻ��Ƶĺ�������
    enum Function { Sin, Cos };

�����涨��

    public:
      void SetDrawFunction(Function fun);

    private:
      Function fun;

��`GraphicsExerciseView.cpp`

    #include <math.h>

    // ���û��Ƶĺ���
    void CGraphicsExercise2DView::SetDrawFunction(Function fun)
    {
	    this->fun = fun;
    }

����`CGraphicsExercise2DView()`�������

    // ���û��Ƶĺ���
    SetDrawFunction(Sin);

## ������Χ�Ͳ���

���������Һ�����xȡֵ��Χ��`[0, 2*��]`������x��ȡ��������`0.01`��

��`CGraphicsExercise2DView.h`

    public:
      void SetPlotSin(float startX, float endX, float step);

    private:
      float startX, endX, step;

��`CGraphicsExercise2DView.cpp`

    // ���÷�Χ�Ͳ���
    void CGraphicsExercise2DView::SetPlotSin(float startX, float endX, float step)
    {
	     this->startX = startX;
	     this->endX = endX;
	     this->step = step;
    }

����`CGraphicsExercise2DView()`�������

    // �����Ա���x��Χ[startX, endX]��ȡ������step
    SetPlotSin((float)0.0, (float)6.3, (float)0.01);


## ��������ϵ

����ϵ�Ǿ������Ͻ����¸�2 \* ��ģ�����ؿ�ʼ���Ƶģ���y��Ķ����ǣ�2 \* �Ŵ��ģ, 2 \* �Ŵ��ģ����

��`OnDraw()`������`// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���`����������´���

```
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
```

## ���ƺ���

x��startX���Ƶ�endX��ÿ���step����һ�Ρ�

Ҳ����`OnDraw()`�����������

```
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
```

## Ч��ͼ

![GraphicsExercise2DCapture](http://ojlsgreog.bkt.clouddn.com/GraphicsExercise2DCapture.png)
