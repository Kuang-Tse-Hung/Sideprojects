#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 20 18:43:59 2021

@author: michaek05130505gmail.com
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.preprocessing import MinMaxScaler

data = pd.read_csv('MA.csv',date_parser = True)

# "data_training" stroes the data before 2020-01-22
data_training = data[data['Date'] < '2020-01-22'].copy() #a1 = a.copy() -> deep copy,  a2 = a -> shallow copy.

# "data_test" stores the data after 2020-01-22
data_test = data[data['Date'] >= '2020-01-22'].copy()

training_data = data_training.drop(['Date','Adj Close'], axis = 1) #when we want to delete specific column, we need to asign axis to 1. (default 0)

scaler = MinMaxScaler() #data standardization range (0,1)
training_data = scaler.fit_transform(training_data) 
#actually we need to "fit" data before "transform", fit_transform is just a function doing both above at same time.
#"fit" : Method calculates the parameters μ and σ and saves them as internal objects.
#"transform": Method using these calculated parameters apply the transformation to a particular dataset.

X_train = []
Y_train = []
for i in range(3,training_data.shape[0]):
    X_train.append(training_data[i-3  : i-1]) #"X_train": 945 sets of data, every of which contain 60 rows and 5 columns.
    Y_train.append(training_data[i, 0])#"y_train": 945 rows of data?  Y_train[0] = the stock price of the 60th day and so on.
    
X_train, Y_train = np.array(X_train), np.array(Y_train)

from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense, LSTM, Dropout

regressior = Sequential() 

regressior.add(LSTM(units = 60, activation = 'relu', return_sequences = True, input_shape = (X_train.shape[1], 5)))
regressior.add(Dropout(0.2))

regressior.add(LSTM(units = 60, activation = 'relu', return_sequences = True))
regressior.add(Dropout(0.2))

regressior.add(LSTM(units = 80, activation = 'relu', return_sequences = True))
regressior.add(Dropout(0.2))

regressior.add(LSTM(units = 120, activation = 'relu')) #final layer doesn't need return sequence
regressior.add(Dropout(0.2))

regressior.add(Dense(units = 1))


regressior.summary() #An overview of the Sequential (regressior)
regressior.compile(optimizer = 'adam', loss = 'mean_squared_error')


regressior.fit(X_train, Y_train, epochs = 100, batch_size = 32)
#The cocept of ecpoch was like how many times we train the model,for example, feed the model 1000 data for 1 train.
#the concept of Y_train is like a lable to every set the dataset in X_train respectively.


past_60_days = data_training.tail(60)
df = past_60_days.append(data_test, ignore_index= True)
df = df.drop(['Date','Adj Close'], axis = 1)

inputs = scaler.transform(df)

X_test = []
Y_test = []

for i in range(3, inputs.shape[0]):
    X_test.append(inputs[i-3:i-1])
    Y_test.append(inputs[i,0])
    
X_test, Y_test = np.array(X_test), np.array(Y_test)
y_pred = regressior.predict(X_test)
scaler.scale_ #understanding the scaling level(down).
scale = 1 / 4.10610165e-03 ## transfer back to normal value.
y_pred = y_pred * scale
Y_test = Y_test * scale


plt.figure(figsize = (20,8))
plt.plot(Y_test, color = 'red', label = 'Real Mastercard Stock Price')
plt.plot(y_pred, color = 'blue', label = 'Predicted Mastercard Stock Price')
plt.title('Mastercard Stock Price Predection')
plt.xlabel('Date')
plt.ylabel('Mastercard Stock Price')
plt.legend()
plt.show()






