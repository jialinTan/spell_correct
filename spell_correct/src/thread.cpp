#include "thread.h"
namespace THREAD
{
    void CThread::start(CThread_RUN* arg)
    {
        arg->set_log(m_log);
        arg->set_cache(&m_cache);
        pthread_create(&m_tid,NULL,thread_func,(void*)arg);
    }
    hash_record* CThread::get_record()
    {
        return &m_cache;
    }
    void CThread::set_log(LOG_SYSTEM::Log_system* log)
    {
        m_log=log;
    }
    void* CThread::thread_func(void* obj)
    {
        pthread_detach(pthread_self());
        CThread_RUN* obj1=(CThread_RUN*)obj;
        obj1->run();//这个地方用到了多态,传入的是CRun的子类,执行的是子类的run函数。
    }
}
