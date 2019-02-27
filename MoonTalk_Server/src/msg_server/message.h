#ifndef MOONTALK_SRC_MESSAGE_H_
#define MOONTALK_SRC_MESSAGE_H_

enum MSG_TYPE {
    MSG_TYPE_LOGIN = 1,
	MSG_TYPE_LOGIN_RET,
	MSG_TYPE_GETUSERINFO,
	MSG_TYPE_GETUSERINFO_RET
};

struct DataHeader
{
	MSG_TYPE type;
	int length;
};

struct UserInfoGet : public DataHeader
{
	char username[64];
    UserInfoGet()
    {
        type = MSG_TYPE_GETUSERINFO;
    }
};

struct UserInfoRet : public DataHeader
{
	char buf[128];
	UserInfoRet()
	{
		type = MSG_TYPE_GETUSERINFO_RET;
	}
};

#endif // !MOONTALK_SRC_MESSAGE_H_