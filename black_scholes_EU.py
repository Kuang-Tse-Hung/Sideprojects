# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

from scipy import stats
import numpy as np



#C:goal:the proper price of a option 

#X:exercise price of the option

#S :current price of the financial asset
    
#T:maturity date of the option
    
#r:countinuously risk free rate


#X= int (input  ('enter the exercise price:'))
#S= int (input  ('enter the current price: '))
#T=int (input ('enter the maturity date: '))
#V= float (input ('enter the valatility: '))
#r= float (input('enter the intrest rate: '))

def count_d1(S,X,T,r,V):
    d1 =(np.log(S / X) + (r + 0.5 * V ** 2) * T) / (V * np.sqrt(T))
    return d1

     
def count_d2(S,X,T,r,V):
    d2 = (np. log ( S  / X ) + ( r - 0.5 * V ** 2)*T)/(V*np.sqrt(T))
   
    return d2
    
counted_d1 = count_d1(50,100,1,0.05,0.25)
counted_d2 = count_d2(50,100,1,0.05,0.25)
    
def count_call(d1,d2,S,X,T,r):
    return  (S * stats.norm.cdf(d1, 0.0, 1.0) - X * np.exp(-r * T) * stats.norm.cdf(d2, 0.0, 1.0))


print(counted_d1)
print(counted_d2)
print(count_call(counted_d1, counted_d2,50,100,1,0.05))
"""
import seaborn as sns
x = stats.norm.cdf(counted_d1,0.0,1.0)
sns.distplot(x)"""
  

def euro_vanilla_put(S, K, T, r, sigma):   
    d1 = (np.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    d2 = (np.log(S / K) + (r - 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    print(d1)
    print(d2)
    put = (K * np.exp(-r * T) * stats.norm.cdf(-d2, 0.0, 1.0) - S * stats.norm.cdf(-d1, 0.0, 1.0))
    
    return put

print(euro_vanilla_put(50,100,1,0.05,0.25))











    
    