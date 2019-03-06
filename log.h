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

		// �����нڵ����־ͳһд��һ���ļ�
		void Write();

		// ע��һ����־�ڵ�
		void Register(iLogNode* node);

		// ��ӽڵ���־
		void AddNodeLog(int id, const std::string& strLog);

		void SetRoomId(DWORD id)	{ m_roomId = id; }
		void SetDeskId(WORD id)		{ m_deskId = id; }

	private:
		void Open(std::ofstream& file);

	private:
		std::string					m_path;				// ��ǰĿ¼
		std::string					m_gameName;			// ��Ϸ��
		DWORD						m_roomId;			// ��ǰ����ID
		WORD						m_deskId;			// ��ǰ����ID
		int							m_maxId;			// ��ǰ�����־�ڵ�ID
		std::map<int, iLogNode*>	m_mapLogNode;		// ��־�ڵ㼯��
		bool						m_canWrite;			// �Ƿ���д����־
	};
}

#endif /*CORE_LOG_H*/