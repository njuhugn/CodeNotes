
public class FindSingle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] array1 = {4,1,1,4,9};
		System.out.printf("Single in duplicateOrEven = %d\n",findSingleInDuplicateOrEven(array1));
		
		int[] array2 = {4,1,1,4,9,1,1,4,4};
		System.out.printf("Single in duplicateOrEven = %d\n",findSingleInDuplicateOrEven(array2));
		
		
		int[] array3 = {4,1,1,4,9,1,4,2,2,2,1000,1000,1000};
		System.out.printf("Single in triplicate = %d\n",findSingleInTriplicate(array3));
		
		int[] array4 = {4,4,4,4,4,4,9,1,1,1,1,1,1,2,2,2,2,2,2};
		System.out.printf("Single in triplicate = %d\n",findSingleInTriplicate(array4));
	}
	
	private static int findSingleInDuplicateOrEven(int[] A){
		int res = 0;
		for( int e: A)
		{
			res ^= e;
		}
		return res;
	}
	
	private static int  findSingleInTriplicate(int[] array) {
		// TODO Auto-generated method stub
		int res = 0;
		
		//Allocate O(1) memory and init to zero
		int[] bCount = new int[32]; //sizeof(int) * 8
		for(int b=0; b < bCount.length; ++b)
			bCount[b] = 0;
		
		//Add bit-wise. O(32n) time
		for(int e : array)
			for(int b=0; b < bCount.length; ++b)
				bCount[b] += (e >> b) & 1;
		
		//Cancell elements occur exactly 3 times Or integral multiples of 3
		for(int b=0; b < bCount.length; ++b)
			bCount[b] %= 3;
		
		//Return the Single element: res = \sum_{b=0}^32 bitCount[b] * 2^i
		for(int b=0; b < bCount.length; ++b)
			res += (bCount[b] << b);
		
		return res;
	}
	
}
