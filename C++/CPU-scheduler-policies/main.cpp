#include "scheduler.hpp"

int main()
{
    Scheduler cpu;

    cpu.IncludeJob(100, "word");
    cpu.IncludeJob(200, "steam");
    cpu.IncludeJob(300, "excel");
    cpu.IncludeJob(400, "wireshark");
    cpu.IncludeJob(500, "chrome");

    cpu.ShowJobs();

    //cpu.ExecuteJob();
    Policy1 *p1  = (Policy1*) &cpu;
    Policy2 *p2  = (Policy2*) &cpu;

    p1->ExecuteJob();
    p1->ExecuteJob();
    p1->ExecuteJob();
    p2->ExecuteJob();
    cpu.ShowJobs();

    return 0;
}
