#ifndef CORE_LOG_H
#define CORE_LOG_H

#include <string>
#include <map>
#include <io.h>
#include <direct.h>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iostream>

#include "iLogNode.h"

namespace core
{
	class Log
	{
	public:
		Log(const std::string& gameName, DWORD roomID, WORD deskID)
		: m_path("")
		, m_maxId(0)
		, m_roomId(roomID)
		, m_deskId(deskID)
		, m_gameName(gameName)
		, m_canWrite(false)
		{
			m_mapLogNode.clear();
		}

		virtual ~Log()
		{

		}

		void Reset();

		// 将所有节点的日志统一写入一个文件
		void Write();

		// 注册一个日志节点
		void Register(iLogNode* node);

		// 添加节点日志
		void AddNodeLog(int id, const std::string& strLog);

		void SetRoomId(DWORD id)	{ m_roomId = id; }
		void SetDeskId(WORD id)		{ m_deskId = id; }

	private:
		void Open(std::ofstream& file);

	private:
		std::string					m_path;				// 当前目录
		std::string					m_gameName;			// 游戏名
		DWORD						m_roomId;			// 当前房间ID
		WORD						m_deskId;			// 当前桌子ID
		int						m_maxId;			// 当前最大日志节点ID
		std::map<int, iLogNode*>			m_mapLogNode;			// 日志节点集合
		bool						m_canWrite;			// 是否能写入日志
	};
}

#endif /*CORE_LOG_H*/
