#include "WindowMediaService.h"
#include <gtest/gtest.h>

class WindowMediaServiceTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		service = new WindowMediaService();
	}

	void TearDown() override
	{
		delete service;
	}

	WindowMediaService *service;
};

TEST_F(WindowMediaServiceTest, TestStart)
{
	service->start();
	// Add assertions to verify the behavior of start()
}

TEST_F(WindowMediaServiceTest, TestPlayAsync)
{
	bool result = service->playAsync();
	ASSERT_TRUE(result);
	// Add more assertions as needed
}

TEST_F(WindowMediaServiceTest, TestPauseAsync)
{
	bool result = service->pauseAsync();
	ASSERT_TRUE(result);
	// Add more assertions as needed
}

// Add more tests as needed
