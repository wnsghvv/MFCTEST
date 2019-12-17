﻿
// Ftn3View.cpp: CFtn3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Ftn3.h"
#endif

#include "Ftn3Doc.h"
#include "Ftn3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFtn3View

IMPLEMENT_DYNCREATE(CFtn3View, CView)

BEGIN_MESSAGE_MAP(CFtn3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CFtn3View 생성/소멸

CFtn3View::CFtn3View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFtn3View::~CFtn3View()
{
}

BOOL CFtn3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFtn3View 그리기

void CFtn3View::OnDraw(CDC* /*pDC*/)
{
	CFtn3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFtn3View 인쇄

BOOL CFtn3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFtn3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFtn3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFtn3View 진단

#ifdef _DEBUG
void CFtn3View::AssertValid() const
{
	CView::AssertValid();
}

void CFtn3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFtn3Doc* CFtn3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFtn3Doc)));
	return (CFtn3Doc*)m_pDocument;
}
#endif //_DEBUG


// CFtn3View 메시지 처리기


int CFtn3View::OnDrawRect()
{
	CClientDC dc(this);
	RECT r;
	GetClientRect(&r);
	int p1, p2, p3;
	p1 = rand() % r.right;
	p2 = rand() % r.bottom;
	p3 = rand() % 50;
	dc.Ellipse(p1 - 25, p2- 10, p1 + 25, p2 + 10);
	return 0;
}


void CFtn3View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON) OnDrawRect();
	srand((unsigned)time(NULL));

	CView::OnMouseMove(nFlags, point);
}
