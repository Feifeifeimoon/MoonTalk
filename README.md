# MoonTalk
使用c++编写的即时通讯项目

|     | 客户端 | 服务端 |
|:------:|:------:|:------:|
| 平台 | windows | ubuntu18.04|
| 语言 | c++ | c++|
| 开发工具 | vs2017 | vscode + cmake|



# 客户端
* UI库使用[duilib](https://github.com/duilib/duilib)
* 使用Sqlite3存储用户的数据


# 服务端
* 仿照[muduo](https://github.com/chenshuo/muduo)完成网络库
* 使用Mysql存储所有用户的信息以及好友关系


# 通信协议
* 采用结构体 ＋ Google Protobuf


# 部分截图
![登陆界面](http://github.com/Feifeifeimoon/MoonTalk/raw/master/img/loginFrame.png)

![主界面](http://github.com/Feifeifeimoon/MoonTalk/raw/master/img/mainFrame.png)

![服务端](http://github.com/Feifeifeimoon/MoonTalk/raw/master/img/server.png)
# 任务清单
## 客户端
* 好友列表的读取显示
* 聊天窗口
* 信息修改窗口

## 服务端
* 服务器日志的制作
* 完善线程池和数据库连接池
* 聊天信息的转发



革命尚未成功
同志仍需努力
