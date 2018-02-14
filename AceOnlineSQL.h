#if !defined(_ACEONLINE_SQL_H_)
#define _ACEONLINE_SQL_H_

// 2008-07-30 by cmkwon, Yedang_Kor ���� DBServer ������ �ӽ÷� Direct �� ���� - dll �ʿ� ����
//#pragma comment(lib, "AceOnlineSQL.lib")					// 2007-09-13 by cmkwon, �� ������ ���� ���̺귯�� ���� �ε�

#define MSBILLING_SIZE_MAX_ACCOUNT_NAME			20		// �ִ� ������
#define MSBILLING_SIZE_MAX_CHARACTER_NAME		20		// �ִ� ĳ���͸�
#define MSBILLING_SIZE_MAX_ACCOUNT_NO			20		// �ִ� ������ȣ
#define MSBILLING_SIZE_MAX_ITEM_NUM				20		// �ִ� �����۹�ȣ ����
#define MSBILLING_SIZE_MAX_ITEM_NAME			20		// �ִ� ������ �̸� ����
#define MSBILLING_SIZE_MAX_IPADDRESS			16		// 
#define MSBILLING_SIZE_MAX_SERVER_NAME			20		// �ִ� ������
//-------------------------------------------------------------------------------
//--						Error code ����
#define ERR_DB_NO_ERROR							0
#define ERR_DB_IS_NOT_ACCOUNTNAME				1			// td_cash_bonus_point ���̺� �������� ����
#define ERR_DB_NOT_ENOUGH_MONEY					2			// ������ Point(CashPoint+BonusPoint)�� �����Ϸ��� �������� ���ݺ��� �۴�
#define ERR_DB_IS_NOT_GAMEUID					3			// �����Ϸ��� ������ ���� ������ ��ϵǾ� ���� ����
#define ERR_DB_INVALID_ITEM						4			// �����Ϸ��� �������� ��ȿ���� ���� - ti_item_info ���̺� ���ų� IsDisable �ʵ尡 0�� �ƴϴ�
#define ERR_DB_IS_NOT_EQUAL_ITEM_UNIT_PRICE		5			// ���� �������� 1���� ������ ���� ������ ��ϵȰͰ� �ٸ���
#define ERR_nCommandCheck						6			// ������� �̿��� �ڵ尡 ��� �ð�� 
#define ERR_nCommandCheck_NoGiftUserIDGiftCharName	7		// ���Ž� �����ϱ� ���ڰ��� �Ѿ�ð�� 
#define ERR_NoGiftUserIDGiftCharName				8		// �����ϱ⿡ ���ڰ��� ������� 

#define ERR_DB_CONNECT_FAIL						100			// ���� DB Server�� ���� ����
#define ERR_DB_QUERY_ERROR						101			// DB Query ����
#define ERR_DB_QUERY_FETCH_ERROR				102			// DB Query ����
#define ERR_DB_INVALID_BILLING_COMMAND			110			// 
//-------------------------------------------------------------------------------



//----------------------------------------------------------------
//-- ���۵����� ����ü
//----------------------------------------------------------------
struct SBILLING_REQ_DATA
{
	int  nCommand;												// �������(1:�ܾ���ȸ, 2:�����۱���, 3:����) // 2007-12-04 by cmkwon, ���� �����ϱ� ���̺귯�� ���� - 
	char szServerName[MSBILLING_SIZE_MAX_SERVER_NAME];			// ���� ���ӱ������� 
	char szUserID[MSBILLING_SIZE_MAX_ACCOUNT_NAME];				// ����������(����ھ��̵�)
	char szUserNo[MSBILLING_SIZE_MAX_ACCOUNT_NO];				// ����������(����ڹ�ȣ)
	char szCharName[MSBILLING_SIZE_MAX_CHARACTER_NAME];			// ����������(���ӳ��� ĳ���͸�)
	char szItemNum[MSBILLING_SIZE_MAX_ITEM_NUM];				// ���� ������ ������(���� ������ ��ϵ� �����۸� ���Ű���)
	int  nBuyItemCount;											// ���� ������ ī��Ʈ
	int  nItemUnitPrice;										// ���� �������� 1���� ����
	char szUserIP[MSBILLING_SIZE_MAX_IPADDRESS];				// ����������(������ IP)	
	char szGiftUserID[MSBILLING_SIZE_MAX_ACCOUNT_NAME];			// 2007-12-04 by cmkwon, ���� �����ϱ� ���̺귯�� ���� - �����޴� ����(����ھ��̵�)
	char szGiftUserNo[MSBILLING_SIZE_MAX_ACCOUNT_NO];			// 2007-12-04 by cmkwon, ���� �����ϱ� ���̺귯�� ���� - �����޴� ����(����ڹ�ȣ)
	char szGiftCharName[MSBILLING_SIZE_MAX_CHARACTER_NAME];		// 2007-12-04 by cmkwon, ���� �����ϱ� ���̺귯�� ���� - �����޴� ����(���ӳ��� ĳ���͸�)
};


//----------------------------------------------------------------
//-- ���ŵ����� ����ü
//----------------------------------------------------------------
struct SBILLING_RET_DATA
{
	int  nRetErrCode;				// ó����� (=0: ����, <>0: ����), ERR_DB_XXXX
	int  nCashPoint;				// ������ �����Ͽ� ������ Point
	int  nBonusPoint;				// �̺�Ʈ Ȥ�� �ٸ� ������ ���� ������ Point
};

// 2008-07-30 by cmkwon, Yedang_Kor ���� DBServer ������ �ӽ÷� Direct �� ���� - dll �ʿ� ����
//extern "C" __declspec(dllimport) int BillingReqExecute(SBILLING_REQ_DATA *i_pReqData, SBILLING_RET_DATA *o_pRetData);

#endif