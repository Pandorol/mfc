void CMainFrame::OnMenuDeviceInfo() 
{
	// TODO: Add your command handler code here
	CView* pOldView = GetActiveView();
	CCreateContext context;
	context.m_pCurrentDoc = GetActiveDocument();
	context.m_pNewViewClass = RUNTIME_CLASS(CDeviceInfoView);
	context.m_pCurrentFrame = this;
	CView* pNewView = (CView*)this->CreateView(&context);
	this->SetActiveView(pNewView);
	pNewView->ShowWindow(SW_SHOW);
	pNewView->OnInitialUpdate();
	pNewView->UpdateData(false);
	RecalcLayout();
	pOldView->DestroyWindow();

}

void CMainFrame::OnMenuImpedance() 
{
	// TODO: Add your command handler code here
	CView* pOldView = GetActiveView();
	CCreateContext context;
	context.m_pCurrentDoc = GetActiveDocument();
	context.m_pCurrentFrame = this;
	context.m_pNewViewClass = RUNTIME_CLASS(CImpedanceView);
	CView* pNewView = (CView*)this->CreateView(&context);
	this->SetActiveView(pNewView);
	pNewView->ShowWindow(SW_SHOW);
	pNewView->OnInitialUpdate();
	pNewView->UpdateData(false);
	RecalcLayout();
	pOldView->DestroyWindow();

}

void CMainFrame::OnMenuRecwave() 
{
	// TODO: Add your command handler code here
	CView* pOldView = GetActiveView();
	CCreateContext context;
	context.m_pCurrentDoc = GetActiveDocument();
	context.m_pCurrentFrame = this;
	context.m_pNewViewClass = RUNTIME_CLASS(CRecWaveView);
	CView* pNewView = (CView*)this->CreateView(&context);
	this->SetActiveView(pNewView);
	pNewView->ShowWindow(SW_SHOW);
	pNewView->OnInitialUpdate();
	pNewView->UpdateData(false);
	RecalcLayout();
	pOldView->DestroyWindow();
}
