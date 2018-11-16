import java.util.Arrays;

class p032 {

  public static void main(String[] args) {
     long startTime = System.nanoTime();
    System.out.println(new p032().run());
     long endTime = System.nanoTime();
    long t = (endTime - startTime)/1000000;
    System.out.println("Total execution time: " + t + " ms" );

  }

  public String run() {
    int sum = 0;

    for(int i = 1; i < 10000; i++) {
      if (panProd(i))
        sum += i;
  }

  return Integer.toString(sum);
}
 
 private static boolean panProd(int n) {

  for(int i = 1; i <= n; i++) {
   // System.out.println("" + "" + n + i + n/i);
   if((n % i == 0) && (isPan("" + n + i + n/i)))
    return true;
  }
  return false;
 }

 private static boolean isPan(String s) {
  if (s.length() != 9)
   return false;

  char[] temp = s.toCharArray();
  Arrays.sort(temp);
  return new String(temp).equals("123456789");
 }
}
