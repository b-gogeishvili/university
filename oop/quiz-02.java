public class Main {
    public static void main(String[] args) {
    }


    static void displayAccessModifiers() {
        System.out.println("Private: Only accessible inside the class");
        System.out.println("Public: Accessibe from anywhere");
        System.out.println("Default: Only accessible inside the package");
        System.out.println("Protected: ");
    }

    static double getPerimeterOfCircle(double radius) {
        final double PI = 3.14;

        return 2 * PI * radius;
    }

    static void displayGoodFunctionNames() {
        System.out.println("Good Function Names Are: ");
        System.out.println("goodFunctionName");
        System.out.println("betterName");
        System.out.println("foo");
    }
    static void displayBadFunctionNames() {
        System.out.println("Bad Function Names Are: ");
        System.out.println("BadFunctionName");
        System.out.println("bad_name");
        System.out.println("BADFUNCTIONNAME");
    }

    static void displayNonValidFunctionNames() {
        System.out.println("Non-Valid Function Names Are: ");
        System.out.println("Function Name");
        System.out.println("-nonValidName");
        System.out.println("123Name");
    }


    static int[] getRunningSum(int[] nums) {
        int[] modifiedArray = new int[nums.length];

        for(int i = 0; i < nums.length; i++) {
            if (i == 0) {
                modifiedArray[i] = nums[i];
            }

            modifiedArray[i] = nums[i-1] + nums[i];
        }

        return modifiedArray;
    }

}
