#ifndef CORE_I_LOG_H
#define CORE_I_LOG_H

namespace core
{
	class iLogNode
	{
	public:
		/*生成最终日志*/
		virtual void GenLog(std::string&) = 0;

		/*日志标题*/
		virtual void Title(std::string&) = 0;

		/*日志信息汇总、总结*/ 
		virtual void Summary(std::string&) = 0;

		/*日志内容格式*/
		virtual void ContentFormat(std::string&) = 0;

		/*添加日志信息*/
		virtual void AddLog(const std::string&) = 0;

		/*重置*/
		virtual void Reset() = 0;

		/*获取日志id*/
		virtual int GetID() = 0;
		
		/*获取日志名*/
		virtual std::string GetName() = 0;
		
		/*获取优先级*/
		virtual int GetPriority() = 0;

		/*设置日志id*/
		virtual void SetID(int id) = 0;
		
		/*设置日志名*/
		virtual void SetName(const std::string& name) = 0;

		/*设置优先级*/
		virtual void SetPriority(int priority) = 0;
	};
}

#endif /*CORE_I_LOG_H*/
