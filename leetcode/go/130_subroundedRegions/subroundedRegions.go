package main

import "fmt"

func solve(board [][]byte) {
	rows := len(board)
	if rows == 0 {
		return
	}
	cols := len(board[0])

	for i := 0; i < rows; i++ {
		dfs(board, i, 0)
		dfs(board, i, cols-1)
	}
	for i := 0; i < cols; i++ {
		dfs(board, 0, i)
		dfs(board, rows-1, i)
	}

	for row, _ := range board {
		for col, _ := range board[row] {
			if board[row][col] == 'A' {
				board[row][col] = 'O'
			} else if board[row][col] == 'O' {
				board[row][col] = 'X'

			}
		}
	}

}

func dfs(board [][]byte, x int, y int) {
	rows := len(board)
	if rows == 0 {
		return
	}
	cols := len(board[0])

	if x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O' {
		return
	}

	board[x][y] = 'A'
	dfs(board, x-1, y)
	dfs(board, x+1, y)
	dfs(board, x, y-1)
	dfs(board, x, y+1)

}

func main() {
	board := [][]byte{[]byte("XXXX"), []byte("XOOX"), []byte("XXOX"), []byte("XOXX")}
	solve(board)
	for row, _ := range board {
		fmt.Printf("%v\n", string(board[row]))
	}
}
