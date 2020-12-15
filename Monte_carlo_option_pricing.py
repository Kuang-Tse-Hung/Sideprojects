#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#Monte carlo pricing model
#Reference: Hilpisch, Y. (2014). Python for Finance: Analyze Big Financial Data
"""
Created on Thu Dec 10 12:43:51 2020

@author: michaek05130505gmail.com
"""
import math
from math import exp, sqrt, log
from random import gauss, seed
import numpy as np
from numpy import *
from time import time


np.random.seed(20000)
t0 = time()
#parameters
S0 = 100.; K = 105.; T = 1.0; r = 0.05; sigma = 0.2
M = 50; dt = T / M; I = 25000
S = S0 * exp(cumsum((r - 0.5 * sigma ** 2) * dt
                    +sigma * math.sqrt(dt)
                           * random.standard_normal((M + 1, I)), axis = 0))
S[0] = S0

C0 = math.exp(-r * T) * sum(maximum(S[-1] - K, 0)) / I

tnp2 = time() - t0
print ('European Option Value is: ,',C0)
print ('Duration in Seconds is ' ,tnp2)

