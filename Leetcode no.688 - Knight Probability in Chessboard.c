
/**
 * \brief leetCode 688: Knight Probability in Chessboard.
 */

double knightProbability(int n, int k, int row, int column)
{
    int32_t possible_move_row[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int32_t possible_move_col[8]=  {2, -2, 1, -1, 2, -2, 1, -1};
    double probability[n][n][k+1];
    memset(probability, 0, sizeof(probability));
    probability[row][column][0] = 1.0;

    for (size_t step = 1; step <= k;  step ++)
    {
        for (size_t row_no = 0; row_no < n; row_no ++)
        {
            for (size_t col_no = 0; col_no < n; col_no ++)
            {
                for (size_t move_idx = 0; move_idx < 8; move_idx ++)
                {
                    int32_t row_moved = row_no + possible_move_row[move_idx];
                    int32_t col_moved = col_no + possible_move_col[move_idx];

                    if ((row_moved >= 0) && (row_moved < n) && (col_moved >= 0) && (col_moved <n))
                    {
                        probability[row_no][col_no][step] += probability[row_moved][col_moved][step-1]/8.0;
                    }
                }
            }
        }
    }

    double result = 0.0;

    for (size_t i = 0; i < n; i ++)
    {
        for (size_t j = 0; j < n; j ++)
        {
            result += probability[i][j][k];
        }
    }

    return result;
}

