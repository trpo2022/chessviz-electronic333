#include <chess-logic.h>

// Правильно ли задана фигура
int is_valid_piece (piece p) {
  return p == BLACK_BISHOP ||
         p == WHITE_BISHOP ||
         p == BLACK_KING ||
         p == WHITE_KING ||
         p == BLACK_KNIGHT ||
         p == WHITE_KNIGTH ||
         p == BLACK_PAWN ||
         p == WHITE_PAWN ||
         p == BLACK_QUEEN ||
         p == WHITE_QUEEN ||
         p == BLACK_ROOK ||
         p == WHITE_ROOK ||
         p == EMPTY_FIELD;
}

// Лежат ли индексы строки и столбца в пределах доски
int check_row_col (int row) {
  return row >= 0 && row < BOARD_HEIGTH;
}

int check_col (int col) {
  return col >= 0 && col < BOARD_WIDTH;
}

piece get_at (chess_board board, int row, int col) {
  if (check_row(row) && check_col(col)) {
    return board[row][col];
  }
  else {
    return ERROR_PIECE;
  }
}

void put_at (chess_board board, int row, int col, piece piece) {
  if (check_row(row) && check_col(col) && is_valid_piece(piece)) {
    board[row][col] = piece;
  }
}

void remove_at (chess_board board, int row, int col) {
  if (check_row(row) && check_col(col)) {
    board[row][col] = EMPTY_FIELD;
  }
}

void move (chess_board board, int r1, int c1, int r2, int c2) {
  if (check_row(r1) && check_col(c1) && check_row(r2) && check_col(c2)) {
    piece p = get_at(board, r1, c1);
    remove_at(board, r1, c1);
    put_at(board, r2, c2, p);
  }
}
