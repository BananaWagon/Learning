#pragma once

class GameBase
{
public:
	GameBase();
	~GameBase();
	virtual int		Run();
	virtual void	input();
	virtual void	update();
	virtual void	drawBoard();
	virtual int		alphabeta();
	
	//virtual bool chkWin();
};

///////////////////////////////////////////////////////////////
//                                                           //
//                    Suedo for MiniMax                      //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
//	function minimax(node, depth, maximizingPlayer)          //
//		if depth = 0 or node is a terminal node              //
//			return the heuristic value of node               //
//		if maximizingPlayer                                  //
//			bestValue : = -                                  //
//			for each child of node                           //
//				val : = minimax(child, depth - 1, FALSE)     //
//			  bestValue : = max(bestValue, val)              //
//			return bestValue                                 //
//		else                                                 //
//			bestValue : = +                                  //
//			for each child of node                           //
//				val : = minimax(child, depth - 1, TRUE)      //
//				bestValue : = min(bestValue, val)            //
//			return bestValue                                 //
//                                                           //
//  (*Initial call for maximizing player *)                  //
//  minimax(origin, depth, TRUE)                             //
//                                                           //
///////////////////////////////////////////////////////////////





//(Initial call for maximizing player )
//minimax(origin, depth, TRUE)
//
//for (int i = 0; i < 3; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		if (ipos[i][j] == EMPTY)
//		{
//			miniMax(ipos[i][j], 4, true);
//		}
//	}
//}