#include <ProfilingTimer.h>

ProfilingTimer::ProfilingTimer(std::string name)
        : mLocalName(name) {
    sNestedName += mLocalName;
    sNestedName += " > ";

    if (sTimetable.find(sNestedName) == sTimetable.end())
        sTimetable[sNestedName] = 0;

    mStartTick = Platform::GetTimerTicks();
}

ProfilingTimer::~ProfilingTimer() {
    long long totalTicks = Platform::GetTimerTicks() - mStartTick;

    sTimetable[sNestedName] += totalTicks;

    sNestedName.erase(sNestedName.length() - mLocalName.length() - 3);
}