#include <gtest/gtest.h>

#include "ScheduleSerializer.hpp"
#include "ScheduleParser.hpp"
#include "Common.hpp"
#include "common/fs/FilePath.hpp"

const std::string ScheduleWritePath = "fakeScheduleWrite.xml";

TEST(ScheduleSerializer, SaveToInvalidFile)
{
    ScheduleSerializer serializer;

    ASSERT_THROW(serializer.scheduleTo(ScheduleTests::schedule(), "invalid/path"), ScheduleSerializeException);
}

TEST(ScheduleSerializer, SaveToFile)
{
    ScheduleSerializer serializer;
    serializer.scheduleTo(ScheduleTests::schedule(), ScheduleWritePath);

    ASSERT_EQ(ScheduleTests::schedule(), ScheduleParser{}.scheduleFrom(FilePath{ScheduleWritePath}));
}