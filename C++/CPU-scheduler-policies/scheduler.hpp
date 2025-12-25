#include <iostream>
#include <vector>

using namespace std;

class Scheduler
{
private:
protected:
    vector< pair<size_t, string>> m_tasks;
public:
    void IncludeJob(size_t id, string name)
    {
        pair<size_t, string> job(id, name);
        m_tasks.push_back(job);
    }

    void ShowJobs()
    {
        for(size_t i=0; i<m_tasks.size(); i++)
        {
            cout << "Job id:" << m_tasks.at(i).first << " Job name:" << m_tasks.at(i).second << endl;
        }
    }

    void ExecuteJob()
    {
        cout << "Nothing to do at this level" << endl;
    }
};

class Policy1 : public Scheduler
{
public:
    void ExecuteJob()
    {
        cout << "Executing Job id:" << m_tasks.at(0).first << " Job name:" << m_tasks.at(0).second;

        cout << "....done" << endl;

        m_tasks.erase(m_tasks.begin() + 0);
    }
};

class Policy2 : public Scheduler
{
public:
    void ExecuteJob()
    {
        size_t pos = m_tasks.size()-1;
        cout << "Executing Job id:" << m_tasks.at(pos).first << " Job name:" << m_tasks.at(pos).second;

        cout << "....done" << endl;

        m_tasks.erase(m_tasks.begin() + pos);
    }
};

