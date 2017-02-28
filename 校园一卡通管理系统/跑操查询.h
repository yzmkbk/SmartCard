#pragma once


// 跑操查询 对话框

class 跑操查询 : public CDialogEx
{
	DECLARE_DYNAMIC(跑操查询)

public:
	跑操查询(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~跑操查询();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAOCAO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
	CString m_RunNum;
	afx_msg void OnPaint();
};
