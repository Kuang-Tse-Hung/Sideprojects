#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec 11 10:39:02 2020

@author: michaek05130505gmail.com
"""

import numpy as np
import time
#from numba import autojit
#@autojit
def binomial_tree_call_put(N, T, S0, sigma, r, K, call = True, array_out = False):
    #initialize
    dt = T / N;
    u = np.exp(sigma * np.sqrt(dt))
    d = 1 / u
    p = (np.exp(r * dt) - d )/ (u - d)
    
    #price tree
    price_tree = np.zeros([N+1,N+1])
    
    for i in range(N+1):
        for j in range(i+1):
            price_tree[j,i] = S0 * (d ** j) * (u ** (i - j))
   
    #option value
    option = np.zeros([N+1,N+1])
    if call:
        option[:, N] = np.maximum(np.zeros(N+1),price_tree[:, N] - K)
    else:
        option[:, N] = np.maximum(np.zeros(N+1),K - price_tree[:, N])
    #calculate option price at t = 0
    for i in np.arange(N-1, -1, -1):
        for j in np.arange(0, i+1):
            option[j,i] = np.exp(-r * dt) * (p * option[j, i+1]+(1-p)*option[j+1,i+1])
            
    #Return 
    if array_out:
        return [option[0, 0], price_tree, option]
    else: 
        return option[0, 0]



            
start_time = time.time()
for i in range(10):
    print(binomial_tree_call_put(50, 1, 100, 0.1, 0.05, 100,True, False))
end_time = time.time()
print(end_time - start_time)


print(np.arange(0,5))
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            