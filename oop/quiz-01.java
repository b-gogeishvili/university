public class Main {

    public static void main(String[] args) {

    }

    static boolean isEven(int number) {
        return number % 2 == 0;
    }

    static void playWithArray(int size) {

        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();

    }

    static char getGrade(int score) {
        if (score < 51) {
            return 'F';
        } else if (score <= 60) {
            return 'E';
        } else if (score <= 70) {
            return 'D';
        } else if (score <= 80) {
            return 'C';
        } else if (score <= 90) {
            return 'B';
        } else if (score <= 100) {
            return 'A';
        } else {
            return '0';
        }
    }
}
