public class Main {

    public static void main(String[] args) {
        boolean[][] arr = trueFalseBoard(3);

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    static boolean[][] trueFalseBoard(int num) {

        if (num % 2 == 0) {
            return null;
        }

        boolean[][] board = new boolean[5][6];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (i == j || i + j == 4) {
                    board[i][j] = true;
                }
            }
        }

        return board;
    }
}
