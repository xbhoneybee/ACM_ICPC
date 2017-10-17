java.math.BigInteger
java.math.BigDecimal

## Java 语法
```
1. 输入：

格式为：Scanner cin = new Scanner (new BufferedInputStream(System.in));

例程：

import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args) 

    {

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        int a; double b; BigInteger c; String st;

        a = cin.nextInt(); b = cin.nextDouble(); c = cin.nextBigInteger(); d = cin.nextLine(); // 每种类型都有相应的输入函数.

    }

}

 

2. 输出

函数：System.out.print(); System.out.println(); System.out.printf();

System.out.print(); // cout << …;

System.out.println(); // cout << … << endl;

System.out.printf(); // 与C中的printf用法类似.

例程：

import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args) 

    {

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        int a; double b;

        a = 12345; b = 1.234567;

        System.out.println(a + " " + b);

        System.out.printf("%d %10.5f\n", a, b); // 输入b为字宽为10，右对齐，保留小数点后5位，四舍五入.

    }

}

规格化的输出：

函数：

// 这里0指一位数字，#指除0以外的数字(如果是0，则不显示),四舍五入.

    DecimalFormat fd = new DecimalFormat("#.00#");

    DecimalFormat gd = new DecimalFormat("0.000");

    System.out.println("x =" + fd.format(x));

    System.out.println("x =" + gd.format(x));

 

3. 字符串处理

java中字符串String是不可以修改的，要修改只能转换为字符数组.

例程：

import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args) 

    {

        int i;

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        String st = "abcdefg";

        System.out.println(st.charAt(0)); // st.charAt(i)就相当于st[i].

        char [] ch;

        ch = st.toCharArray(); // 字符串转换为字符数组.

        for (i = 0; i < ch.length; i++) ch[i] += 1;

        System.out.println(ch); // 输入为“bcdefgh”.

if (st.startsWith("a")) // 如果字符串以'0'开头.

        {

            st = st.substring(1); // 则从第1位开始copy(开头为第0位).

        }

    }

}

 

4. 高精度

BigInteger和BigDecimal可以说是acmer选择java的首要原因。

函数：add, subtract, divide, mod, compareTo等，其中加减乘除模都要求是BigInteger(BigDecimal)和BigInteger(BigDecimal)之间的运算，所以需要把int(double)类型转换为BigInteger(BigDecimal)，用函数BigInteger.valueOf().

例程：

import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args) 

    {

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        int a = 123, b = 456, c = 7890;

        BigInteger x, y, z, ans;

        x = BigInteger.valueOf(a); y = BigInteger.valueOf(b); z = BigInteger.valueOf(c);

        ans = x.add(y); System.out.println(ans);
        c=b.subtract(a);
        ans = z.divide(y); System.out.println(ans);

        ans = x.mod(z); System.out.println(ans);

        if (ans.compareTo(x) == 0) System.out.println("1");
    
        public int compareTo(BigDecimal val)
        //结果是:-1 小于,0 等于,1 大于
    }

}

 

5. 进制转换

java很强大的一个功能。

函数：

String st = Integer.toString(num, base); // 把num当做10进制的数转成base进制的st(base <= 35).

int num = Integer.parseInt(st, base); // 把st当做base进制，转成10进制的int(parseInt有两个参数,第一个为要转的字符串,第二个为说明是什么进制).   

BigInter m = new BigInteger(st, base); // st是字符串，base是st的进制.

//Added by abilitytao

1.如果要将一个大数以2进制形式读入 可以使用cin.nextBigInteger(2); 

当然也可以使用其他进制方式读入；

2.如果要将一个大数转换成其他进制形式的字符串 使用cin.toString(2);//将它转换成2进制表示的字符串

例程：POJ 2305

 

import java.io.*;

import java.util.*;

import java.math.*;

public class Main

{

    public static void main(String[] args)

    {

        int b;

        BigInteger p,m,ans;

        String str ;

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        while(cin.hasNext())

        {

            b=cin.nextInt();

            if(b==0)

                break;

            p=cin.nextBigInteger(b);

            m=cin.nextBigInteger(b);

            ans=p.mod(m);

            str=ans.toString(b);

            System.out.println(str);

        }

    }

}

//End by abilitytao

 

6. 排序

函数：Arrays.sort();至于怎么排序结构体。需要再写个类

例程：

import java.io.*;

import java.math.*;

import java.util.*;

import java.text.*;

public class Main

{

    public static void main(String[] args) 

    {

        Scanner cin = new Scanner (new BufferedInputStream(System.in));

        int n = cin.nextInt();

        int a[] = new int [n];

        for (int i = 0; i < n; i++) a[i] = cin.nextInt();

        Arrays.sort(a);

        for (int i = 0; i < n; i++) System.out.print(a[i] + " ");

    }

}
```
