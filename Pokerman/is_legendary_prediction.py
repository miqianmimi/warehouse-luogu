#!/usr/bin/env python

import matplotlib.pyplot as plt
import pandas as pd
import numpy

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
print(c)


Xtrain, Xtest, ytrain, ytest = tt(c, label, test_size=0.3,random_state=42)

print(Xtrain.size)
print(Xtest.size)


#=====================================
# 输入：
#        空
# 输出:
#        dataMat: 测试数据集
#        labelMat: 测试分类标签集
#=====================================

#=====================================
# 输入：
#         inX: 目标转换向量
# 输出:
#       1.0/(1+numpy.exp(-inX)): 转换结果
#=====================================
def sigmoid(inX):
    return 1.0/(1+numpy.exp(-inX))

#=====================================
# 输入：
#        dataMatIn: 数据集
#        classLabels: 分类标签集
# 输出:
#        weights: 最佳拟合参数向量
#=====================================
def gradAscent(dataMatIn, classLabels):
    # 基于梯度上升法的logistic回归分类器
    # 将数据集，分类标签集存入矩阵类型。
    dataMatrix = numpy.mat(dataMatIn)
    labelMat = numpy.mat(classLabels).transpose()
    # 上升步长度
    alpha = 0.001
    # 迭代次数
    maxCycles = 20
    # 初始化回归参数向量
    m,n = numpy.shape(dataMatrix)
    weights = numpy.ones((n,1))
    # 对回归系数进行maxCycles次梯度上升
    for k in range(maxCycles):
        h = sigmoid(dataMatrix*weights)
        error = (labelMat - h)
        weights = weights + alpha * dataMatrix.transpose()* error
    return (weights)



# ======================================
#    输入:
#            weights: 回归系数向量
#    输出:
#            图形化的决策边界演示
# ======================================
def plotBestFit(weights):
    '决策边界演示'

    # 获取数据集 分类标签集
    dataMat, labelMat = Xtest,ytest
    dataArr = numpy.array(dataMat)

    # 两种分类下的两种特征列表
    xcord1 = []
    ycord1 = []
    xcord2 = []
    ycord2 = []


    for i,j in enumerate(labelMat):
        if j == 0:
            xcord1.append(i)
            ycord1.append(0)
        else:
            xcord2.append(i)
            ycord2.append(1)


    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(xcord1, ycord1, s=30, c='red', marker='s')
    ax.scatter(xcord2, ycord2, s=30, c='green')
    # 绘制决策边界

    y = sigmoid(numpy.dot(dataArr, weights))

    ax.plot(range(y.size), y)

    plt.xlabel('X1')
    plt.ylabel('X2')
    plt.show()


def classifyVector(inx, weight_vector):
    """
    此函数以回归系数和特征向量作为输入来计算对应的Sigmoid值。如果Sigmoid值大于0.5，则函数返回1，否则返回0
    """
    prob = sigmoid(numpy.sum(inx * weight_vector))
    if prob > 0.5:
        return 1.0
    else:
        return 0.0


def calculata_errorRate(testDateArr, testLabelArr, weight_vector):
    """
    这个函数根据测试集的样本，计算分类错误率
    """
    prob_Arr = sigmoid(numpy.dot(testDateArr, weight_vector))
    label_result = numpy.zeros((prob_Arr.shape[0], 1))
    label_result[numpy.nonzero(prob_Arr > 0.5)[0]] = 1.0
    print(label_result)
    print(testLabelArr)

    total_error = 0.0
    for i in range(len(label_result)):
        if label_result[i] != testLabelArr[i]:
            total_error += 1
    errorRate = total_error / len(label_result)
    return errorRate


def draw_testDate_scatterGraph(testDateArr, testLabelArr, weight_vector):
    """
    此函数首先将测试数据集按照类别划分为正类和负类两个数据集，然后以散点图的形式将它们展现出来。
    输入： testDateArr 测试数据集（175*2的数组形式）
           testLabelArr 测试数据集对应的类别标签（1*175的数组形式）
    输出： 散点图
    """
    positive_index = numpy.nonzero(testLabelArr == 1)
    testDateArr_positive = testDateArr[positive_index]
    negative_index = numpy.nonzero(testLabelArr == 0)
    testDateArr_negative = testDateArr[negative_index]
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.scatter(testDateArr_positive[:, 1], testDateArr_positive[:, 2], marker='x', c='red')
    ax.scatter(testDateArr_negative[:, 1], testDateArr_negative[:, 2], marker='o', c='black')
    ax.plot(numpy.arange(0, 10), (-numpy.arange(0, 10) * weight_vector[1] - weight_vector[0]) / weight_vector[2])
    plt.xlabel('Clump Thickness', fontsize=10)
    plt.ylabel('Cell Size', fontsize=10)
    plt.show()

def test():
    '测试'
    dataArr, labelMat = Xtrain, ytrain
    weights = gradAscent(dataArr, labelMat)
    error = calculata_errorRate(Xtest, ytest, weights.getA())
    print(error)
    plotBestFit(weights.getA())


if __name__ == '__main__':
    test()