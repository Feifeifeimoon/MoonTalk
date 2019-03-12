#ifndef _MOONTALK_SRC_CLIENT_CLIENTMANAGE_H
#define _MOONTALK_SRC_CLIENT_CLIENTMANAGE_H

class TcpClient;
class ClientManage
{
public:
	static ClientManage* GetInstance();
	static TcpClient*	 GetLoginClient();
	static TcpClient*    GetMsgClient();
	void                 init();
	static void MsgClientConnect();
private:
	ClientManage() {};
	~ClientManage() {};

private:
	static ClientManage* m_instance;
	static TcpClient*    m_loginClient;
	static TcpClient*    m_msgClient;


};


#endif // !_MOONTALK_SRC_CLIENT_CLIENTMANAGE_H
