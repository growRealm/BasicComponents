#pragma once
#ifndef CONNECTION_H
#define CONNECTION_H

#include <mysql.h>
#include <string>
#include <ctime>
using namespace std;

/*
 * 实现MySQL数据库的操作
 */
class Connection
{
private:
	MYSQL *_conn;		// 表示和MySQL Server的一条连接
	clock_t _alivetime; // 记录进入空闲状态后的起始存活时间

public:
	// 初始化数据库连接
	Connection();

	// 释放数据库连接资源
	~Connection();

	// 连接数据库
	bool connect(string ip,
				 unsigned short port,
				 string username,
				 string password,
				 string dbname);

	// DML：insert、delete、update
	bool update(string sql);

	// DQL：select
	MYSQL_RES *query(string sql);

	// 刷新一下连接的起始的空闲时间点
	void refreshAliveTime() { _alivetime = clock(); }

	// 返回存活的时间
	clock_t getAliveTime() const { return clock() - _alivetime; }
};

#endif // !CONNECTION_H