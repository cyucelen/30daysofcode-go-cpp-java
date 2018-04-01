import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;
  	
  	Difference(int []arr){
  		this.elements = arr;
  	}
  	
  	void computeDifference() {
  		int max = 0;
  		for(int i = 0; i < elements.length; i++) {
  			for(int j = 0; j < elements.length; j++) {
  				if(i != j) {
  					int absDifference = Math.abs(elements[i] - elements[j]);
  					if(absDifference > max)
  						max = absDifference;
  				}
  			}
  		}
  		maximumDifference = max;
  	}  	
}
