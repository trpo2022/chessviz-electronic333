#pragma once

// Чтобы не переусложнять, моя доска для шахмат 
// будет константного размера 8х8.
// Никаких извращений типа 8х10.
#define BOARD_WIDTH 8 // Ширина шахматной доски
#define BOARD_HEIGTH 8 // Её высота

// По FEN нотации
#define BLACK_PAWN 'p' // Пешки
#define WHITE_PAWN 'P'
#define BLACK_KNIGHT 'n' // Кони
#define WHITE_KNIGTH 'N'
#define BLACK_BISHOP 'b' // Слоны
#define WHITE_BISHOP 'B'
#define BLACK_ROOK 'r' // Ладьи
#define WHITE_ROOK 'R'
#define BLACK_QUEEN 'q' // Королевы
#define WHITE_QUEEN 'Q'
#define BLACK_KING 'k' // Короли
#define WHITE_KING 'K'

#define EMPTY_FIELD ' ' // Пустая клетка на доске

// Возвращается при ошибке
// Например, get_at возращает # если неверно задана позиция
#define ERROR_PIECE '#'

// Игроки
#define PLAYER_WHITE 0
#define PLAYER_BLACK 1

typedef char chess_board[BOARD_HEIGTH][BOARD_WIDTH];
typedef char piece;

// Где int, int in [0 to BOARD_HEIGTH], [0 to BOARD_WIDTH]
piece get_at (chess_board, int, int); // Возвращает фигуру по координатам
void put_at (chess_board, int, int, piece); // Устанавливает фигуру по координатам
void remove_at (chess_board, int, int); // Удаляем фигуру

void move (chess_board, int, int, int, int); // Делаем ход
