#ifndef CORE_ERROR_H
#define CORE_ERROR_H

#include <string>
#include <vector>
#include "iLogNode.h"

namespace core
{
	class Error : public iLogNode
	{
	public:
		Error(const std::string& name)
		: m_name(name)
		{
			m_vecLogInfo.clear();
		}

		virtual ~Error()
		{

		}

		/*����������־*/
		virtual void GenInfo(std::string& info)
		{
			info.clear();
			for (size_t index = 0; index < m_vecLogInfo.size(); ++index)
			{
				info += m_vecLogInfo[index];
			}
			info += std::string("\n\n");
		}

		/*��־����*/
		virtual void Title(std::string& title)
		{
			title = "";
		}

		/*��־��Ϣ���ܡ��ܽ�*/
		virtual void Summary(std::string& summary)
		{
			summary = "";
		}

		/*��־��ʽ*/
		virtual void ContentFormat(std::string& cfmt)
		{
			cfmt = "";
		}

		/*�����־��Ϣ*/
		virtual void AddLog(const std::string& strInfo)
		{
			m_vecLogInfo.push_back(strInfo);
		}

		/*����*/
		virtual void Reset();

		/*��ȡ��־id*/
		virtual int GetID()				{ return m_id; }

		/*��ȡ��־��*/
		virtual std::string GetName()	{ return m_name; }

		/*��ȡ���ȼ�*/
		virtual int GetPriority()		{ return m_priority; }

		/*������־id*/
		virtual void SetID(int id)		{ m_id = id; }

		/*������־��*/
		virtual void SetName(const std::string& name)	{ m_name = name; }

		/*�������ȼ�*/
		virtual void SetPriority(int priority)			{ m_priority = priority; }

	private:
		int							m_id;
		int							m_priority;
		std::string					m_name;
		std::vector<std::string>	m_vecLogInfo;
	};
}
#endif /*CORE_ERROR_H*/