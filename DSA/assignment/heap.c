#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int heap[500000];
void main()
{
    long long int no, i, j, c, root, temp,k;


   
          clock_t t;
   
             double time;
                for(i=0;i<=500000;i++)
                   heap[i]=rand();
                      for(k=25000;k<=500000;k=k+25000)
                         {  t=clock();
                             for (i = 1; i < k; i++)
                                 {
                                 	c = i;
                                 		do
                                 			{
                                 				    root = (c - 1) / 2;
                                 				    	    if (heap[root] < heap[c])   /* to create MAX heap array */
                                				    	    	    {
                                 				    	    	    		temp = heap[root];
                                 				    	    	    				heap[root] = heap[c];
                                 				    	    	    						heap[c] = temp;
                                 				    	    	    							    }
                                 				    	    	    							    	    c = root;
                                 				    	    	    							    	    	} while (c != 0);
                                 				    	    	    							    	    	    }
   
                                 				    	    	    							    	    	        for (j = no - 1; j >= 0; j--)
                                 				    	    	    							    	    	            {
                                 				    	    	    							    	    	            	temp = heap[0];
                                 				    	    	    							    	    	            		heap[0] = heap[j];    /* swap max element with rightmost leaf element */
                                 				    	    	    							    	    	            			heap[j] = temp;
                                 				    	    	    							    	    	            				root = 0;
                                 				    	    	    							    	    	            					do
                                 				    	    	    							    	    	            						{
                                 				    	    	    							    	    	            							    c = 2 * root + 1;    /* left node of root element */
                                 				    	    	    							    	    	            							    	    if ((heap[c] < heap[c + 1]) && c < j-1)
                                 				    	    	    							    	    	            							    	    		c++;
                                 				    	    	    							    	    	            							    	    			    if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
                                 				    	    	    							    	    	            							    	    			    	    {
                                 				    	    	    							    	    	            							    	    			    	    		temp = heap[root];
                                 				    	    	    							    	    	            							    	    			    	    				heap[root] = heap[c];
                                				    	    	    							    	    	            							    	    			    	    						heap[c] = temp;
                                 				    	    	    							    	    	            							    	    			    	    							    }
                                 				    	    	    							    	    	            							    	    			    	    							    	    root = c;
                                 				    	    	    							    	    	            							    	    			    	    							    	    	} while (c < j);
                                 				    	    	    							    	    	            							    	    			    	    							    	    	    }
                                 				    	    	    							    	    	            							    	    			    	    							    	    	        t=clock()-t;
                                 				    	    	    							    	    	            							    	    			    	    							    	    	           time=(double)t/CLOCKS_PER_SEC;
                                 				    	    	    							    	    	            							    	    			    	    							    	    	              printf("%d\t:%lf\n",k,time);
                                 				    	    	    							    	    	            							    	    			    	    							    	    	                 }
   
   
                                 				    	    	    							    	    	            							    	    			    	    							    	    	                 }
