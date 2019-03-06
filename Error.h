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

		/*生成最终日志*/
		virtual void GenInfo(std::string& info)
		{
			info.clear();
			for (size_t index = 0; index < m_vecLogInfo.size(); ++index)
			{
				info += m_vecLogInfo[index];
			}
			info += std::string("\n\n");
		}

		/*日志标题*/
		virtual void Title(std::string& title)
		{
			title = "";
		}

		/*日志信息汇总、总结*/
		virtual void Summary(std::string& summary)
		{
			summary = "";
		}

		/*日志格式*/
		virtual void ContentFormat(std::string& cfmt)
		{
			cfmt = "";
		}

		/*添加日志信息*/
		virtual void AddLog(const std::string& strInfo)
		{
			m_vecLogInfo.push_back(strInfo);
		}

		/*重置*/
		virtual void Reset();

		/*获取日志id*/
		virtual int GetID()			{ return m_id; }

		/*获取日志名*/
		virtual std::string GetName()		{ return m_name; }

		/*获取优先级*/
		virtual int GetPriority()		{ return m_priority; }

		/*设置日志id*/
		virtual void SetID(int id)		{ m_id = id; }

		/*设置日志名*/
		virtual void SetName(const std::string& name)	{ m_name = name; }

		/*设置优先级*/
		virtual void SetPriority(int priority)		{ m_priority = priority; }

	private:
		int				m_id;
		int				m_priority;
		std::string			m_name;
		std::vector<std::string>	m_vecLogInfo;
	};
}
#endif /*CORE_ERROR_H*/
