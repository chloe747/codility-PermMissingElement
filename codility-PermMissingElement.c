//Solution Written by Chloe Smith - chloesmith747@gmail.com, github.com/chloe747.
// Results available at: https://codility.com/demo/results/trainingGRS2KB-A9J/
// Test available at: https://codility.com/programmers/lessons/

// Algorithmn explanation
// Since we know that the range is [1...N+1], we can sort this array in O(n) time
// by checking to see if the value in element i equals i+1. If the value does not
// equal i+1, then find the correct element for the value, and swap what is currently
// in that position into A[i], and the previous value into its correct spot. Keep 
// repeating this process until you get the correct value in A[i]. Then repeat this process
// for the rest of the array elements.
// if the element in A[i] is the N+1 element, then just record that value of i and move
// the next element.

int solution(int A[], int N) {
    
    int swap = 0;
    int currentValue = 0; //can just use a[i] or w/e, but this is more readable
    int LastValuePosition = -1; //this is the position in the array of the N+1 value
    
    //Sort the array using the above algorithmn, should be O(n) time
    for(int i = 0; i < N; i++)
    {
        // While the current array value is not sorted
        while(A[i] != (i+1))
        {
              currentValue = A[i];
              //check to see if the current value is the last value
              if(currentValue == N+1)
              {
                  LastValuePosition = i;
                  break; //continue onto the next array value
              }   
              //get the value that is in currentValue's correctly sorted spot
              swap = A[currentValue - 1];
              //place currentValue into its correct spot
              A[currentValue - 1] = currentValue;
              //place the value in swap into A[i], then use the while loop to check if it is sorted.
              A[i] = swap;
        }
    }
    //if LastValuePosition is set to -1, that means that we never found the N+1 value, so that is the missing value
    if(LastValuePosition == -1)
    {
        return N+1;
    }
    //otherwise, the value that is missing will be the position of N+1 plus the 0-array offset
    else
    {
        return LastValuePosition+1;
    }
}