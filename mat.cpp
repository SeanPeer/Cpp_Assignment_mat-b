/**
 * @file mat.cpp
 * @author Sean Peer (SeanPeer@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (tmp_col) 2022
 * 
 */
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "mat.hpp"

const int lowest_ascii = 33;
const int highest_ascii = 126;

using namespace std;
using namespace ariel;

string ariel::mat(int col,int row,char symbol1,char symbol2)
{
    if((row % 2 == 0) || (col % 2 == 0)){ throw  ("The number of the rows and columns must be odd number !");}
    if((row < 0) || (col < 0)){ throw ("row and columns must be positive numbers only !");}
    if((symbol1 < lowest_ascii) || (symbol1 > highest_ascii) || (symbol2 < lowest_ascii) || (symbol2 > highest_ascii)){ throw ("The symbols you asked for are invalid");}

    string mat;
    int i = 0;
    int curr_row = 0; 
    int curr_col = 0;
    // Save a copy of the given row and column for decreasing them
    int row_cpy = row;
    int col_cpy = col;
    vector<vector<char>> result (row,vector<char> (col));
    // Initialize the first symbol to be in use as the current symbol
    char curr_symbol = symbol1; 
 
    
 
 
    // Fill the given symbols in result matrix going in spiral form where every iteration fills the current rectangele in symbol1 or symbol2
    while (curr_row < row_cpy && curr_col < col_cpy)
    {
        // Fill the current row with the current symbol and after filling decrease the increase curr in order to know where is the first raw i didnt fill yet.
        for (i = curr_col; i < col_cpy; ++i)
        {
            result[curr_row][i] = curr_symbol;
        }
        curr_row++;
 

        // Fill the last col with the current symbol and after filling decrease the col copy in order to know where is the last col i didnt fill yet.
          for (i = curr_row; i < row_cpy; ++i)
        {
            result[i][col_cpy-1] = curr_symbol;
        }    
        col_cpy--;
 
        // Fill the last row from the remaining rows with the current symbol
        if (curr_row < row_cpy)
        {
            for (i = col_cpy-1; i >= curr_col; --i)
            {
                result[row_cpy-1][i] = curr_symbol;
            }    
            row_cpy--;
        }
 
        // Fill the first column from the remaining columns with the current symbol
        if (curr_col < col_cpy)
        {
            for (i = row_cpy-1; i >= curr_row; --i)
            {
                result[i][curr_col] = curr_symbol;
            }
            curr_col++;
        }
 
        //switch symbols for the next iteration
        if (curr_symbol != symbol2 ){
            curr_symbol = symbol2;
        }else {curr_symbol = symbol1;}
        
    }
    // Push the matrix we've made into a string 
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            mat += result[i][j];
        }
        mat += "\n";

    } 
    return mat;
}

