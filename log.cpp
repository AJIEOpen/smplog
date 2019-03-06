#include "log.h"

void core::Log::Open(std::ofstream& file)
{
	// ʱ��
	using namespace std::chrono;
	system_clock::time_point now = system_clock::now();
	std::time_t t = system_clock::to_time_t(now);

	std::stringstream date;
	date << std::put_time(std::localtime(&t), "%F\\");

	// Ŀ¼
	m_path = std::string(".\\") + m_gameName + std::string("\\") + date.str().c_str();

	// ����Ŀ¼
	char tmpDir[1024] = { 0 };
	for (size_t i = 0; i < m_path.length(); ++i)
	{
		tmpDir[i] = m_path[i];
		if (tmpDir[i] != '\\' && tmpDir[i] != '/')
		{
			continue;
		}

		if (_access(tmpDir, 0) != 0)
		{
			int ret = _mkdir(tmpDir);
			if (ret != 0)
			{
				return;
			}
		}
	}

	// �����ļ�
	std::stringstream hms;
	hms << std::put_time(std::localtime(&t), "%H_%M_%S");

	char szFile[128] = { 0 };
	sprintf_s(szFile, "%s%d_%d_%s.txt", m_path.c_str(), m_pGameDesk->GetRoom()->GetID(), m_pGameDesk->GetDeskID(), hms.str().c_str());

	std::ofstream f(szFile, std::ios::app);
	if (f.fail())
	{
		m_canWrite = false;
		return;
	}

	file = f;
}

// �����нڵ����־ͳһд��һ���ļ�
void core::Log::Write()
{
	std::ofstream file;
	Open(file);

	if (!m_canWrite)
	{
		return;
	}

	// ��ʱ�������ȼ�����
	for (auto iter = m_mapLogNode.begin(); iter != m_mapLogNode.end(); ++iter)
	{
		iLogNode& node = iter->second;
		
		std::string logInfo;
		node.GenLog(logInfo);

		file.write(logInfo.c_str(), logInfo.length());
	}

	file.flush();
	file.close();
}

void core::Log::Reset()
{
	m_path = "";
	m_maxId = 0;
	m_roomId = 0;
	m_deskId = 0;
	m_canWrite = false;
}

// ע��һ����־�ڵ�
void core::Log::Register(iLogNode* node)
{
	if (NULL == node)
	{
		return;
	}

	++m_maxId;
	m_mapLogNode[m_maxId] = node;
}

// ��ӽڵ���־
void core::Log::AddNodeLog(int id, const std::string& strLog)
{
	auto iter = m_mapLogNode.find(id);
	if (iter == m_mapLogNode.end())
	{
		return;
	}

	m_mapLogNode[m_maxId].AddLog(strLog);
}