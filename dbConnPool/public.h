#pragma once
#ifndef PUBLIC_H
#define PUBLIC_H


#define LOG(str) \
	cout << __FILE__ << ":" << __LINE__ << " " << \
	__TIMESTAMP__ << " : " << str << endl;


#endif // !PUBLIC_H