

public class CountArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {1,2,1,0,9,1,1,1,4,4}; // n = 10
		
		repetitions(array,array.length);
	}
	
	private static void repetitions(int[] A, int n)
	{
		for(int i=0; i < n; ++i)
		{
			A[ A[i]%n ] += n;	// construct <key,value>
		}
		
		System.out.println("<Elem,Freq>:");
		for(int i=0; i < n; ++i)
		{
			System.out.printf("<%d, %d> \t",i, A[i]/n);
		}
		System.out.println();
	}
}

