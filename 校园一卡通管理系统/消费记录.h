#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// 消费记录 对话框

class 消费记录 : public CDialogEx
{
	DECLARE_DYNAMIC(消费记录)

public:
	消费记录(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~消费记录();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PurchaseHistory };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_消费记录List;
	CString m_UserName;
};
