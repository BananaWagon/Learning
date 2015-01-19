﻿#pragma once
#include "GameBase.h"
#include "Board.h"

class TicTacToe :
	public GameBase
{
	Board TTT;
public:
	TicTacToe();
	~TicTacToe();
	int Run();
	void drawBoard();

private:
	int _gameState;
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
//			bestValue : = -∞                                 //
//			for each child of node                           //
//				val : = minimax(child, depth - 1, FALSE)     //
//			  bestValue : = max(bestValue, val)              //
//			return bestValue                                 //
//		else                                                 //
//			bestValue : = +∞                                 //
//			for each child of node                           //
//				val : = minimax(child, depth - 1, TRUE)      //
//				bestValue : = min(bestValue, val)            //
//			return bestValue                                 //
//                                                           //
//  (*Initial call for maximizing player *)                  //
//  minimax(origin, depth, TRUE)                             //
//                                                           //
///////////////////////////////////////////////////////////////