
// 校园一卡通管理系统Dlg.h : 头文件
//

#pragma once


// C校园一卡通管理系统Dlg 对话框
class C校园一卡通管理系统Dlg : public CDialogEx
{
// 构造
public:
	C校园一卡通管理系统Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcmenubutton1();
	afx_msg void OnBnClickedButton1();

	CString m_UserName;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32777();
	afx_msg void On32778();
};
