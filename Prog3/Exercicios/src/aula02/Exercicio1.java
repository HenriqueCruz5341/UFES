package aula02;

public class Exercicio1 {
    public static void main(String[] args) {
        double s1 = 0, s2 = 0, s3 = 0, num, dem;
        int exp;

        for (num = 1, dem = 1; num < 100; num += 2, dem++)
            s1 += num / dem;

        for (num = 2, dem = 50, exp = 1; dem > 0; exp++, dem--)
            s2 += Math.pow(num, exp) / dem;

        for (num = 1, dem = 1; num <= 10; num++, dem++) {
            if (num % 2 == 1)
                s3 += num / (dem * dem);
            else
                s3 -= num / (dem * dem);

        }

        System.out.println("S1 = " + s1);
        System.out.println("S2 = " + s2);
        System.out.println("S3 = " + s3);
    }
}