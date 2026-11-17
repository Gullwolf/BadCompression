import java.util.Arrays;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {
    public static String[] parseFile(String fileName) {
        Path filePath = Paths.get(fileName + ".txt");

        try {
            String content = new String(Files.readAllBytes(filePath));

            String[] words = content.split("\\s+");

            return words;
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    public static String[] removeVowels(String[] input) {
        String[] result = new String[input.length];

        for (int i = 0; i < result.length; i++) {
            result[i] = input[i].toString().toUpperCase();
            result[i] = result[i].replaceAll("[AEIOU]", "");
        }

        return result;
    }


    public static void main(String[] args) {
        String fileName = "";
//        String[] test = new String[]{"AAA", "abAbA", "aeiou", "Hello World"};
//        test = removeVowels(test);
//        System.out.println(Arrays.toString(test));

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the file name: ");
        fileName = scanner.nextLine();

        String[] test = new String[]{Arrays.toString(parseFile(fileName))};
        test = removeVowels(test);
        System.out.println(Arrays.toString(test));


    }
}