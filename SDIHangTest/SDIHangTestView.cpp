
// SDIHangTestView.cpp : implementation of the CSDIHangTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDIHangTest.h"
#endif

#include "SDIHangTestDoc.h"
#include "SDIHangTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIHangTestView

IMPLEMENT_DYNCREATE(CSDIHangTestView, CFormView)

BEGIN_MESSAGE_MAP(CSDIHangTestView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSDIHangTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSDIHangTestView construction/destruction

CSDIHangTestView::CSDIHangTestView():CFormView(CSDIHangTestView::IDD)
{
	// TODO: add construction code here
}

CSDIHangTestView::~CSDIHangTestView()
{
}

BOOL CSDIHangTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSDIHangTestView drawing

void CSDIHangTestView::OnDraw(CDC* /*pDC*/)
{
	CSDIHangTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSDIHangTestView printing


void CSDIHangTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSDIHangTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIHangTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIHangTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSDIHangTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSDIHangTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIHangTestView diagnostics

#ifdef _DEBUG
void CSDIHangTestView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIHangTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIHangTestDoc* CSDIHangTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIHangTestDoc)));
	return (CSDIHangTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIHangTestView message handlers
