/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest,CheckPiezas)
{

  bool check1=true;
  Piezas p;
  for(int i=0;i<BOARD_ROWS;i++)
  {
	for(int j=0;j<BOARD_COLS;j++) 
	{
         if(p.pieceAt(i,j)!=Blank) 
	{
          check1=false;
     	 }
        }
  }
  ASSERT_TRUE(check1);
}

TEST(PiezasTest, CheckReset) 
{

  Piezas p;
  p.dropPiece(0);
  p.reset();
  bool check2=true;

  for(int i = 0; i < BOARD_ROWS; i++)
  {
	for(int j = 0; j < BOARD_COLS; j++)
	{		
	 if(p.pieceAt(i,j) != Blank)
	 {
		check2=false;
	 } 		

	}
   }

  ASSERT_TRUE(check2);

}

TEST(PiezasTest, toggleCheckO)
{

  Piezas p;
  bool check3=true;
  if(p.toggle_piece_turn()!=O)
  {

    check3=false;
  }
  ASSERT_TRUE(check3);

}

TEST(PiezasTest, toggleCheckX) 
{

  Piezas p;
  bool check4=true;
  p.toggle_piece_turn();
  if(p.toggle_piece_turn()!=X)
  {

    check4=false;

  }

  ASSERT_TRUE(check4);

}

TEST(PiezasTest, InvalidplacePiece)

{

	Piezas p;
	ASSERT_TRUE(p.pieceAt(5,1) == Invalid);

}

TEST(PiezasTest, InvaliddropPiece)

{

  Piezas p;
  bool check5= false;

  if(p.dropPiece(5)==Invalid)
  {
   check5=true;
  }

  ASSERT_TRUE(check5);

}


TEST(PiezasTest, fullColumndropPiece)

{

 Piezas p;

 bool check6=false;

 p.dropPiece(0);

 p.dropPiece(0);

 p.dropPiece(0);

 if(p.dropPiece(0)==Blank)
 {
  check6=true;
 }

 ASSERT_TRUE(check6);

}
