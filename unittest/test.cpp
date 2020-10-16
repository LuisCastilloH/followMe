#include <gtest/gtest.h>

#include "Clip.h"
#include "ClipList.h"

// -----------------------------------------------------------------------

class ClipTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		c1 = Clip("hola", 2, 1.0, 2.0, "next", "none");
		c2 = Clip("mundo", 3, 1.0, 3.0, "previous", "none");
		c3 = Clip("adios", 1, 4.0, 10, "next", "none");
	}
	Clip c, c1, c2, c3;

};

TEST_F(ClipTest, getName)
{	
	EXPECT_EQ(c.getName(), "");
	EXPECT_EQ(c1.getName(), "hola");
	EXPECT_EQ(c2.getName(), "mundo");
	EXPECT_EQ(c3.getName(), "adios");
}

TEST_F(ClipTest, getTicksToPlay)
{
	EXPECT_EQ(c.getTicksToPlay(), 0);
	EXPECT_EQ(c1.getTicksToPlay(), 2);
	EXPECT_EQ(c2.getTicksToPlay(), 3);
	EXPECT_EQ(c3.getTicksToPlay(), 1);
}

TEST_F(ClipTest, chooseActionDeterministic)
{
	// std::cout << "hola";
	EXPECT_EQ(c.chooseAction(4,1), 2);
	EXPECT_EQ(c1.chooseAction(5,1), 1);
	EXPECT_EQ(c2.chooseAction(4,1), 1);
	EXPECT_EQ(c3.chooseAction(3,3), 2);
}

// -----------------------------------------------------------------------

class ClipListTest : public ::ClipTest
{
protected:
	void SetUp() override
	{
		c1 = new Clip("hola", 2, 1.0, 0.0, "next", "none");
		c2 = new Clip("mundo", 3, 1.0, 3.0, "previous", "none");
		c3 = new Clip("adios", 1, 4.0, 10, "next", "none");
		clips = new ClipList();
	}
	Clip *c1, *c2, *c3, *c;
	ClipList *clips;
};

TEST_F(ClipListTest, addClip)
{
	std::string temp;
	clips->addClip(c1);
	temp = clips->getHead()->getName();
	// std::cout << temp << std::endl;
	EXPECT_EQ(temp, "hola");
	delete clips;
}

TEST_F(ClipListTest, exists)
{
	std::string temp;
	clips->addClip(c1);
	clips->addClip(c2);
	clips->addClip(c3);
	c = clips->exists("adios");
	temp = c->getName();
	// std::cout << temp << std::endl;
	EXPECT_EQ(temp, "adios");
	delete clips;
}

TEST_F(ClipListTest, executeActionDeterministic)
{
	std::string temp;
	clips->addClip(c1);
	clips->addClip(c2);
	clips->executeAction(10,0);
	temp = clips->getHead()->getName();
	// std::cout << temp << std::endl;
	EXPECT_EQ(temp, "mundo");
	delete clips;
}

// -----------------------------------------------------------------------

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}