/*
 * ================================================================
 * =
 * =
 * =   文件名称：HelloWorld.java
 * =   创 建 者：Ang Wang  
 * =   创建日期：2021年01月02日
 * =   描    述：
 * =
 * ===============================================================
*/

//public 表示公开的
//class表示类
//HelloWorld表示类名

public class HelloWorld		//以类为单位，对比c语言的源文件
{
	//类体中不能直接写java语句，除声明变量

	public static void main(String[] args)   //主方法，对比c语言中主函数
	{
		//方法体，对比c语言中函数体
		System.out.println("Hello World!");
	}
}

class Test1
{
	//成员变量
	static int k=1000;
	static int f;

	public static void main(String[] args)   //主方法，对比c语言中主函数
	{
		//局部变量
		int i=0;

		//方法体，对比c语言中函数体
		System.out.println(k);
		System.out.println(f);
		System.out.println(i);
	}

}
