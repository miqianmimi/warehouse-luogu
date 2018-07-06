from sklearn.ensemble import GradientBoostingRegressor
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split as tt
a = pd.read_csv("pokerman.csv")
label_1 = a['isLegendary']
label = []
for i in label_1:
    if i == True:
        label.append(1)
    else:
        label.append(0)
print(label)
c = pd.DataFrame()
c['Catch_Rate']=a['Catch_Rate']
c['Total']=a['Total']
c['Attack']=a['Attack']
c['HP']=a['HP']
c['Defense']=a['Defense']
print(c)


Xtrain, Xtest, ytrain, ytest = tt(c, label, test_size=0.3,random_state=42)

print(Xtrain.size)
print(Xtest.size)
gbdt=GradientBoostingRegressor(
  loss='ls'
, learning_rate=0.1
, n_estimators=100
, subsample=1
, min_samples_split=2
, min_samples_leaf=1
, max_depth=3
, init=None
, random_state=None
, max_features=None
, alpha=0.9
, verbose=0
, max_leaf_nodes=None
, warm_start=False
)
train_feat=np.array(Xtrain)
train_id=np.array(ytrain)
test_feat=np.array(Xtest)
test_id=np.array(ytest)
print (train_feat.shape,train_id.shape,test_feat.shape,test_id.shape)
gbdt.fit(train_feat,train_id)
pred=gbdt.predict(test_feat)
total_err=0


label_result = np.zeros((pred.shape[0], 1))
label_result[np.nonzero(pred > 0.5)[0]] = 1.0
print(label_result)
pred = label_result

for i in range(pred.shape[0]):
    print (pred[i],test_id[i])
    err =(pred[i]-test_id[i])
    if err!=0:
        print ("haha")
        print(err)
    total_err+=abs(err)
print(total_err/Xtest.size)