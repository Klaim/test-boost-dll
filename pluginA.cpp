

#include <boost/thread.hpp>
#include <boost/chrono.hpp>

int main()
{

    const boost::chrono::nanoseconds SLEEP_DURATION(boost::chrono::milliseconds(500));
    const auto SLEEP_DURATION_MS = boost::chrono::duration_cast<boost::chrono::milliseconds>(SLEEP_DURATION);
    const auto SLEEP_DURATION_US = boost::chrono::duration_cast<boost::chrono::microseconds>(SLEEP_DURATION);
    const auto SLEEP_DURATION_NANO = boost::chrono::duration_cast<boost::chrono::nanoseconds>(SLEEP_DURATION);
    const auto SLEEP_DURATION_STEADY = boost::chrono::duration_cast<boost::chrono::steady_clock::duration>(SLEEP_DURATION);


    const auto begin = boost::chrono::steady_clock::now();
    boost::this_thread::sleep_for(SLEEP_DURATION);
    const auto end = boost::chrono::steady_clock::now();
    const auto sleep_duration = end - begin;
    const auto sleep_duration_ms = boost::chrono::duration_cast<boost::chrono::milliseconds>(sleep_duration);
    const auto sleep_duration_us = boost::chrono::duration_cast<boost::chrono::microseconds>(sleep_duration);
    const auto sleep_duration_nano = boost::chrono::duration_cast<boost::chrono::nanoseconds>(sleep_duration);

    assert(sleep_duration >= SLEEP_DURATION);
    assert(sleep_duration_ms >= SLEEP_DURATION_MS);
    assert(sleep_duration_us >= SLEEP_DURATION_US);
    assert(sleep_duration_nano >= SLEEP_DURATION_NANO);

}
